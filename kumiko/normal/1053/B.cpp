#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int M = 1000000007;

int n;
ll x, cnt[2];
int a[300005], s[300005];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%I64d", &x);
		for(int j = 0; j < 60; ++j)
			if(x >> j & 1) ++a[i];
		s[i] = a[i] + s[i - 1];
	}

	++cnt[0];
	ll res = 0;
	for(int i = 1; i <= n; ++i){
		res += cnt[s[i] & 1];
		++cnt[s[i] & 1];

		int tmax = 0;
		for(int j = i; j && j >= i - 61; --j){
			int sum = s[i] - s[j - 1];
			tmax = max(tmax, a[j]);
			if(sum & 1) continue;
			if(tmax * 2 > sum) --res;
		}
	}

	printf("%I64d\n", res);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}