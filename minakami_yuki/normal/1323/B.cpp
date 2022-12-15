#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=1e5+10;
int n,m,k;
int a[N],b[N];
LL c[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i) scanf("%d",&b[i]);
	LL s=0;
	int t,x;
	LL v;
	for(int i=1;i<=m;++i){
		if(k%i==0){
			t=k/i;v=0;x=0;
			for(int j=1;j<=n;++j){
				if(a[j]==1){
					++x;
					if(x>=t) ++v;
				}
				else x=0;
			}
			s=s+v;
		}
		//cout<<s<<endl;
		c[i]=c[i-1]+s;
		//cout<<i<<" "<<c[i]<<endl;
	}
	LL ans=0;x=0;
	for(int i=1;i<=m;++i){
		if(b[i]==1) ++x;
		else{
			ans=ans+c[x];
			x=0;
		}
	}
	ans=ans+c[x];
	printf("%I64d\n",ans);
	return 0;
}