/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long ll;
inline void Fail(){printf("0");exit(0);}

const int maxn=200005;
const int maxm=1000005;
const int mod=1e9+7;
int n,ans;
int cnt[maxm],mo[maxm],t2[maxn];
 
int main(){
	t2[0]=1;
	REP(i,200000)t2[i]=2LL*t2[i-1]%mod;
	scanf("%d",&n);
	rep(i,n){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	mo[1]=1;
	REP(i,1000000){
		for(int j=i+i;j<=1000000;j+=i)
		mo[j]-=mo[i],cnt[i]+=cnt[j];
	}
	for(int i=2;i<=1000000;i++){
		int cur=0;
		for(int j=i;j<=1000000;j+=i)
		if(cnt[j]){
			cur+=1LL*mo[j/i]*cnt[j]%mod*t2[cnt[j]-1]%mod;
			if(cur>=mod)cur-=mod;
			if(cur<=-mod)cur+=mod;
		}
		ans=(ans + 1LL*i*cur % mod)%mod;
	}
	printf("%d",ans);
	return 0;
}