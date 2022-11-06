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
int n,D,l,r,mid,sco;
int a[200001],b[200001],c[200001],d[200001],p;
bool chk(){
	p=0; rep(i,1,n) if(i!=D) c[++p]=a[i]; p=0;
	rep(i,2,n) d[++p]=b[i];
	rep(i,mid,n-1) if(c[i]+d[p--]>sco) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&D);
	l=1,r=n;
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) scanf("%d",&b[i]);
	while(l<r){
		mid=(l+r)>>1;
		sco=a[D]+b[1];
		if(chk()) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}