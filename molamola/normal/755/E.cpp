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
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

void solve(){
	int n, k; scanf("%d%d", &n, &k);
	if(n == 2){puts("-1"); return;}
	if(n == 3){
		puts("-1");
	}
	else if(n == 4){
		if(k != 3)puts("-1");
		else{
			printf("3\n");
			printf("1 2\n2 3\n3 4\n");
		}
	}
	else{
		if(k == 2){
			printf("%d\n", n-1);
			for(int i=1;i<n;i++)printf("%d %d\n", i, i+1);
		}
		else if(k == 3){
			printf("%d\n", n-1);
			printf("1 2\n2 3\n3 4\n");
			for(int i=5;i<=n;i++)printf("2 %d\n", i);
		}
		else puts("-1");
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}