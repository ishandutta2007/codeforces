#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
char S[N],T[N];
int f1[N],f2[N],ans;
int main(){
	scanf("%d%d",&n,&m);
	cin>>S;
	cin>>T;
	for(int i=1;i<=m;i++){
		for(int o=f1[i-1]+1;o<=n;o++){
			if(S[o-1]==T[i-1]){
				f1[i]=o;
				break;
			}
		}
	}
	f2[m+1]=n+1;
	for(int i=m;i>=1;i--){
		for(int o=f2[i+1]-1;o>=1;o--){
			if(S[o-1]==T[i-1]){
				f2[i]=o;
				break;
			}
		}
	}
	for(int i=2;i<=m;i++){
		ans=max(ans,f2[i]-f1[i-1]);
	}
	printf("%d\n",ans);
	return 0;
}