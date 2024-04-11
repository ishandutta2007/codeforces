#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn],f[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			f[i]=1;
			for(int j=i-1;j>=i-255&&j>=1;j--)
				if((a[i]^(j-1))>(a[j]^(i-1)))
					f[i]=max(f[i],f[j]+1);
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}