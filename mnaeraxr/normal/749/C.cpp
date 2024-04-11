#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

typedef complex<int> point;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

set<int> P[2];

int F[maxn], n;

int root(int a){
	return F[a] < 0 ? a : F[a] = root(F[a]);
}

void rem(int a){
	P[0].erase(a);
	P[1].erase(a);

	F[a] = (a + 1) % n;
}

int get_next(int prt, int pos){
	set<int>::iterator it = P[prt].lower_bound(pos);
	if (it == P[prt].end()) return *P[prt].begin();
	return *it;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string s; cin >> s;

	for (int i = 0; i < n; ++i){
		F[i] = -1;
		P[ s[i] == 'D' ].insert(i);
	}

	int td = (int)P[1].size(), tr = (int)P[0].size();

	for (int p = 0; td && tr; ){
		int prt = s[p] == 'D';

		int nxt = get_next(prt ^ 1, p);

		rem(nxt);
		td -= prt == 0;
		tr -= prt == 1;

		p = root( (p + 1) % n);
	}

	if (td) cout << "D" << endl;
	else cout << "R" << endl;

	return 0;
}