#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

int p[200020];
ll s[200020];
int n;
int ans[3];
double mx;

void Do(int x){
	int low = 1, high = min(x-1, n-x);
	int res = 0;
	while(low <= high){
		int mid = (low + high) >> 1;
		ll r = (ll)(p[x-mid] + p[n+1-mid]) * (mid + mid - 1);
		ll l = (s[n] - s[n+1-mid] + s[x] - s[x-mid]) * 2;
		if(l <= r)res = mid, low = mid + 1;
		else high = mid - 1;
	}
	double R = (double)(s[n] - s[n-res] + s[x] - s[x-1-res]) / (res + res + 1) - p[x];
	if(R > mx){
		mx = R;
		ans[0] = n - res + 1;
		ans[1] = x;
		ans[2] = x - res;
	}
}

void Do2(int x){
	//x, x-1;
	int low = 1, high = min(x-2, n-x);
	int res = 0;
	while(low <= high){
		int mid = (low + high) >> 1;
		ll r = (ll)(p[x-mid-1] + p[n+1-mid]) * (mid + mid);
		ll l = (s[n] - s[n+1-mid] + s[x] - s[x-mid-1]) * 2;
		if(l <= r)res = mid, low = mid + 1;
		else high = mid - 1;
	}
	double R = (double)(s[n] - s[n-res] + s[x] - s[x-2-res]) / (res + res + 2) - (p[x] + p[x-1]) / 2.0;
	if(R > mx){
		mx = R;
		ans[0] = n - res + 1;
		ans[1] = x;
		ans[2] = x - res - 1;
	}
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", p+i);
	if(n <= 2){
		printf("1\n%d", p[1]);
		return 0;
	}
	sort(p+1, p+1+n);
	for(int i=1;i<=n;i++)s[i] = s[i-1] + p[i];
	ans[0] = n+1, ans[1] = 1, ans[2] = 1;
	for(int i=1;i<n;i++)Do(i);
	for(int i=2;i<n;i++)Do2(i);
	printf("%d\n", n - ans[0] + 1 + ans[1] - ans[2] + 1);
	for(int i=ans[2];i<=ans[1];i++)printf("%d ", p[i]);
	for(int i=ans[0];i<=n;i++)printf("%d ", p[i]);
	return 0;
}