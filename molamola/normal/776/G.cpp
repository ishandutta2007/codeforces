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

ll P, a;
ll D[20][2][2];

ll get(int x, int s, int b){
	if(x == -1){
		return b;
	}
	if(D[x][s][b] != -1)return D[x][s][b];
	ll res = 0;
	for(int i=0;i<=a;i++){
		int nb = (b | (i == a));
		int ns = 0;
		if(s == 1){
			int temp = (P >> (4*x)) & 15;
			if(i > temp)break;
			if(i == temp)ns = 1;
		}
		if(a / 4 == x && (i & (1<<(a&3))) == 0)continue;
		res += get(x-1, ns, nb);
	}
	return D[x][s][b] = res;
}

ll Do(ll X, int t){
	if(X <= 0 || (1LL << t) > X)return 0;
	P = X, a = t;
	memset(D, -1, sizeof D);
	return get(15, 1, 0);
}

void solve(){
	int q; scanf("%d", &q);
	while(q--){
		char A[30], B[30];
		scanf("%s%s", A, B);
		ll X = 0, Y = 0;
		for(int i=0;A[i];i++){
			int c = A[i] - '0';
			if(isalpha(A[i]))c = A[i] - 'a' + 10;
			X = (X<<4) | c;
		}
		for(int i=0;B[i];i++){
			int c = B[i] - '0';
			if(isalpha(B[i]))c = B[i] - 'a' + 10;
			Y = (Y<<4) | c;
		}
		ll ans = 0;
		for(int i=1;i<=15;i++){
			ans += Do(Y, i) - Do(X-1, i);
		}
		printf("%lld\n", ans);
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}