#include <bits/stdc++.h>
using namespace std;
 
int mex(set<int> r){
	int z = 0;
	while(r.count(z)) z++;
	return z;
}
struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};
 
const int M = 500;
 
int solve(vector<int> a){
	int n = (int)a.size();
	vector<vector<int> > first_occ(M, vector<int>(n, -1));
	vector<UF> uf(M, UF(n+1));
	set<int> st;
	for(int j = n-1; j >= 0; j--){
		vector<int> where;
		where.push_back(0);
		int curk = n-1;
		int v;
		for(v = 0; first_occ[v][j] >= 0; v++){
			curk = min(curk, first_occ[v][j]);
			int look = 2 * a[j] - a[curk];
			int i = lower_bound(a.begin(), a.end(), look+1) - a.begin();
			where.push_back(i);
		}
		where.push_back(j+1);
		st.insert(v);
		for(int z = 0; z <= v; z++){
			while(true){
				int r = uf[z].find(where[z]);
				if(r >= where[z+1]) break;
				uf[z].join(r, r+1);
				first_occ[z][r] = j;
			}
		}
	}
 
	return mex(st);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int ans = 0;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int& x : a) cin >> x;
		int res = solve(a);
		ans ^= res;
	}
	cout << (ans == 0 ? "NO" : "YES") << '\n';
}