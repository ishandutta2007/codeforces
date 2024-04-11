#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int m,n,k,t;
int a[MAXN],x[MAXN],y[MAXN],d[MAXN];
int rsum[MAXN];
inline bool Check(int v){
	memset(rsum,0,sizeof(rsum));
	for(int i=1;i<=k;i++)
		if(d[i]>v) rsum[x[i]]++,rsum[y[i]+1]--;
	int res=1;
	for(int i=1;i<=n;i++){
		rsum[i]+=rsum[i-1];
		res++;
		if(rsum[i]) res+=2;//,printf("ff %d\n",i);
	}
	return res<=t;
}
int main(){
	scanf("%d%d%d%d",&m,&n,&k,&t);
	for(int i=1;i<=m;i++)
		scanf("%d",a+i);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d",x+i,y+i,d+i);
	sort(a+1,a+m+1);
//	Check(a[1]);return 0;
	int l=0,r=m;
	while(l<r){
		int mid=l+r+1>>1;
		if(Check(a[m-mid+1])) l=mid;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}