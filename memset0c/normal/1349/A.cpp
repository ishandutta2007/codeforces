#include<bits/stdc++.h>
#include <cstdlib>
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
const int N=2e5+10;
int n,a[N];
std::vector<int> f[N];
void split(int n){
	for(int i=2;i*i<=n;i++)if(n%i==0){
		int cnt=0;
		while(n%i==0)cnt++,n/=i;
		f[i].push_back(cnt);
	}
	if(n!=1)f[n].push_back(1);
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		split(a[i]);
	}
	long long ans=1;
	for(int i=1;i<=200000;i++)if(f[i].size()>=n-2){
		while(f[i].size()<n)f[i].push_back(0);
		std::sort(f[i].begin(),f[i].end());
		int x=f[i][1];
		while(x--){
			ans=ans*i;
		}
	}
	printf("%lld\n",ans);
}