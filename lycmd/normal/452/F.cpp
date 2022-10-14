#include<bits/stdc++.h>
using namespace std;
int const N=333333;
int n,flg,a[N],ord[N];
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c))c=getchar(),f=(c==45?-f:f);
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
} 
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),ord[a[i]]=i;
	for(int i=2;i<n&&!flg;i++)
		for(int j=max(1,i-5);j<i&&!flg;j++){
			int k=2*a[i]-a[j];
			flg|=(k>0&&k<=n&&ord[k]>i);
		}
	for(int i=2;i<n&&!flg;i++)
		for(int j=i+1;j<=min(n,i+5)&&!flg;j++){
			int k=2*a[i]-a[j];
			flg|=(k>0&&k<=n&&ord[k]<i);
		}
	puts(flg?"YES":"NO");
}