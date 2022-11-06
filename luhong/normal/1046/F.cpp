#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define MN 40002
#define MM 5000001
#define ll long long
#define ld long double
#define inf 0x7fffffff
#define clz 1000000007
#define ers(arr,val) memset(arr,val,sizeof(arr));
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repd(i,b,a) for(int i=(b);i>=(a);i--)
#define repe(i,u) for(int i=h[u];i;i=e[i].nx)
using namespace std;
int n,a[200001],x,f;
ll ans=0;
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	scanf("%d%d",&x,&f);
	rep(i,1,n){
		ans+=1ll*(a[i]/(x+f));
		if(a[i]%(x+f)>x&&a[i]>x) ans++;
	}
	printf("%I64d",ans*f);
	return 0;
}