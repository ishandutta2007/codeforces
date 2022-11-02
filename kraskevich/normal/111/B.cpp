#include <iostream>
using namespace std;

typedef long long ll;
const int maxN = 100 * 1000 + 1;
int last[maxN];
bool p[maxN];
int sz, val[maxN], ppow[maxN];
int res;

void init() {
     for(int i = 0; i < maxN; ++i) {
             last[i] = -1;
             p[i] = true;
     }
     p[0] = p[1] = false;
     for(int i = 2; (ll)i * i < maxN; ++i)
             if(p[i])
                     for(ll j = (ll)i * i; j < maxN; j += i)
                             p[j] = false;
}

void go(int cur, int v, int l, int nn) {
     if(cur == sz) {
            if(last[v] < l || l == nn)
                         ++res;
            last[v] = nn;
            return;
     }
     int t = 1;
     for(int i = 0; i <= ppow[cur]; ++i) {
             go(cur + 1, v * t, l, nn);
             t *= val[cur];
     }
}

void add(int n, int l, int nn) {
     sz = 0;
     res = 0;
     int cur = n;
     for(int i = 2; (ll) i * i <= n && cur > 1; ++i) 
             if(p[i] && n % i == 0) {
                     val[sz] = i, ppow[sz] = 0;
                     while(cur % i == 0) {
                               cur /= i;
                               ++ppow[sz];
                     }
                     ++sz;
             }
     if(p[cur]) {
                val[sz] = cur;
                ppow[sz] = 1;
                ++sz;
     }
     go(0, 1, l, nn);
}

int main() {
    init();
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            add(x, i - y, i);
            cout << res << endl;
    }
    cin >> n;
    return 0;
}