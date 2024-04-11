#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<map>
#include<bitset>
#include<stack>
#include<vector>
#include<set>
using namespace std;
#define MAXN 300010
#define MAXM 1010
#define INF 1000000000
#define MOD 1000000007
#define ll long long
#define eps 1e-8
ll n,a,b,c,d,st,len;
ll t[MAXN],C[MAXN];
ll mn[MAXN];
ll s[MAXN];
ll q[MAXN],hd,tl;
ll cal(ll x,ll y){
	if(!y){
		if(!C[x]){
			return -b;
		}else{
			return a;
		}
	}else{
		if(!C[x]){
			return -d;
		}else{
			return c;
		}
	}
}
int main(){
	ll i;
	scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d,&st,&len);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&t[i],&C[i]);
	}
	t[n+1]=(ll)INF*3;
	ll now=st;
	for(i=n;i;i--){
		mn[i]=min(cal(i,0),cal(i,0)+mn[i+1]);
	}
	for(i=1;i<=n;i++){
		s[i]=s[i-1]+cal(i,1);
	}
	ll l=1,r=1;
	hd=1;
	while(t[r]<len){
		while(hd<=tl&&s[q[tl]]>=s[r]){
			tl--;
		}
		q[++tl]=r;
		r++;
	}
	bool flag=1;
	for(i=0;i<=t[n]+1;i=min(t[r]-len+1,t[l]+1)){
		while(t[l]<i){
			now+=cal(l,0);
		//	cerr<<l<<"*"<<now<<endl;
			if(now<0){
				flag=0;
				break;
			}
			l++;
		}
		if(!flag){
			break;
		}
		while(t[r]<i+len){
			while(hd<=tl&&s[q[tl]]>=s[r]){
				tl--;
			}
			q[++tl]=r;
			r++;
		}
		while(hd<=tl&&q[hd]<l){
			hd++;
		}
	//	cerr<<i<<' '<<l<<' '<<r<<endl;
		if(l==r){
			if(now+mn[l]>=0){
				printf("%lld\n",i);
				return 0;
			}
		}else{
			if(now+s[q[hd]]-s[l-1]>=0){
				printf("%lld\n",i);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}

/*
3 3 3 9 10 6 5
1 0
5 1
10 1


*/