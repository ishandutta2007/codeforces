#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define lb long double
#define N 100005
using namespace std;

int n,k,t[27];
char a[N];

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	rep(i,1,n) t[a[i]-'A'+1]++;
	sort(t+1,t+1+26);
	ll ans=0;
	dep(i,26,1){
		if(k>=t[i]){
			ans+=(ll)t[i]*t[i];
			k-=t[i];
		}else{
			ans+=(ll)k*k;
			k=0;
		}
		if(k==0)break;
	}
	printf("%I64d\n",ans);
}