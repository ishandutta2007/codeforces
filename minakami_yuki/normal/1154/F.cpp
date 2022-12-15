#include<iostream>
#include<algorithm>
#include<cstdio>
#define LL long long
using namespace std;
const int N=2e5+10;
const LL inf=1e15;
int n,m,K;
int a[N];
LL s[N];
int c[N];
LL f[N];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
//	for(int i=1;i<=n;++i) cout<<a[i]<<" ";cout<<endl;
	int l,r;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&l,&r);
		c[l]=max(c[l],r);
	}
//	for(int i=1;i<=K;++i) cout<<s[i]<<" ";cout<<endl;
//	for(int i=1;i<=K;++i) cout<<c[i]<<" ";cout<<endl;
	for(int i=1;i<=K;++i){
		f[i]=inf;
		for(int j=1;j<=i;++j){
			f[i]=min(f[i],f[i-j]+s[i]-s[i-(j-c[j])]);
		}
	}
	printf("%I64d\n",f[K]);
	return 0;
}