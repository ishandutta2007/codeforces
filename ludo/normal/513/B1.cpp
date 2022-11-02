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
#define MAX 100000
#define MAXSOLS 100000

typedef long long ll;
typedef pair<int, int> pii;

int n;
int stck[10], stckn = 0;

int cur_perm[10];

string sols[MAXSOLS];
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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        stck[stckn++] = i;
    }

    find_perms(0);

    sort(sols, sols + nsols);

    cout << sols[m - 1] << endl;
    return 0;
}