#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int t;
int it[1000001];
int vis[1000001];
vector<int> pre[1000001];
int vis2[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	for(int i=1;i<=1e6;i++){
		for(int j=i;j<=1e6;j+=i){
			pre[j].pb(i);
		}
	}
	while(t--){
		int n,c;
		cin>>n>>c;
		for(int j=0;j<=c;j++){
			vis[j]=0;
			vis2[j]=0;
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
			vis[it[i]]=1;
		}
		if(vis[1]==0){
			cout<<"No"<<endl;
			continue;
		}
		string ans="Yes";
		int su=0;
		for(int j=2;j<=c;j++){
			for(auto i:pre[j]){
				if(i<j){
				
					if(vis2[i]==1){
						vis2[i]=0;
						su--;
					}
					if(vis[i]==1){

						if(vis[j/i]==0){
							if(vis2[i]==0){
								vis2[i]=1;
								su++;
							}
						}
					}
				}
			}
			if(vis[j]==1 and su>0){
				ans="No";
			}
		}
		cout<<ans<<endl;
	}






	return 0;
}