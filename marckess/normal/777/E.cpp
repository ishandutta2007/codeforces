#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

struct anillo {
	ll alt, in, ex;

	bool operator < (const anillo &b) const {
		if ( ex == b.ex )
			return in > b.in;
		return ex > b.ex;
	}
};

ll n, res = 0;
vector<ll> mx;
stack<ll> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	anillo an[100005];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> an[i].in >> an[i].ex >> an[i].alt;

	an[n].in = an[n].alt = 0, an[n].ex = 2e9;
	sort (an, an + n + 1);

	for (int i = 0; i <= n; i++) {
		mx.push_back(an[i].alt);
		while (st.size() && an[st.top()].in >= an[i].ex)
			st.pop();
		if (st.size())
			mx[i] += mx[st.top()];
		st.push(i);
	}

	cout << *max_element (mx.begin(), mx.end()) << endl;

	return 0;
}