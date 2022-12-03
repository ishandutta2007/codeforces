#include<bits/stdc++.h>
using namespace std;
const int M=4e5+9; 
int n,ans=0;
int a[M],f[M],g[M];
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i)scanf("%d%d",&x,&y),a[x]=y,a[y]=x,f[x]=f[y]=(x<y);
	for(int i=1,j=1,x=2*n+1,y=2*n+1;i<=n;++i){
		if(a[i]>y||a[i]<=n)return puts("-1"),0;
		a[i]<x?(x=a[i],g[i]=0):(y=a[i],g[i]=1);
		if(x==2*n-i+1){
			int cnt1=0,cnt2=0;
			while(j<=i)(g[j]==f[j]?cnt1++:cnt2++),++j;
			ans+=min(cnt1,cnt2);
		}
	}
	printf("%d\n",ans);
	return 0;
}