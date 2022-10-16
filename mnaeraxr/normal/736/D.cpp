#include <bits/stdc++.h>

using namespace std;

typedef bitset<2000> bs;
typedef vector<bs> mat;
typedef pair<int,int> pii;

void print(mat M){
	int n = (int)M.size();
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			cout << M[i].test(j);
		cout << endl;
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;

	mat A(n), B(n);
	vector<pii> Q(m);

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		u--; v--;
		Q[i] = pii(u, v);
		A[u].set(v);
	}

	for (int i = 0; i < n; ++i)
		B[i].set(i);

	for (int i = 0; i < n; ++i){
		int piv = i;
		while (!A[piv].test(i))
			++piv;

		swap(A[piv], A[i]);
		swap(B[piv], B[i]);

		for (int j = i + 1; j < n; ++j)
			if (A[j].test(i)){
				A[j] ^= A[i];
				B[j] ^= B[i];
			}

		
	}

	for (int i = n - 1; ~i; --i){
		for (int j = 0; j < i; ++j)
			if (A[j].test(i)){
				A[j] ^= A[i];
				B[j] ^= B[i];
			}
	}

	for (int i = 0; i < m; ++i){	
		int u = Q[i].first, v = Q[i].second;

		cout << (!B[v].test(u) ? "YES" : "NO") << endl;
	}
}