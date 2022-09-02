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

typedef pair<double, double> pdd;

pii p[1010];
int n;

double dis(pii a, pii b){
	return hypot(a.Fi - b.Fi, a.Se - b.Se);
}

pii operator-(pii a, pii b){return pii(a.Fi - b.Fi, a.Se - b.Se); }

ll crs(pii a, pii b){
	return (ll)a.Fi * b.Se - (ll)a.Se * b.Fi;
}

int chk(pii a, pii b, pii c, double R){
	double t = (double)crs(c-a, b-a);
	t /= dis(a, c);
	if(t > 2 * R)return 1;
	return 0;
}

int Do(double X){
	rep(i, n){
		int a = i, b = (i+1) % n, c = (i+2) % n;
		if(chk(p[a], p[b], p[c], X) == 0)return 0;
	}
	return 1;
}

void solve(){
	scanf("%d", &n);
	rep(i, n)scanf("%d%d", &p[i].Fi, &p[i].Se);
	double low = 0, high = 2e9;
	rep(i, n){
		high = min(high, dis(p[i], p[(i+1)%n]));
	}
	rep(u, 70){
		double mid = (low + high) * 0.5;
		if(Do(mid))low = mid;
		else high = mid;
	}
	printf("%.12f\n", low);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}