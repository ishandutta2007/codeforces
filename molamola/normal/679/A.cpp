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

int c[110];

void solve(){
	for(int i=2;i<=100;i++)c[i] = 1;
	int cnt = 0, v = -1;
	for(int i=2;i<=50;i++)if(c[i]){
		printf("%d\n", i); fflush(stdout);
		char S[10]; scanf("%s", S);
		if(!strcmp(S, "yes"))cnt++, v = i;
		for(int j=i+i;j<=100;j+=i)c[j] = 0;
	}
	if(cnt == 0){
		printf("prime\n"); fflush(stdout);
	}
	else if(cnt > 1){
		printf("composite\n"); fflush(stdout);
	}
	else{
		int a[] = {4, 9, 25, 49};
		rep(i, 4){
			printf("%d\n", a[i]); fflush(stdout);
			char S[10]; scanf("%s", S);
			if(!strcmp(S, "yes")){
				
				printf("composite\n"); fflush(stdout);
				return;
			}
		}
		
		printf("prime\n"); fflush(stdout);
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}