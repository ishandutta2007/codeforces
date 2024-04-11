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

int n, A[100010];
int chk[100010];
int st[100010], top;
int ans[100010];
int c[100010];

int get_naive(int x){
	int res = 0;
	for(int i=1, cnt = 0;i<=n;i++){
		if(c[A[i]] == 0){
			++cnt, c[A[i]] = 1, st[top++] = A[i];
		}
		if(i == n || (cnt == x && c[A[i+1]] == 0)){
			cnt = 0;
			while(top)c[st[--top]] = 0;
			res++;
		}
	}
	return res;
}

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", A+i);
	int q = 300;
	for(int i=1;i<=q;i++){
		ans[i] = get_naive(i);
	}
	if(q < n){
		int L[100010] = {};
		while(L[q+1] < n){
			int cnt = 0, save = L[q+1];
			for(int j=L[q+1]+1;j<=n;j++){
				if(c[A[j]] == 0){
					++cnt, st[top++] = A[j];
				}
				c[A[j]] += 1;
				if(j == n || (cnt == q+1 && c[A[j+1]] == 0)){
					L[q+1] = j;
					break;
				}
			}
			ans[q+1]++;
			for(int i=q+2;i<=n;i++){
				if(L[i] == n)break;
				for(int j=save+1;j<=L[i];j++){
					c[A[j]]--;
					if(c[A[j]] == 0){
						--cnt;
					}
				}
				save = L[i];
				for(int j=L[i-1]+1;j<=n;j++){
					if(c[A[j]] == 0){
						++cnt, st[top++] = A[j];
					}
					c[A[j]] += 1;
					if(j == n || (cnt == i && c[A[j+1]] == 0)){
						L[i] = j;
						break;
					}
				}
				if(L[i-1] == n)L[i] = n;
				ans[i]++;
			}
			
			while(top)c[st[--top]] = 0;
		}
	}
	
	for(int i=1;i<=n;i++)printf("%d ", ans[i]);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}