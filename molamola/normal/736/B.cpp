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

int pr(int x){
	for(int i=2;i*i<=x;i++){
		if(x % i == 0)return 0;
	}
	return 1;
}

void solve(){
	int n; scanf("%d", &n);
	if(n == 1 || pr(n)){
		printf("1");
	}
	else if(n % 2 == 0){
		printf("2");
	}
	else if(pr(n-2))printf("2");
	else printf("3");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}