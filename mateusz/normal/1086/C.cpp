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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 1000005;

int k, t, n;
char s[N], a[N], b[N];
bool used[256];
int per[256];

bool tryForA(int from) {
    int copyPer[k + 5];
    bool copyUsed[k + 5];
    for (int i = 1; i <= k; i++) {
        copyPer[i] = per[i];
        copyUsed[i] = used[i];
    }
    bool good = true;
    for (int i = from; i <= n; i++) {
        if (per[s[i]]) {
            if (per[s[i]] < a[i]) {
                good = false;
                break;
            }
            if (per[s[i]] > a[i]) {
                break;
            }
            continue;
        }
        
        bool found = false;
        for (int j = a[i] + 1; j <= k; j++) {
            if (!used[j]) {
                per[s[i]] = j;
                used[j] = true;
                found = true;
                break;
            }
        }
        if (found) break;
        if (used[a[i]]) {
            good = false;
            break;
        } else {
            used[a[i]] = true;
            per[s[i]] = a[i];
        }
    }
    if (!good) {
        for (int i = 1; i <= k; i++) {
            per[i] = copyPer[i];
            used[i] = copyUsed[i];
        }
        return false;
    } else {
        for (int i = 1; i <= k; i++) {
            if (per[i]) continue;
            for (int j = 1; j <= k; j++) {
                if (!used[j]) {
                    per[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
        printf("YES\n");
        for (int i = 1; i <= k; i++) {
            printf("%c", (char)(per[i] + 'a' - 1));
        }
        printf("\n");
        return true;
    }
}


bool tryForB(int from) {
    int copyPer[k + 5];
    bool copyUsed[k + 5];
    for (int i = 1; i <= k; i++) {
        copyPer[i] = per[i];
        copyUsed[i] = used[i];
    }
    bool good = true;
    for (int i = from; i <= n; i++) {
        if (per[s[i]]) {
            if (per[s[i]] > b[i]) {
                good = false;
                break;
            }
            if (per[s[i]] < b[i]) {
                break;
            }
            continue;
        }
        
        bool found = false;
        for (int j = b[i] - 1; j >= 1; j--) {
            if (!used[j]) {
                per[s[i]] = j;
                used[j] = true;
                found = true;
                break;
            }
        }
        if (found) break;
        if (used[b[i]]) {
            good = false;
            break;
        } else {
            used[b[i]] = true;
            per[s[i]] = b[i];
        }
    }
    if (!good) {
        for (int i = 1; i <= k; i++) {
            per[i] = copyPer[i];
            used[i] = copyUsed[i];
        }
        return false;
    } else {
        for (int i = 1; i <= k; i++) {
            if (per[i]) continue;
            for (int j = 1; j <= k; j++) {
                if (!used[j]) {
                    per[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
        printf("YES\n");
        for (int i = 1; i <= k; i++) {
            printf("%c", (char)(per[i] + 'a' - 1));
        }
        printf("\n");
        return true;
    }
}

void test() {
    scanf("%d", &k);
    scanf("%s", &s[1]);
    scanf("%s", &a[1]);
    scanf("%s", &b[1]);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        s[i] -= 'a' - 1;
        a[i] -= 'a' - 1;
        b[i] -= 'a' - 1;
    }
    for (int i = 1; i <= k; i++) {
        per[i] = 0;
        used[i] = false;
    }
    bool good = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            if (per[s[i]] && per[s[i]] != a[i]) {
                good = false;
                break;
            }
            if (!per[s[i]] && used[a[i]]) {
                good = false;
                break;
            }
            per[s[i]] = a[i];
            used[a[i]] = true;
        } else {
            if (per[s[i]] && (per[s[i]] < a[i] || per[s[i]] > b[i])) {
                good = false;
                break;
            }
            if (per[s[i]]) {
                if (per[s[i]] == a[i]) {
                    if (tryForA(i + 1)) {
                        return;
                    }
                    good = false;
                    break;
                }
                if (per[s[i]] == b[i]) {
                    if (tryForB(i + 1)) return;
                    good = false;
                    break;
                }
                break;
            }
            bool found = false;
            for (int c = a[i] + 1; c < b[i]; c++) {
                if (!used[c]) {
                    per[s[i]] = c;
                    used[c] = true;
                    found = true;
                    break;
                }
            }
            if (!found) {
                if (!used[a[i]]) {
                    used[a[i]] = true;
                    per[s[i]] = a[i];
                    if (tryForA(i + 1)) {
                        return;
                    }
                    used[a[i]] = false;
                    per[s[i]] = 0;
                }
                if (!used[b[i]]) {
                    used[b[i]] = true;
                    per[s[i]] = b[i];
                    if (tryForB(i + 1)) return;
                    used[b[i]] = false;
                    per[s[i]] = 0;
                }
                good = false;
                break;
            }
            break;
        }
    }
    
    if (!good) {
        printf("NO\n");
        return;
    }
    for (int i = 1; i <= k; i++) {
        if (!per[i]) {
            for (int j = 1; j <= k; j++) {
                if (!used[j]) {
                    per[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
    }
    printf("YES\n");
    for (int i = 1; i <= k; i++) {
        printf("%c", (char)(per[i] + 'a' - 1));
    }
    printf("\n");
}

int main() {
    
    scanf("%d", &t);
    
    while (t--) {
        test();
    }
    
    return 0;
}