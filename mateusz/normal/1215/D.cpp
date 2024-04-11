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
char number[N];

int main() {
    
    scanf("%d", &n);
    
    scanf("%s", &number[1]);
    
    int sum = 0;
    int cntLeft = 0, cntRight = 0;
    for (int i = 1; i <= n; i++) {
        if (number[i] == '?') {
            if (i <= n / 2) {
                cntLeft++;
            } else {
                cntRight++;
            }
            continue;
        }
        if (i <= n / 2) {
            sum += number[i] - '0';
        } else {
            sum -= number[i] - '0';
        }
    }
    
    if ((cntLeft + cntRight) % 2 == 1) {
        printf("Monocarp\n");
        return 0;
    }
    
    if (cntLeft + cntRight == 0) {
        printf(sum == 0 ? "Bicarp\n" : "Monocarp\n");
        return 0;
    }
    
    int oldCntLeft = cntLeft;
    int oldCntRight = cntRight;
    int oldSum = sum;
    
    int who = 0;
    int lastUsed = -1;
    while (cntLeft > 0 || cntRight > 0) {
        if (who == 0) {
            if (cntLeft > 0) {
                cntLeft--;
                sum += 9;
            } else {
                cntRight--;
            }
        } else {
            if (cntRight > 0) {
                cntRight--;
                lastUsed = -9;
                sum -= 9;
            } else {
                lastUsed = 0;
                cntLeft--;
            }
        }
        
        who = 1 - who;
    }
    
    int winner = 0;
    if (sum == 0) {
        winner = 1;
    }
    
    if ((sum > 0 && sum - lastUsed <= 0) || (sum < 0 && sum - lastUsed >= 0)) {
        winner = 1;
    }
    
    int winner2 = 0;
    
    sum = oldSum;
    cntLeft = oldCntLeft;
    cntRight = oldCntRight;
    
    who = 0;
    lastUsed = -1;
    while (cntLeft > 0 || cntRight > 0) {
        if (who == 0) {
            if (cntRight > 0) {
                cntRight--;
                sum -= 9;
            } else {
                cntLeft--;
            }
        } else {
            if (cntLeft > 0) {
                cntLeft--;
                lastUsed = 9;
                sum += 9;
            } else {
                lastUsed = 0;
                cntRight--;
            }
        }
        
        who = 1 - who;
    }
    if (sum == 0) {
        winner2 = 1;
    }
    
    if ((sum > 0 && sum - lastUsed <= 0) || (sum < 0 && sum - lastUsed >= 0)) {
        winner2 = 1;
    }
    
    if (!winner || !winner2) {
        printf("Monocarp\n");
    } else {
        printf("Bicarp\n");
    }
    
    return 0;
}