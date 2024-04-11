#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,k,a[MAXN],b[MAXN],c[MAXN];
int Calc(int l,int r){
	return b[r]-b[l-1]-c[l]-c[r]+1;
}
int ans;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++){
			if(i>1&&i<n&&a[i]>a[i-1]&&a[i]>a[i+1]) c[i]=1;
			else c[i]=0;
			b[i]=b[i-1]+c[i];
		}
		ans=1;
		for(int i=1; i+k-1<=n; i++)
			if(Calc(i,i+k-1)>Calc(ans,ans+k-1)) ans=i;
		printf("%d %d\n",Calc(ans,ans+k-1),ans);
	}
	return 0;
}