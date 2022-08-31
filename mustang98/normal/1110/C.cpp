#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int dumb(int a) {
    int ans = -inf;
    for (int b = 1; b < a; ++b) {
        ans = max(ans, __gcd(a & b, a ^ b));
    }
    return ans;
}

vector<int> p2;
vector<int> os = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
map<int, int> mp;

int solve(int a) {
    if (mp.find(a) != mp.end()) {
        return mp[a];
    }
    for (int i = 0; i < p2.size(); ++i) {
        if (p2[i] > a) {
            return p2[i] - 1;
        }
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int cur = 1;
    for (int i = 0; i < 30; ++i) {
        p2.push_back(cur);
        cur *= 2;
    }
    for (int i = 0; i < os.size(); ++i) {
        int val = p2[i + 2] - 1;
        mp[val] = os[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        cout << solve(a) << endl;
    }

    return 0;
}