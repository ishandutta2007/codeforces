#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
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
typedef tuple<int, int, int> t3;
typedef tuple<int, int, int, int> t4;
typedef pair<ll, ll> PL;
typedef long double ldouble;

int n, p;
int A[100010], B[100010];

void solve(){
	scanf("%d%d", &n, &p);
	for(int i=1;i<=n;i++)scanf("%d%d", A+i, B+i);
	double low = 0, high = 1e13;
	rep(u, 90){
		double mid = (low + high) * 0.5;
		double sum = 0;
		for(int i=1;i<=n;i++){
			double use = A[i] * mid;
			sum += max(0.0, use - B[i]);
		}
		if(sum < p * mid)low = mid;
		else high = mid;
	}
	if(low > 9e12){
		puts("-1");
	}
	else printf("%.12f\n", low);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}