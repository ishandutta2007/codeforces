#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF (1LL<<61)
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,s,e;
ll x[5005],aa[5005],bb[5005],cc[5005],dd[5005];
void ina(ll *x){int a;fore(i,0,n)scanf("%d",&a),x[i]=a;}
ll dp[10005],dp2[100005];

ll gt(int w){
	if(w<0)return INF;
	return dp[w];
}

int main(){
	scanf("%d%d%d",&n,&s,&e);s--;e--;
	ina(x);ina(aa);ina(bb);ina(cc);ina(dd);
	if(e>s){
		swap(e,s);
		swap(aa,cc);
		swap(bb,dd);
	}
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	fore(i,1,2*n+1)dp[i]=INF;
	fore(k,1,n+1){
		ll a=aa[k-1],b=bb[k-1],c=cc[k-1],d=dd[k-1];
		fore(w,0,2*n+1){
			if(!w&&k!=n){dp2[w]=INF;continue;}
			if(k-1==s)dp2[w]=min(c+gt(w+1),d+gt(w-1));
			else if(k-1==e)dp2[w]=min(a+gt(w+1),b+gt(w-1));
			else {
				dp2[w]=min(c+a+gt(w+2),d+b+gt(w-2));
				dp2[w]=min(dp2[w],b+c+gt(w));
				if(w>1)dp2[w]=min(dp2[w],d+a+gt(w));
			}
			dp2[w]+=w*(x[k]-x[k-1]);
		}
		memcpy(dp,dp2,sizeof(dp));
	}
	cout<<dp[0]<<endl;
	return 0;
}