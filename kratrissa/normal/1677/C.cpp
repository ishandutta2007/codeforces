#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e5+5;
int T,n,a[N],b[N],pa[N],pb[N],p[N];bool vst[N];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pa[a[i]]=i;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),pb[b[i]]=i;
	for(int i=1;i<=n;i++)p[pa[i]]=pb[i];
	fill(vst,vst+n+1,0);int cnt=0;
	for(int i=1;i<=n;i++)if(!vst[i]){
		int len=1;
		for(int j=p[i];j!=i;j=p[j])len++,vst[j]=1;
		if(len&1)cnt++;
	}
	int m=n-cnt>>1;
	printf("%lld\n",2ll*m*(n-m));
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}