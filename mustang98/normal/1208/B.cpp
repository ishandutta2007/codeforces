#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2011, inf = 1000111222;

vector<int> v;
int n;
int m[max_n];

int get_small(int a) {
    return lower_bound(v.begin(), v.end(), a) - v.begin();
}

int cnt[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    set<int> s;
    for (int i =0 ; i <n ;++i) {
        int a;
        cin >> a;
        v.PB(a);
        m[i] = a;
        s.insert(a);
    }
    if (s.size() == n) {
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    for (int i = 0;i < n; ++i) {
        m[i] = get_small(m[i]);
    }
    int ans = inf;
    for (int st = 0; st < n; ++st) {
        int cn1 = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            cnt[m[i]]++;
            if (cnt[m[i]] == 2) {
                ++cn1;
            }
        }
        for (int to = st; to < n; ++to) {
            cnt[m[to]]--;
            if (cnt[m[to]] == 1) {
                --cn1;
            }
            if (cn1 == 0) {
                ans = min(ans, to - st + 1);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}