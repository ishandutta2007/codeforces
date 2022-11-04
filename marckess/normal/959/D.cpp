#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi pr;
const int MN = 5'000'000;
bitset<MN> bs, us;
void criba () {
	bs.set();

	for (ll i = 2; i < MN; i++) {
		if (bs[i]) {
			pr.push_back(i);
			for (ll j = i*i; j < MN; j += i)
				bs[j] = 0;
		}
	}
}

int n, a, b;
bool fac (int n, bool f) {
	for (int i = 0; ll(pr[i]) * pr[i] <= n && i < pr.size(); i++) {
		if (n % pr[i] == 0 && us[pr[i]] && !f)
			return 1;

		while (n % pr[i] == 0) {
			us[pr[i]] = us[pr[i]] || f;
			n /= pr[i];
		}
	}

	if (n > 1) {
		if (us[n] && !f)
			return 1;
		us[n] = us[n] || f;
	}

	return 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    criba();

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a;

    	if (fac(a, 0)) {
    		for (int j = a+1; 1; j++) {
    			if (fac(j, 0))
    				continue;
    			fac(j, 1);

    			cout << j << " ";
    			i++, j = 2;

    			while (i < n) {
    				while (!bs[j] || us[j])
    					j++;
    				cout << j++ << " ";
    				i++;
    			}

    			break;
    		}

    		break;
    	}

    	fac(a, 1);
    	cout << a << " ";
    }

    cout << endl;

    return 0;
}