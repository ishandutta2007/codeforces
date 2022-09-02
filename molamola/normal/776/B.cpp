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

int p[100010];

void solve(){
	for(int i=2;i<100010;i++)p[i] = 1;
	for(int i=2;i<100010;i++)if(p[i]){
		for(int j=i+i;j<100010;j+=i)p[j] = 0;
	}
	int n; cin >> n;
	if(n == 1){
		printf("1\n1\n");
		return;
	}
	else if(n == 2){
		printf("1\n1 1\n");
		return;
	}
	printf("%d\n", 2);
	for(int i=2;i<=n+1;i++)printf("%d ", p[i] ? 1 : 2);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}