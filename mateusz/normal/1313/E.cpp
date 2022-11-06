#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 1000005, BASE = (1 << 20);

string a, b, s;
int n, m;

long long tree[2][2 * BASE + 5];
int ile[2][2 * BASE + 5];
pair<long long, int> save[N];

void insert(int d, int pos, int w, int c) {
    pos += BASE;
    while (pos >= 1) {
        tree[d][pos] += w;
        ile[d][pos] += c;
        pos /= 2;
    }
}

pair<long long, int> query(int d, int posa, int posb) {
    if (posa > posb) {
        return {0, 0};
    }
    posa += BASE;
    posb += BASE;
    long long sum = 0;
    int cnt = 0;
    sum += tree[d][posa];
    cnt += ile[d][posa];
    if (posa != posb) {
        sum += tree[d][posb];
        cnt += ile[d][posb];
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            sum += tree[d][posa + 1];
            cnt += ile[d][posa + 1];
        }
        if (posb % 2 == 1) {
            sum += tree[d][posb - 1];
            cnt += ile[d][posb - 1];
        }
        posa /= 2;
        posb /= 2;
    }
    return {sum, cnt};
}

int PrefMatching(string& s, int n, int j, int k) {
  k = max(k, j);
  int i = k - j;
  while (k < n and s[i] == s[k]) {
    i++;
    k++;
  }
  return k - j;
}

// Liczy funkcj pref.
// s - sowo na pozycjach [0, n-1].
// n - dugo sowa.
// p - tablica pref, ktra zostanie wypeniona na pozycjach [0, n - 1].
void Pref(string s, int* p) {
  int n = s.size();
  int i = 0;
  p[0] = -1;
  for (int j = 1; j < n; j++) {
    const int l = j - i;
    if (l < p[i] and j + p[l] < i + p[i]) {
      p[j] = p[l];
    } else {
      p[j] = PrefMatching(s, n, j, i + p[i]);
      i = j;
    }
  }
  p[0] = n;
}

int prefA[N], prefB[N];

int main() {
    
    cin >> n >> m;
    cin >> a >> b >> s;
    char c = s.back();
    s.back() = '#';
    Pref(s + a, prefA);
    s.back() = c;
    
    reverse(s.begin(), s.end());
    reverse(b.begin(), b.end());
    c = s.back();
    s.back() = '#';
    Pref(s + b, prefB);
    
    for (int i = 0; i < n; i++) {
        prefB[i] = prefB[i + m];
    }
    reverse(prefB, prefB + n);
    
//     cerr << n << endl;
    for (int i = 0; i < n; i++) {
        prefA[i] = prefA[i + m];
    }
    
//     for (int i = 0; i < n; i++) {
//         cerr << prefA[i] << " ";
//     }
//     cerr << endl;
//     
//     for (int i = 0; i < n; i++) {
//         cerr << prefB[i] << " ";
//     }
//     cerr << endl;
    
    vector<pair<pair<int, int>, pair<int, int>>> events; //pozycja, typ(poczatek/koniec), drugi koneic, ktore_slowo
    for (int i = 0; i < n; i++) {
        if (prefA[i] == 0) continue;
        events.push_back({{i, 0}, {i + prefA[i] - 1, 0}});
        events.push_back({{i + prefA[i] - 1, 1}, {i, 0}});
//         cerr << "(" << i << ", " << i + prefA[i] - 1 << ")\n";
    }
    
    for (int i = 0; i < n; i++) {
        if (prefB[i] == 0) continue;
        events.push_back({{i, 1}, {i - prefB[i] + 1, 1}});
        events.push_back({{i - prefB[i] + 1, 0}, {i, 1}});
        events.push_back({{max(0, i - prefB[i] + 1 - (m - prefB[i] + 1) + 2), -1}, {(m - prefB[i] + 1) - 1, i}});
//         cerr << "(" << i - prefB[i] + 1 << ", " << i << ")\n";
    }
    
    sort(events.begin(), events.end());
    long long openBSum = 0;
    int openBCnt = 0;
    long long ans = 0;
    for (int i = 0; i < events.size(); i++) {
        int pos = events[i].first.first;
        int pos2 = events[i].second.first;
        int type = events[i].first.second;
        int str = events[i].second.second;
//         cerr << pos << " " << pos2 << " " << type << " " << str << endl;
        if (type == -1) {
            save[str] = query(0, pos2, n);
            continue;
        }
        if (str == 1) {
            if (type == 0) {
                int startPos = m - prefB[pos2] + 1;
//                 cerr << startPos << endl;
//                 openBSum += startPos - 2;
//                 openBCnt++;
                insert(1, startPos, startPos - 2, 1);
                auto p = query(0, startPos - 1, n);
                p.first -= save[pos2].first;
                p.second -= save[pos2].second;
//                 cerr << "dodaje " << p.first << " minus " << (long long)startPos * p.second << endl;
                ans += p.first - (long long)startPos * p.second;
            } else {
                int startPos = m - prefB[pos] + 1;
                insert(1, startPos, -(startPos - 2), -1);
//                 openBSum -= startPos - 2;
//                 openBCnt--;
            }
        } else {
            if (type == 0) {
//                 ans += (long long)openBCnt * prefA[pos] - openBSum;
                auto p = query(1, 0, prefA[pos] + 1);
                
//                 cerr << "dodaje " << (long long)p.second * prefA[pos] << " minus " << p.first << endl;
                ans += (long long)p.second * prefA[pos] - p.first;
                insert(0, prefA[pos], prefA[pos] + 2, 1);
            } else {
//                 insert(0, , -(prefA[pos2] + 2), -1);
            }
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}