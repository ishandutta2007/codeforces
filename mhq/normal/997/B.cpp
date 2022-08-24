#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector < pair < ll,  ll > > q[49];
ll get_un(vector < pair < ll, ll > > a) {
    unsigned n = a.size();
	vector <pair <ll,bool> > x (n*2);
	for (unsigned i=0; i<n; i++)
	{
		x[i*2] = make_pair (a[i].first, false);
		x[i*2+1] = make_pair (a[i].second, true);
	}

	sort (x.begin(), x.end());

	ll result = 0;
	ll c = 0;
	for (unsigned i=0; i<n*2; i++)
	{
		if (c && i)
			result += ll (x[i].first - x[i-1].first);
		if (x[i].second)
			++c;
		else
			--c;
	}
	return result;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 48; j++) {
            if (i + j > n) continue;
            ll cur = 4 * i + 9 * j;
            q[cur % 49].push_back(make_pair(cur / 49, (cur / 49) + (n - i - j) + 1));
        }
    }
    ll ans = 0;
    for (int i = 0; i < 49; i++) {
        ans += get_un(q[i]);
    }
    cout << ans;
	return 0;
}