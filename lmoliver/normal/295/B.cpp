#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=505;
LL d[N][N];
int x[N];
bool ok[N]={false};
LL ans[N]={0};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	for(int t=n;t>=1;t--){
		int k=x[t];
		ok[k]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&i!=k&&k!=j){
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(ok[i]&&ok[j])ans[t]+=d[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}