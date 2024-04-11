#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef pair<ll, ll> PL;
typedef long double ldouble;

vector <int> E[5050];
int down[5050];
int n;
int A[4];
bitset <5050> can[5050];
int C[4][5050];
int d2[5050];

int adfs(int x){
	if(x == A[0] || x == A[1] || x == A[2] || x == A[3]){
		int t = (int)(find(A, A+4, x) - A);
		d2[x] = t;
		return t;
	}
	for(int e : E[x]){
		int a = adfs(e);
		if(a != -1)return d2[x] = a;
	}
	return d2[x] = -1;
}

void pdfs(int x){
	can[x].reset();
	down[x] = (sz(E[x]) == 0 ? 1 : 0);
	if(x == A[0] || x == A[1] || x == A[2] || x == A[3]){
		can[x][0] = 1;
		return;
	}
	vector <int> v;
	int z = 0;
	for(int e : E[x]){
		pdfs(e);
		down[x] += down[e];
		if(d2[x] != -1){
			if(d2[e] == -1)v.pb(down[e]);
			else can[x] = can[e], z = down[e];
		}
	}
	for(int e : v){
		for(int i=z+e-1;i>=e;i--){
			can[x][i] = can[x][i] | can[x][i-e];
		}
		z += e;
	}
}

int tot_leaf;
int Dw[4];

int Do(int a, int b, int c, vector <int> &V){
	int ok[5050] = {};
	if(Dw[c] > tot_leaf / 2 - 1) return 0;
	int des = tot_leaf / 2 - 1 - Dw[c];
	for(int i=0;i<Dw[a];i++)if(C[a][i]){
		int t = Dw[a] - i - 1;
		ok[t] = 1;
	}
	for(int e : V){
		for(int i=des;i>=e;i--){
			ok[i] |= ok[i-e];
		}
	}
	int ud = 6 - a - b - c;
	for(int i=des;i>=Dw[ud];i--){
		ok[i] |= ok[i-Dw[ud]];
	}
	for(int i=0;i<Dw[b];i++)if(C[b][i]){
		for(int j=des;j>=i;j--){
			ok[j] |= ok[j-i];
		}
	}
	return ok[des];
}

void solve(){
	scanf("%d", &n);
	rep(i, 4)scanf("%d", A+i);
	for(int i=2;i<=n;i++){
		int x; scanf("%d", &x);
		E[x].pb(i);
	}
	memset(d2, -1, sizeof d2);
	for(int e : E[1])adfs(e);
	vector <int> V;
	
	for(int e : E[1]){
		pdfs(e);
		tot_leaf += down[e];
		if(d2[e] == -1) V.pb(down[e]);
		else{
			int t = d2[e];
			Dw[t] = down[e];
			for(int i=0;i<=down[e];i++){
				C[t][i] = can[e].test(i);
			}
		}
	}
	if(tot_leaf % 2 != 0) puts("NO");
	else if(Do(0, 1, 2, V) && Do(2, 3, 1, V)) puts("YES");
	else if(Do(0, 1, 3, V) && Do(3, 2, 1, V)) puts("YES");
	else puts("NO");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}