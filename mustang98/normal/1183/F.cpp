#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> v;

int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while(q--) {
        int n;
        scanf("%d", &n);
        v.clear();
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            v.PB(a);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        reverse(v.begin(), v.end());
        int best = v[0];
        for (int i = 0; i < v.size(); ++i) {
            if (i + 2 < v.size() && v[i] + v[i + 1] + v[i + 2] <= best) {
                break;
            }
            for (int j = i + 1; j < v.size(); ++j) {
                if (v[i] % v[j] == 0) continue;
                best = max(best, v[i] + v[j]);
                if (i + 1 < v.size() && v[i] + v[j] + v[j + 1] <= best) break;
                int rr = v[i] + v[j];
                for (int k = j + 1; k < v.size(); ++k) {
                    if (rr + v[k] <= best) break;
                    if (v[i] % v[k] == 0 || v[j] % v[k] == 0) continue;
                    best = max(best, v[i] + v[j] + v[k]);
                }
            }
        }
        printf("%d\n", best);
    }

    return 0;
}