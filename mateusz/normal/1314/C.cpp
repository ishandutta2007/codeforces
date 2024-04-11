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

const int N = 2005, LOG = 10;

int n, m;
long long k;
char word[N];
int kmr[15][N];
long long dp[N][N], suf[N][N];
int pot[N];

vector<pair<int, int> > substrings;

void add(long long &w, long long u) {
    w += u;
    w = min(w, 15 * (long long)1e17);
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    int l1 = a.second - a.first + 1;
    int l2 = b.second - b.first + 1;
    int l = min(l1, l2);
    int plog = pot[l];
    int p = (1 << pot[l]);
    
    pair<int, int> idA = {kmr[plog][a.first], kmr[plog][a.first + l - p]};
    pair<int, int> idB = {kmr[plog][b.first], kmr[plog][b.first + l - p]};
    if (idA != idB) {
        return idA < idB;
    } else {
        return l1 < l2;
    }
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    int l1 = a.second - a.first + 1;
    int l2 = b.second - b.first + 1;
    int l = min(l1, l2);
    int plog = pot[l];
    int p = (1 << pot[l]);
    
    pair<int, int> idA = {kmr[plog][a.first], kmr[plog][a.first + l - p]};
    pair<int, int> idB = {kmr[plog][b.first], kmr[plog][b.first + l - p]};
    if (idA != idB) {
        return idA < idB;
    } else {
        return l1 <= l2;
    }
}


long long check(int w) {
    int from = substrings[w].first;
    int to = substrings[w].second;
    
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = suf[i][j] = 0;
        }
    }
    dp[n + 1][0] = 1;
    suf[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
        suf[i][0] = 1;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            
            int low = i;
            int high = n;
            int res = n + 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (cmp2({from, to}, {i, mid})) {
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            dp[i][j] = suf[res + 1][j - 1];

            add(suf[i][j], dp[i][j]);
            add(suf[i][j], suf[i + 1][j]);
        }
    }
    return dp[1][m];
}

int main() {
    
    scanf("%d %d %lld", &n, &m, &k);
    
    scanf("%s", &word[1]);
    
    for (int i = 1; i <= n; i++) {
        kmr[0][i] = word[i];
    }
    
    pot[1] = 0;
    for (int i = 2; i <= n; i++) {
        pot[i] = pot[i / 2] + 1;
    }
    
    for (int l = 1; l <= LOG; l++) {
        vector<pair<pair<int, int>, int> > pairs;
        for (int i = 1; i + (1 << (l - 1)) <= n; i++) {
            pairs.push_back({{kmr[l - 1][i], kmr[l - 1][i + (1 << (l - 1))]}, i});
        }
        sort(pairs.begin(), pairs.end());
        int id = 0;
        for (int i = 0; i < pairs.size(); i++) {
            if (i == 0 || pairs[i].first != pairs[i - 1].first) {
                ++id;
            }
            kmr[l][pairs[i].second] = id;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            substrings.push_back({i, j});
        }
    }
    
    sort(substrings.begin(), substrings.end(), cmp);
    reverse(substrings.begin(), substrings.end());
    
    int low = 0;
    int high = substrings.size() - 1;
    int res = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid) >= k) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    assert(res < substrings.size());
    
    int from = substrings[res].first;
    int to = substrings[res].second;
    for (int i = from; i <= to; i++) {
        printf("%c", word[i]);
    }
    printf("\n");
    
    return 0;
}