#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 400005;
int ft[MX];

void update (int i, int k) {
	i++;
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
} 

void update (int a, int b, int k) {
	update(a, k);
	update(b, -k);
}

int get (int i) {
	int sum = 0;
	i++;

	while (i) {
		sum += ft[i];
		i -= i & -i;
	}

	return sum;
}

vi st;
ll n, l[MX], r[MX], res[MX];

#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	st.push_back(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		st.push_back(l[i]);
		st.push_back(r[i]+1);
	}

	sort(ALL(st));
	st.erase(unique(ALL(st)), st.end());

	for (int i = 0; i < n; i++)
		update(find(st, l[i]), find(st, r[i]+1), 1);

	for (int i = 0; i + 1 < st.size(); i++) {
		//cout << st[i] << "-" << st[i+1] << ":" << get(i) << endl;
		res[get(i)] += st[i+1] - st[i];
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}