#include<cstdio>
#include<iostream>
using namespace std;
const int N = 500 + 5;
int n,m,a[N],b[N],f[N],g[N];
void Print(int x){
	if(!x)return;
	Print(g[x]); 
	printf("%d ",b[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",b+i);
	for(int i=1,t=0;i<=n;i++,t=0){
		for(int j=1;j<=m;j++){
			if(a[i] == b[j]){
				f[j] = f[t] + 1;
				g[j] = t;
			}
			if(b[j] < a[i] && f[t] < f[j])t = j;
		} 
	} 
	int ans = 0, maxi;
	for(int i=1;i<=m;i++)if(f[i] > ans)ans = f[i],maxi = i;
	printf("%d\n",ans); 
	Print(maxi);
	return 0;
}