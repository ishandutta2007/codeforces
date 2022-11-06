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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

long long lastE, lastC;
long long e, c;
int n;
long long getVal[1000005];
long long val[1000005];
int cnt = 0;
long long es[105], cs[105];
int eSize, cSize;

void add(long long w) {
    cnt++;
    assert(cnt <= n);
    cout << "+ " << w << endl;
    lastE = e;
    lastC = c;
    cin >> e >> c;
}

int main() {
    
    cin >> n;
    
    for (int i = 1; i <= 200; i++) {
        getVal[i * (i - 1) / 2] = i;
    }
    
    cin >> e >> c;
    
    add(1);
    if (e - lastE > 0) {
        val[1] = getVal[e - lastE] + 1;
    }

    add(2);
    if (e - lastE > 0) {
        val[2] = getVal[e - lastE] + 1;
    }
    
    bool nextZero = (c - lastC) == 0;
    
    add(3);
    if (e - lastE > 0) {
        val[3] = getVal[e - lastE] + 1;
    } else if (nextZero) {
        val[3] = 1;
    } else {
        val[3] = 2;
    }
    int remDiff = c - lastC;
    
    
    add(1);
    if (e - lastE > 0) {
        val[1] = getVal[e - lastE] + 1;
    } else {
        val[1] = 2;
    }
    
    val[2] = (c - lastC) / val[3];
    
    lastC = c - remDiff + (val[1] - 1) * val[2] - val[1] * val[2];
//     cerr << lastC << " " << c << endl;
    nextZero = (c - lastC - (val[1] * val[2])) == 0;
//     cerr << nextZero << endl;
    for (int i = 4; i < n; i++) {
        add(i);
        if (e - lastE > 0) {
            val[i] = getVal[e - lastE] + 1;
        } else {
            val[i] = nextZero ? 1 : 2;
        }
        long long remainingCon = c - lastC - (i <= 2 ? 0 : val[i - 2] * val[i - 1]);
        nextZero = remainingCon == 0;
    }
    
    long long remainingCon = c - lastC - val[n - 3] * val[n - 2];
    val[n] = remainingCon / val[n - 2];
    val[1] -= 2;
    for (int i = 2; i < n; i++) {
        val[i]--; 
    }
    
    cout << "! ";
    for (int i = 1; i <= n; i++) {
//         assert(0 <= val[i]);
//         assert(val[i] <= n);
        cout << val[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}