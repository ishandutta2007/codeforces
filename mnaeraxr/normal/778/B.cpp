#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int OR(int a, int b){
	if (a == 1 || b == 1) return 1;
	if (a == 0 || b == 0) return max(a, b);
	if (a != b) return 1;
	return a;
}

int AND(int a, int b){
	if (a == 0 || b == 0) return 0;
	if (a == 1 || b == 1) return max(a, b);
	if (a != b) return 0;
	return a;
}

int XOR(int a, int b){
	return a ^ b;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vector<int> diff(m);

	vi one(m, 2), zero(m, 3);

	map<string, vi> id;
	id["?"] = one;

	for (int i = 0; i < n; ++i){
		string vname; 	cin >> vname;
		string sep; 	cin >> sep;

		vi value(m);

		string a; cin >> a;
		if (('a' <= a[0] && a[0] <= 'z') || a[0] == '?'){
			string op, b;
			cin >> op >> b;

			vi &va = id[a];
			vi &vb = id[b];

			for (int j = 0; j < m; ++j){
				if (op == "AND") value[j] = AND( va[j], vb[j] );
				if (op ==  "OR") value[j] =  OR( va[j], vb[j] );
				if (op == "XOR") value[j] = XOR( va[j], vb[j] );

				if (value[j] == 2) diff[j]++;
				if (value[j] == 3) diff[j]--;
			}
		}
		else{
			for (int j = 0; j < m; ++j)
				value[j] = a[j] - '0';
		}

		id[ vname ] = value;
	}

	for (int i = 0; i < m; ++i){
		if (diff[i] < 0) cout << 1;
		else cout << 0;
	}

	cout << endl;

	for (int i = 0; i < m; ++i){
		if (diff[i] > 0) cout << 1;
		else cout << 0;
	}

	cout << endl;



	return 0;
}