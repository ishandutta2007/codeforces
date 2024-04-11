#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool TEST = false;

ll MAXN = ll(1e14);

ll M = 3234512345123;

ll bal;
ll yes;
ll no;

int nq = 0;

bool tr(ll x){
	x = min(x, MAXN);
	if(x == 0) return true;
	nq++;

	bool works;
	if(TEST){
		works = (x <= M);
	} else {
		cout << "? ";
		cout << x << '\n';
		cout << flush;
		string s;
		cin >> s;
		works = (s == "Lucky!");
		if(s == "Fired!") exit(0);
	}
	if(works){
		bal += x;
		yes = max(yes, x);
		return true;
	} else {
		bal -= x;
		no = min(no, x);
		return false;
	}
}

void solve(){
	auto answer = [&](ll a){
		cout << "! ";
		cout << a << '\n';
		cout << flush;
		if(TEST){
			assert(a == M);
			assert(nq <= 105);			
		}
	};
	bal = 1;
	yes = 0;
	no = MAXN + 1;
	nq = 0;
	while(yes + 1 < no){
		if(!tr(bal)) break;
	}
	// cerr << bal << ' ' << yes << ' ' << no << ' ' << nq << '\n';
	tr(yes);
	tr(yes);
	while(yes + 1 < no){
		{
			ll m1 = (yes + no) / 2;
			if(bal >= m1 * 2){
				tr(m1);
				continue;
			}
		}
		{
			ll m = yes + (no - yes) * 0.29;
			if(m == yes) m++;
			if(bal < m){
				tr(yes);
			} else {
				tr(m);
			}
		}
	}
	// cerr << bal << ' ' << yes << ' ' << no << ' ' << nq << '\n';
	if(yes + 1 == no){
		answer(yes); return;
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	mt19937_64 mt(time(0));
	int T;
	cin >> T;
	while(T--){
		if(TEST){
			cerr << T << '\n';
			ll r = mt() % (48);
			M = min(MAXN, ll(mt() % (1ll << r)));
		}
		solve();
	}
}