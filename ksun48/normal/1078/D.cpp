#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> l, r, x;

vector<vector<int> > jl, jr;

int largmin(int i, int j){
	if(l[i] < l[j]) return i;
	return j;
}
int rargmax(int i, int j){
	if(r[i] > r[j]) return i;
	return j;
}

int lmin(int a, int b){
	int z = 0;
	while((1 << (z+1)) <= b-a+1) z += 1;
	return largmin(jl[z][b], jl[z][a-1+(1 << z)]);
}
int rmax(int a, int b){
	int z = 0;
	while((1 << (z+1)) <= b-a+1) z += 1;
	return rargmax(jr[z][a], jr[z][b+1 - (1 << z)]);
}

int main(){
	int n;
	cin >> n;
	x.resize(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	int N = 3*n;
	l.resize(N);
	r.resize(N);
	for(int i = 0; i < N; i++){
		l[i] = max(i - x[i % n], 0);
		r[i] = min(i + x[i % n], N-1);
	}
	const int MAXJ = 20;
	jl.resize(MAXJ, vector<int>(N));
	jr.resize(MAXJ, vector<int>(N));
	for(int j = 0; j < MAXJ; j++){
		for(int i = 0; i < N; i++){
			if(j == 0){
				jl[j][i] = jr[j][i] = i;
			} else {
				jl[j][i] = largmin(jl[j-1][i], jl[j-1][max(i - (1 << (j-1)), 0)]);
				jr[j][i] = rargmax(jr[j-1][i], jr[j-1][min(i + (1 << (j-1)), N-1)]);
			}
		}
	}
	vector<vector<int> > lexpo(MAXJ, vector<int>(N));
	vector<vector<int> > rexpo(MAXJ, vector<int>(N));	
	for(int j = 0; j < MAXJ; j++){
		for(int i = 0; i < N; i++){
			if(j == 0){
				lexpo[j][i] = lmin(l[i], i);
				rexpo[j][i] = rmax(i, r[i]);
			} else {
				lexpo[j][i] = lexpo[j-1][lexpo[j-1][i]];
				rexpo[j][i] = rexpo[j-1][rexpo[j-1][i]];
			}
		}
	}
	vector<int> ans(n);
	for(int i = n; i < 2*n; i++){
		int curl = i;
		int curr = i;
		int nsteps = 0;
		while(1){
			if(curr - curl + 1 >= n) break;
			for(int j = MAXJ-1; j >= 0; j--){
				int newl = lmin(curl, curr);
				int newr = rmax(curl, curr);
				int xl = lexpo[j][newl];
				int xr = rexpo[j][newr];
				if(r[rmax(xl, curl)] > curr){
					continue;
				}
				if(l[lmin(curr, xr)] < curl){
					continue;
				}
				if(r[xr] - l[xl] + 1 >= n) continue;
				curl = l[xl];
				curr = r[xr];
				nsteps += 1 + (1<<j);
			}
			if(curr - curl + 1 >= n) break;
			int newl = lmin(curl, curr);
			int newr = rmax(curl, curr);
			curl = l[newl];
			curr = r[newr];
			nsteps++;
		}
		ans[i - n] = nsteps;
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}