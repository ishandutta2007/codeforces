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
typedef pair<ll, ll> PL;
typedef long double ldouble;

int A[110], n, k;

void Do(int x, vector <int> a){
	if(x == k)return;
	int n = sz(a);
	int t = A[x] % n;
	printf("%d ", a[t]);
	vector <int> w;
	for(int i=1;i<n;i++)w.pb(a[(t+i)%n]);
	Do(x+1, w);
}

void solve(){
	scanf("%d%d", &n, &k);
	vector <int> v;
	for(int i=0;i<k;i++)scanf("%d", A+i);
	for(int i=0;i<n;i++)v.pb(i+1);
	Do(0, v);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}