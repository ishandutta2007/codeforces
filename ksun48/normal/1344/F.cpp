#include <bits/stdc++.h>
using namespace std;

using bs = bitset<2048>;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solveLinear(vector<bs>& A, vi& b, bs& x, int m) {
	int n = sz(A), rank = 0, br;
	assert(m <= sz(x));
	vi col(m); iota(all(col), 0);
	rep(i,0,n) {
		for (br=i; br<n; ++br) if (A[br].any()) break;
		if (br == n) {
			rep(j,i,n) if(b[j]) return -1;
			break;
		}
		int bc = (int)A[br]._Find_next(i-1);
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) if (A[j][i] != A[j][bc]) {
			A[j].flip(i); A[j].flip(bc);
		}
		rep(j,i+1,n) if (A[j][i]) {
			b[j] ^= b[i];
			A[j] ^= A[i];
		}
		rank++;
	}

	x = bs();
	for (int i = rank; i--;) {
		if (!b[i]) continue;
		x[col[i]] = 1;
		rep(j,0,i) b[j] ^= A[j][i];
	}
	return rank; // (multiple solutions if rank < m)
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using B = bitset<1024>;
	B rouge_rouge, rouge_bleue, bleue_rouge, bleue_bleue;
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		rouge_rouge[i].flip();
		bleue_bleue[i].flip();
	}
	vector<bs> A;
	vector<int> b;
	for(int _ = 0; _ < k; _++){
		string s;
		cin >> s;
		int l;
		cin >> l;
		vector<int> ind(l);
		for(int i = 0; i < l; i++){
			cin >> ind[i]; ind[i]--;
		}
		if(s == "mix"){
			string res;
			cin >> res;
			int val_rouge, val_bleue;
			val_rouge = (res == "Y" || res == "R");
			val_bleue = (res == "Y" || res == "B");
			bs eq_rouge, eq_bleue;
			for(int a : ind){
				if(rouge_rouge[a]) eq_rouge[a].flip();
				if(bleue_rouge[a]) eq_rouge[a + n].flip();
				if(rouge_bleue[a]) eq_bleue[a].flip();
				if(bleue_bleue[a]) eq_bleue[a + n].flip();
			}
			A.push_back(eq_rouge);
			b.push_back(val_rouge);
			A.push_back(eq_bleue);
			b.push_back(val_bleue);
		} else {
			if(s == "RB"){
				for(int a : ind){
					if(rouge_rouge[a] ^ rouge_bleue[a]){
						rouge_rouge[a].flip();
						rouge_bleue[a].flip();
					}
					if(bleue_rouge[a] ^ bleue_bleue[a]){
						bleue_rouge[a].flip();
						bleue_bleue[a].flip();
					}
				}
			} else if(s == "RY"){
				for(int a : ind){
					if(rouge_rouge[a]) rouge_bleue[a].flip();
					if(bleue_rouge[a]) bleue_bleue[a].flip();
				}
			} else if(s == "YB"){
				for(int a : ind){
					if(rouge_bleue[a]) rouge_rouge[a].flip();
					if(bleue_bleue[a]) bleue_rouge[a].flip();
				}
			} else assert(false);
		}
	}
	bs x;
	int works = solveLinear(A, b, x, 2*n);
	if(works == -1){
		cout << "NO" << '\n';
		exit(0);
	}
	cout << "YES" << '\n';
	for(int i = 0; i < n; i++){
		int v = 0;
		if(x[i]) v ^= 1;
		if(x[i+n]) v ^= 2;
		cout << ".RBY"[v];
	}
	cout << '\n';
}