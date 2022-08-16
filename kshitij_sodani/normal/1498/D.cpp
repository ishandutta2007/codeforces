//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'




llo n,m;
llo ans[1000001];
llo vis2[1000001];
llo vis[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=1;i<=m;i++){
		ans[i]=-1;
	}
	vis[0]=1;

	for(llo i=1;i<=n;i++){
		llo t,x,y;
		cin>>t>>x>>y;
		for(llo j=0;j<=m;j++){
			vis2[j]=0;
		}
		if(t==2){
			for(llo j=0;j<=m;j++){
				if(vis[j]==1){
					llo cur=j;
					for(llo ii=0;ii<y;ii++){
						llo cur2=((cur*x+99999)/100000);
						if(cur2>m){
							break;
						}
						if(vis[cur2]==1){
							break;
						}
						vis2[cur2]=1;
						cur=cur2;
					}
				}
			}
		}
		else{
			for(llo j=0;j<=m;j++){
				if(vis[j]==1){
					llo cur=j;
					llo le=y;
					for(llo ii=0;ii<y;ii++){
						llo cur2=((cur*100000+x+99999)/100000);
						if(cur2>m){
							break;
						}
						if(vis[cur2]==1){
							break;
						}
						vis2[cur2]=1;
						cur=cur2;
					}
				}
			}

		}


		for(llo j=0;j<=m;j++){
			if(vis[j]==0 and vis2[j]==1){
				vis[j]=1;
				ans[j]=i;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;







 
	return 0;
}