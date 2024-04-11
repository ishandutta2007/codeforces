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

void solve(){
	char S[200020],T[200020];
	scanf("%s%s", S+1, T+1);
	int A[200020];
	int n = (int)strlen(S+1);
	for(int i=1;i<=n;i++){
		int x; scanf("%d", &x); A[x] = i;
	}
	int low = 0, high = n, ans = 0;
	while(low <= high){
		int mid = (low + high) >> 1;
		int ok = 0;
		for(int i=1, j=1;i<=n;i++)if(A[i] > mid){
			if(S[i] == T[j])++j;
			if(T[j] == 0){ok = 1; break;}
		}
		if(ok)ans = mid, low = mid + 1;
		else high = mid - 1;
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case %d: ", tc);
		solve();
	}
	return 0;
}