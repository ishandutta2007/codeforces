#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int par[2][510000];
vector<int> r[2][510000];
int anc[510000];
vector<int> a1, a2, a3, a4;
void mk(int c, int i, int p){
	if(par[c][i] >= 0) return;
	par[c][i] = p;
	for(int l = 0; l < r[c][i].size(); l++){
		mk(c,r[c][i][l],i);
	}
}
void st(int i){
	if(par[1][i] != par[0][i] && par[0][par[1][i]] != i){
		anc[i] = i;
	} else {
		anc[i] = anc[par[1][i]];
	}
	for(int l = 0; l < r[1][i].size(); l++){
		if(r[1][i][l] != par[1][i]){
			st(r[1][i][l]);
		}
	}
}
void solve(int i){
	for(int l = 0; l < r[0][i].size(); l++){
		if(r[0][i][l] != par[0][i]){
			solve(r[0][i][l]);
		}
	}
	if(par[1][i] != par[0][i] && par[1][par[0][i]] != i){
		a1.push_back(i);
		a2.push_back(par[0][i]);
		a3.push_back(anc[i]);
		a4.push_back(par[1][anc[i]]);
	}
}
int main(){
	int n, a, b;
	scanf("%d", &n);
	for(int c = 0; c < 2; c++){
		for(int i = 0; i <= n; i++) par[c][i] = -1;
		for(int i = 1; i < n; i++){
			scanf("%d%d", &a, &b);
			r[c][a].push_back(b);
			r[c][b].push_back(a);
		}
		mk(c,1,0);
	}
	st(1);
	solve(1);
	printf("%d\n", a1.size());
	for(int i = 0; i < a1.size(); i++){
		printf("%d %d %d %d\n", a1[i], a2[i], a3[i], a4[i]);
	}
}