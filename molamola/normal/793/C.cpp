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

int n, S[2], D[2];

void solve(){
	scanf("%d", &n);
	scanf("%d%d%d%d", S, S+1, D, D+1);
	ldouble left, right;
	left = 0, right = 1e15;
	rep(i, n){
		int x[2], y[2];
		scanf("%d%d%d%d", x, x+1, y, y+1);
		rep(j, 2){
			int a = x[j], v = y[j];
			ldouble A, B;
			if(v == 0){
				if(S[j] < a && a < D[j]){
					continue;
				}
				else{
					puts("-1");
					return;
				}
			}
			else{
				A = (ldouble)(S[j] - a) / v;
				B = (ldouble)(D[j] - a) / v;
				if(A > B)swap(A, B);
				left = max(A, left);
				right = min(B, right);
			}
		}
	}
	if(left + 1e-11 < right){
		printf("%.20lf\n", (double)left);
	}
	else{
		puts("-1");
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}