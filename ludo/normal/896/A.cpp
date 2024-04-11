#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const string F0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string F10 = "What are you doing while sending \"";
const string F11 = "\"? Are you busy? Will you send \"";
const string F12 = "\"?";

const ll maxlen = 1e18 + 1000;
vector<ll> lengths;

ll getlen(int n) {
	if (n < (int) lengths.size())
		return lengths[n];
	return maxlen;
}

char query(ll n, ll k) {
	if (k >= getlen(n)) {
		return '.';
	}

	if (n == 0) return F0[k];

	ll sublen = getlen(n - 1);
	ll n0 = F10.size(), n1 = F11.size(), n2 = F12.size();

	if (k < n0)
		return F10[k];
	if (k < n0 + sublen)
		return query(n - 1, k - n0);
	if (k < n0 + n1 + sublen)
		return F11[k - n0 - sublen];
	if (k < n0 + n1 + sublen + sublen)
		return query(n - 1, k - n0 - n1 - sublen);
	return F12[k - n0 - n1 - sublen - sublen];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lengths.pb(F0.size());
	while (true) {
		ll last = lengths.back();
		ll cur = 2 * last + F10.size() + F11.size() + F12.size();
		if (cur > maxlen) break;
		lengths.pb(cur);
	}

	int q;
	cin >> q;
	string ans(q, '.');
	for (int i = 0; i < q; i++) {
		ll n, k;
		cin >> n >> k;
		ans[i] = query(n, k - 1);
	}
	cout << ans << endl;
	return 0;
}