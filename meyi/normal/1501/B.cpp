#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],f[maxn],n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		memset(f,0,sizeof f);
		for(ri i=n;i;--i)++f[i],--f[max(i-a[i],0)];
		for(ri i=n-1;i;--i)f[i]+=f[i+1];
		for(ri i=1;i<=n;++i)printf("%d ",(bool)f[i]);
		puts("");
	}
}