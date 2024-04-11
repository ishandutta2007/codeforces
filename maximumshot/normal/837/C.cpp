#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, a, b;

    cin >> n >> a >> b;

    int r = 0;

    vec< pii > arr(n);

    for(int i = 0;i < n;i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            int ok = 0;
            for(int ti = 0;ti < 2;ti++) {
                for(int tj = 0;tj < 2;tj++) {
                    int x1, y1, x2, y2;
                    tie(x1, y1) = arr[i];
                    tie(x2, y2) = arr[j];
                    if(ti) swap(x1, y1);
                    if(tj) swap(x2, y2);
                    for(int tt = 0;tt < 2;tt++) {
                        if(tt) {
                            swap(x1, x2);
                            swap(y1, y2);
                        }
                        for(int qq = 0;qq < 2;qq++) {
                            int ha, hb;
                            ha = a;
                            hb = b;
                            if(qq) swap(ha, hb);
                            if(x1 <= ha && x2 <= ha && y1 + y2 <= hb) {
                                ok = 1;
                            }
                        }
                    }
                }
            }
            if(ok) {
                r = max(r, arr[i].first * arr[i].second + arr[j].first * arr[j].second);
            }
        }
    }

    cout << r << "\n";

    return 0;
}