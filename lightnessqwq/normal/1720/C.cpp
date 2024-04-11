#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,m,T,ans,flg,mn;
int a[maxn][maxn];
string s;
inline void chk(int x){
	if(x>0)
		mn=min(mn,x);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),ans=0,mn=1e9;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=0;j<m;j++)
				a[i][j]=s[j]-48,ans+=a[i][j];
		}
		for(int i=1;i<n;i++)
			for(int j=0;j+1<m;j++){
				chk(a[i][j]+a[i][j+1]+a[i+1][j]),chk(a[i][j]+a[i][j+1]+a[i+1][j+1]);
				chk(a[i+1][j]+a[i+1][j+1]+a[i][j]),chk(a[i+1][j]+a[i+1][j+1]+a[i][j+1]);
			}
		if(mn==1e9)
			puts("0");
		else printf("%d\n",ans-mn+1);
	}
	return 0;
}