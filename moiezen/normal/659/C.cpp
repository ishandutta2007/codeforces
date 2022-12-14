#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
std::map<int,int> f;
int n,m,i,j,k,ans;
int a[N];
int l[N];
int main(){
	scanf("%d%d",&n,&m);
	rpt(i,1,n) scanf("%d",&a[i]);
	f.clear();
	rpt(i,1,n) f[a[i]]=1;
	ans=0;i=0;
	while(m>0){
		i++;
		if(f[i]) continue;
		if(m<i) break;
		m-=i;ans++;l[ans]=i;
	}
	printf("%d\n",ans);
	rpt(i,1,ans) printf("%d ",l[i]);
}