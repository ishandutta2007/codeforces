#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007

//#define TESTING

typedef long long ll;
typedef pair<int, int> pii;

ll n, m;
#ifdef TESTING
int stck[10], stckn = 0;

int cur_perm[10];

string sols[10000];
int nsols = 0;
int best_sol = -1;

void find_perms(int index)
{
    if (index == n) {
        int sum = 0;
        for (int l = 0; l < n; l++) {
            int cur_min = cur_perm[l];
            for (int r = l; r < n; r++) {
                cur_min = min(cur_min, cur_perm[r]);
                sum += cur_min;
            }
//            cout << cur_perm[l] << ", ";
        }
//        cout << ": " << sum << endl;

        if (sum > best_sol) {
            best_sol = sum;
            nsols = 0;
        }
        if (sum == best_sol) {
            stringstream ss;
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    ss << " ";
                }
                ss << cur_perm[i];
            }
            sols[nsols++] = ss.str();
        }

    } else {
        for (int i = 0; i < stckn; i++) {
            int cur = stck[i];
            stck[i] = stck[--stckn];

            cur_perm[index] = cur;
            find_perms(index + 1);

            stck[stckn++] = stck[i];
            stck[i] = cur;
        }
    }
}
#endif

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif // LOCAL

    cin >> n >> m;

#ifdef TESTING
    for (ll i = 1; i <= n; i++) {
        stck[stckn++] = i;
    }

    find_perms(0);

    sort(sols, sols + nsols);

    for (ll fcurm = 0; 2 * fcurm < (1 << n); fcurm++) {
        ll curm = fcurm;
#else
    ll curm = m - 1;
#endif
        ll bsol[100];
        ll pl = 0, pr = n;
        bool flag = true;
        for (ll i = n - 1; i >= 0; i--) {
//            cout << (2 * curm) << " vs " << (1 << i) << ", " << flag << endl;
            if (2 * curm >= (1LL << i)) {
//                if ((2 * curm == 1 << i) || flag) {
                if (flag) {
                    bsol[--pr] = n - i;
                } else {
                    bsol[pl++] = n - i;
                }
                curm = (1LL << i) - curm - 1;
                flag = !flag;
            } else {
                if (flag) {
                    bsol[pl++] = n - i;
                } else {
                    bsol[--pr] = n - i;
                }
            }
        }
#ifdef TESTING
        stringstream ss;
        for (int i = 0; i < n; i++) {
            if (i > 0) ss <<" ";
            ss << bsol[i];
        }
        if (ss.str() != sols[fcurm]) {
            cout << ss.str() << " vs " << sols[fcurm] << endl;
        }
    }
#else
    for (ll i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << bsol[i];
    }
    cout << endl;
#endif
    return 0;
}