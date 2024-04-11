#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
#define ll long long
#define Mod (ll)1000000007
#define rep(i,x,y) for(int i=x;i<=y;++i)

ll N,xx,a[maxn],Max,l,x,y,sum;

ll fast(ll x,ll v){
	ll sum=1;
	for(;v;x=x*x%Mod,v>>=1)if(v&1)sum=sum*x%Mod;
	return sum;
}

int main(){
	scanf("%I64d%I64d",&N,&xx);
	rep(i,1,N) scanf("%I64d",&a[N-i+1]),sum+=a[N-i+1];
	x=sum-a[1],y=1;
	rep(i,2,N)
		if(x==sum-a[i])++y;
		else{
			while(!(y%xx)&&x!=sum-a[i]) ++x,y/=xx;
			if(x==sum-a[i]){++y;continue;}
			else break;
		}
	while(!(y%xx))++x,y/=xx;
		
	printf("%I64d\n",fast(xx,min(sum,x)));
}