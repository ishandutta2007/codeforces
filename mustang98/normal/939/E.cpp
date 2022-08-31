#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 500111, inf = 1000111222;

vector<ll> v;
vector<ll> sum;

double check(int pr) {
    return v.back() - (1.0 * (sum[pr] + v.back()) / (pr + 2));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int Q;
    cin >> Q;
    while(Q--) {
        int t, a;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &a);
            v.PB(a);
            sum.PB(a);
            if (sum.size() > 1) {
                sum.back() += sum[sum.size() - 2];
            }
        } else {
            if (v.size() == 1) {
                printf("0\n");
                continue;
            }
            if (v.size() == 2) {
                printf("%.8f\n", check(0));
                continue;
            }

            int l = 0, r = v.size() - 2;
            while(l + 2 < r) {
                int mid1 = l + (r - l) / 3;
                int mid2 = l + ((r - l) / 3) * 2;
                if (check(mid1) < check(mid2)) {
                    l = mid1;
                } else {
                    r = mid2;
                }
            }
            double maxans = 0;
            for (int i = l; i <= r; ++i) {
                maxans = max(maxans, check(i));
            }
            printf("%.8f\n", maxans);
        }
    }


    return 0;
}