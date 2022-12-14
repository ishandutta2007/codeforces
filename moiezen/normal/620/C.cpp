#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 300005
using namespace std;
int n,i,j,k;
int a[N];
int m;
int l[N],r[N];
map<int,int> f;
int main(){
	scanf("%d",&n);
	rpt(i,1,n) scanf("%d",&a[i]);
	m=0;i=1;
	while(i<=n){
		j=i;
		while(j<=n&&f[a[j]]==0) f[a[j++]]=1;
		if(j<=n){
			 l[++m]=i;r[m]=j;
			 rpt(k,i,j) f[a[k]]=0;
			 i=j+1;
		}
		else r[m]=n,i=n+1;
	}
	if(m){
		printf("%d\n",m);
		rpt(i,1,m) printf("%d %d\n",l[i],r[i]);
	}
	else printf("-1\n");
}