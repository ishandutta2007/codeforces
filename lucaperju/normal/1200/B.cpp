    // Matteo Verzotti - C++
    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    #include <cstring>
    #include <stack>
    #include <queue>
    #include <deque>
    #include <vector>
    #include <ctime>
    #include <map>
    #include <chrono>
    #include <cmath>
    #define INF 0x3f3f3f3f
    #define MAX(a,b) a>b ? a:b
    #define MIN(a,b) a<b ? a:b
     
    using namespace std;
     
    const int N = 2 * 1e5;
     
     
    long long v[500];
     
     
    int main() {
        long long t, n, m, k;
        cin >> t;
        while(t--) {
            cin >> n >> m >> k;
            long long s = m;
            bool ok = true;
            for(int i = 1; i <= n; i++)
                cin >> v[i];
            for(int i = 1; i < n; i++) {
                if(v[i] >= v[i+1])
                    s += v[i] - v[i+1] + min(k,v[i+1]);
                else if(v[i+1] - v[i] <= k){
                    s += v[i] - max(0LL,v[i+1]-k);
                }
                else if(v[i+1] - v[i] > k) {
                    if(v[i+1] - v[i] > k + s) {
                        ok = false;
                        i = n;
                    } else {
                        // v[i] + k >= v[i+1] - s
                        s -= v[i+1] - v[i] - k;
                    }
                }
            }
            if(ok == false) cout << "NO\n";
            else cout << "YES\n";
        }
        return 0;
    }