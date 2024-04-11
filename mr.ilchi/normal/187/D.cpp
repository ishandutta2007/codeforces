/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 100 * 1000 + 10;
const int maxT = (1<<20); 
const int inf  = 1000 * 1000 * 1000;

int n,g,r,mod,que;
int len[maxN],mini[maxT],X[maxN];
ll sum[maxN],dp[maxN];
vector <int> Q;

int get (int root, int lo, int hi, int s, int e){

	if (hi<s || e<lo)
		return inf;

	if (s<=lo && hi<=e)
		return mini[root];

	int mid = (lo + hi) / 2;

	return min(get(root<<1,lo,mid,s,e),get((root<<1)+1,mid+1,hi,s,e));
}

void go (int root, int lo, int hi, int pos, int val){

	mini[root] = min (mini[root] , val);

	if (lo == hi)
		return;

	int mid = (lo + hi) / 2;

	if (pos <= mid)
		go(root<<1 , lo , mid, pos, val);
	else
		go((root<<1)+1, mid+1, hi, pos, val);

	mini[root] = min(mini[root<<1] , mini[(root<<1)+1]);
}

int getIndex (int x){

//	return x;

	return lower_bound(Q.begin(),Q.end(),x) - Q.begin();
}

int main(){

	scanf("%d%d%d" , &n, &g, &r);

	mod = (g + r);
	
	for (int i=1; i<=n+1; i++){
		scanf("%d" , &len[i]);
		sum[i] = sum[i-1] + len[i];
		Q.push_back(sum[i]%mod);
		Q.push_back((sum[i]+g)%mod);
		Q.push_back((sum[i]+mod-1)%mod);
	}

	scanf("%d" , &que);

	for (int i=1; i<=que; i++){
		scanf("%d" , &X[i]);
		Q.push_back(((-X[i]+g)%mod+mod)%mod);
		Q.push_back(((-X[i]+mod-1)%mod+mod)%mod);
	}

	Q.push_back(0);
	Q.push_back(mod-1);

	sort(Q.begin(),Q.end());
	Q.resize(unique(Q.begin(),Q.end())-Q.begin());

	for (int i=0; i<maxT; i++)
		mini[i] = inf;

	for (int i=n; i>0; i--){

		ll f1 = sum[i] + g; f1%=mod;
		ll f2 = sum[i] + mod - 1; f2%=mod;

		ll p1=f1;
		ll p2=f2;

		f1 = getIndex(f1);
		int tmp = getIndex(f2); 
	
		if (Q[tmp]!=f2) 
			f2=tmp-1;
		else
			f2 = tmp;

		if (f2<0)
			f2 = (int)Q.size()-1;

		int ans = inf;

		bool f = (p1<p2 && f1>f2);

		if (f1<=f2 && !f)
			ans = get(1,0,(int)Q.size()-1,f1,f2);
		else if (!f)
			ans = min(get(1,0,(int)Q.size()-1,f1,(int)Q.size()-1),get(1,0,(int)Q.size()-1,0,f2));

		if (ans == inf)
			dp[i] = sum[n+1] - sum[i];
		else
			dp[i] = sum[ans] - sum[i] + (mod - ((sum[ans]-sum[i])%mod)) + dp[ans];

		go(1,0,(int)Q.size()-1,getIndex(sum[i]%mod),i);
	}

//	cout << dp[1] << ' ' << sum[1]%mod << endl;

//	cout << " :: " << getIndex(sum[1]%mod) << endl;

//	for (int i=1; i<=n+1; i++)
//		cout << dp[i] << ' ' ;
//	cout << endl;

	for (int o=1; o<=que; o++){
	
		int x; x = X[o];

		ll f1 = -x + g; f1%=mod; if (f1<0) f1+=mod;
		ll f2 = -x + mod - 1; f2%=mod; if (f2<0) f2+=mod;

//		cout << f1 << ' ' << f2 << endl;

		ll p1 = f1;
		ll p2 = f2;

		f1 = getIndex(f1);

		int tmp = getIndex(f2); 
		if (Q[tmp]!=f2) 
			f2=tmp-1;
		else
			f2 = tmp;
		
		if (f2 < 0)
			f2 = (int)Q.size()-1;

		bool f = (p1<p2 && f1>f2);

//		cout << f1 << ' ' << f2 << endl;

		int ans = inf;

		if (f1<=f2 && !f) 
			ans = get(1,0,(int)Q.size()-1,f1,f2);
		else if (!f)
			ans = min(get(1,0,(int)Q.size()-1,f1,(int)Q.size()-1),get(1,0,(int)Q.size()-1,0,f2));

	//	cout << ans << endl;

		ll res = 0;

		if (ans==inf)
			res = x + sum[n+1];
		else
			res = x + sum[ans] + (mod-((sum[ans]+(x%mod))%mod)) + dp[ans]; 

		printf ("%I64d\n" , res);
	}

	return 0;
}