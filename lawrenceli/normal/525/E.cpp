#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, a[30];
ll s, fact[30], ans;
map<ll, vector<int> > mp;

void dfs(int x, ll sum=0, int num=0) {
    if (sum > s || num > k) return;
    if (x == n/2) mp[sum].push_back(num);
    else {
        dfs(x+1, sum, num);
        dfs(x+1, sum+a[x], num);
        if (a[x] <= 18) dfs(x+1, sum+fact[a[x]], num+1);
    }
}

void dfs2(int x, ll sum=0, int num=0) {
    if (sum > s || num > k) return;
    if (x == n) {
        if (mp.count(s-sum))
            ans += upper_bound(mp[s-sum].begin(), mp[s-sum].end(), k-num) - mp[s-sum].begin();
    } else {
        dfs2(x+1, sum, num);
        dfs2(x+1, sum+a[x], num);
        if (a[x] <= 18) dfs2(x+1, sum+fact[a[x]], num+1);
    }
}

int main() {
    cin >> n >> k >> s;
    for (int i=0; i<n; i++) cin >> a[i];
    fact[0] = 1;
    for (int i=1; i<=18; i++) fact[i] = fact[i-1] * i;
    dfs(0);
    //pass by reference nooooo :(
    for (auto i = mp.begin(); i != mp.end(); i++)
        sort(i->second.begin(), i->second.end());
    dfs2(n/2);
    cout << ans;
}