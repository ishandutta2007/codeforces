#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string fi = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
ll tam[100005];

//What are you doing while sending ""? Are you busy? Will you send ""?

ll obtTam (int i) {
	if (i == 0) {
		return tam[i] = f0.size();
	}

	if (tam[i] != -1)
		return tam[i];

	return tam[i] = fi.size() + 2 * obtTam(i-1);
}

char obtRes (int i, ll k) {
	if (i == 0)
		return f0[k];

	if (k < 34)
		return fi[k];

	if (i > 53 || k < 34 + tam[i-1])
		return obtRes(i-1, k - 34);

	if (k < 66 + tam[i-1])
		return fi[k - tam[i-1]];

	if (k < 66 + 2 * tam[i-1])
		return obtRes(i-1, k - 66 - tam[i-1]);

	return fi[k - 2 * tam[i-1]];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	SET(tam, -1);
	obtTam(53);

	int q, n;
	ll k;

	cin >> q;
	while (q--) {
		cin >> n >> k;

		if (n > 53) {
			cout << obtRes(n, k-1);
		} else {
			if (k > tam[n])
				cout << '.';
			else
				cout << obtRes(n, k-1);
		}
	}
	cout << endl;

	return 0;
}


//What are you doing while sending "What are you doing at the end of the world? Are you busy? Will you save us?"? Are you busy? Will you send "What are you doing at the end of the world? Are you busy? Will you save us?"?"