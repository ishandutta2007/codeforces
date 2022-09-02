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

int n, s, a[200020], p[200020];

void solve(){
	scanf("%d%d", &n, &s);
	for(int i=1;i<=n;i++)scanf("%d", a+i);
	int ans = 0;
	if(a[s] != 0)ans++;
	for(int i=1;i<=n;i++)if(i!=s){
		p[a[i]]++;
	}
	for(int i=1, c=n-1;i<n;i++){
		if(p[i] > 0){
			c -= p[i];
			if(c <= 0)break;
		}
		else{
			c--;
			ans++;
			if(c == 0)break;
		}
	}
	printf("%d",ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}