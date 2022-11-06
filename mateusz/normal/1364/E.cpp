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
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
const int N = 100005;
int n, x;
int order[N];
vector<int> per;
int queriesNo;
int query(int a, int b) {
//     queriesNo++;
//     return per[a] | per[b];
    a++;
    b++;
    assert(a != b);
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    srand(time(NULL));
    
    cin >> n;
    
//     for (int i = 0; i < n; i++) {
//         per.push_back(i);
//     }
//     random_shuffle(per.begin(), per.end());
//     debug(per);
    
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    random_shuffle(order, order + n);
    
    int a = order[0];
    int b = order[1];
    int best = query(a, b);
    
    for (int i = 2; i < n; i++) {
        int c = order[i];
        int r = query(b, c);
        if (__builtin_popcount(r) < __builtin_popcount(best)) {
            a = b;
            b = c;
            best = r;
            continue;
        }
        if (__builtin_popcount(r) == __builtin_popcount(best)) {
            r = query(a, c);
            if (__builtin_popcount(r) < __builtin_popcount(best)) {
                b = c;
                best = r;
                continue;
            }
        }
    }
    
    int zero = -1;
    while (true) {
        int x = rand() % n;
        while (x == a || x == b) {
            x = rand() % n;
        }
        int rA = query(a, x);
        int rB = query(b, x);
        if (rA < rB) {
            zero = a;
            break;
        }
        if (rB < rA) {
            zero = b;
            break;
        }
    }
    
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (i == zero) {
            ans.push_back(0);
        } else {
            ans.push_back(query(i, zero));
        }
    }
    
    cout << "! ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
//     debug(queriesNo);
//     assert(queriesNo <= 4269);
//     
    return 0;
}