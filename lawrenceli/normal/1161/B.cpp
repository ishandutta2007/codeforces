#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return ll(a) * ll(b) / gcd(a, b);
}

void z_algo(int* s, int* z, int n) {
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r-l] == s[r]) r++;
            z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if (z[k] < r - i + 1) z[i] = z[k];
            else {
                l = i;
                while (r < n && s[r-l] == s[r]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

const int maxn = 100100;
const int maxm = 200100;

int n, m;
vector<int> nums[maxn];
int z[4 * maxn];
int v[4 * maxn]; int vsze;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        if (a > b) swap(a, b);
        if (b - a < n - (b - a)) {
            nums[b-a].push_back(a);
        } else if (b - a > n - (b - a)){
            nums[n-(b-a)].push_back(b);
        } else {
            // edge case
            nums[b-a].push_back(a);
            nums[b-a].push_back(b);
        }
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        sort(nums[i].begin(), nums[i].end());
        if (nums[i].empty()) continue;

        vsze = 0;
        int last = -1;
        for (int j : nums[i]) {
            if (last != -1) v[vsze++] = j - last;
            last = j;
        }
        v[vsze++] = n - (last - nums[i][0]);

        memcpy(v + vsze, v, vsze * sizeof(int));

        z_algo(v, z, 2 * vsze);
        int sum = v[0];
        bool found = false;
        for (int i = 1; i < vsze; i++) {
            if (z[i] >= vsze) {
                ans = lcm(ans, sum);
                found = true;
                break;
            }
            sum += v[i];
        }

        if (!found) {
            printf("No\n");
            return 0;
        }
    }

    if (ans < n) printf("Yes\n");
    else printf("No\n");
}