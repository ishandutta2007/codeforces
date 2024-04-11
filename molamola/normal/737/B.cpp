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

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

void solve(){
	int n, a, b, k;
	char A[200020];
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf("%s", A+1);
	int p[200020] = {};
	int ans = 0;
	vector <int> v;
	for(int i=1;i<=n;i++){
		if(A[i] == '0'){
			p[i] = p[i-1] + 1;
			if(i == n || A[i+1] == '1')ans += p[i] / b;
			if(p[i] % b == 0)v.pb(i);
		}
		else p[i] = 0;
	}
	ans = max(ans-a+1, 0);
	printf("%d\n", ans);
	for(int i=0;i<ans;i++)printf("%d ", v[i]);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}