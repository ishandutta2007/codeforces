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

const int N = 200005;

int n;
char s[N], ans1[N], ans2[N];

bool good(char *ans) {
    int balance = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ans1[n + 1] = '\0';
        ans2[n + 1] = '\0';
        scanf("%s", &s[1]);
        vector<int> equal, diff;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') equal.push_back(i);
            else diff.push_back(i);
        }
        if (equal.size() % 2 == 1 || diff.size() % 2 == 1) {
            printf("NO\n");
            continue;
        }
        int m = equal.size() / 2;
        for (int i = 0; i < m; i++) {
            int posLeft = equal[i];
            int posRight = equal[(int)equal.size() - 1 - i];
            ans1[posLeft] = ans2[posLeft] = '(';
            ans1[posRight] = ans2[posRight] = ')';
        }
        for (int i = 0; i < diff.size(); i++) {
            if (i % 2 == 0) {
                ans1[diff[i]] = '(';
                ans2[diff[i]] = ')';
            } else {
                ans1[diff[i]] = ')';
                ans2[diff[i]] = '(';
            }
        }
        if (!good(ans1) || !good(ans2)) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        printf("%s\n", ans1 + 1);
        printf("%s\n", ans2 + 1);
    }
    
    return 0;
}