#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <utility>

#define MAX_H 50

using namespace std;

typedef long long ll;

ll n_parents[MAX_H];

ll pow2(int exp)
{
    ll ans = 1;
    while(--exp >= 0) {
        ans *= 2;
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    ll h, n;
    cin >> h >> n;

    ll end_node = (pow2(h) + n - 1);
    for (int i = h - 1; end_node > 1; i--) {
        n_parents[i] = end_node;
        end_node /= 2;
    }

    ll num_visited = 0;
    ll cur_node = 1;

    bool go_left = true;
    for (int i = 0; i < h; i++) {
        ll next_node = 2 * cur_node;
        if (!go_left) {
            next_node++;
        }
        if (binary_search(&n_parents[0], &n_parents[h], next_node)) {
            // we are investigating the right tree :)
            num_visited++;
            go_left = !go_left;
        } else {
            // we are investigating the wrong tree :(
            num_visited += pow2(h - i);
            if (go_left) {
                next_node++;
            } else {
                next_node--;
            }
        }
        cur_node = next_node;
    }
    cout << num_visited << endl;
    return 0;
}