//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n,m;
int dist[601];
int vis[601];
int adj[601][601];
int cur[601];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adj[i][j]=-1;
		}
	}
	for(int i=0;i<m;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		if(adj[aa][bb]==-1){
			adj[aa][bb]=cc;
		}
		adj[aa][bb]=min(adj[aa][bb],cc);
	}
	for(int i=0;i<n;i++){
		//cout<<i<<endl;
		for(int j=0;j<n;j++){
			dist[j]=1e9+600;
			vis[j]=0;
		}
		dist[i]=0;
		for(int j=0;j<n;j++){
			int mi=1e9+600;
			int no=-1;
			for(int k=0;k<n;k++){
				if(vis[k]==0){
					if(dist[k]<mi){
						mi=dist[k];
						no=k;
					}
				}
			}
			vis[no]=1;
			//cout<<no<<":";
			for(int k=0;k<n;k++){
				cur[k]=1e9+600;;
			}
			int xx=dist[no]%n;
			//continue;
			for(int k=0;k<n;k++){
				if(adj[no][k]>=0){
					int yy=k+xx;
					if(yy>=n){
						yy-=n;
					}
					cur[yy]=min(cur[yy],adj[no][k]);
				}
			}
			//continue;
			/*for(int k=0;k,n;k++){
				cout<<cur[k]<<":":
			}
			cout<<endl;*/
			//for(int l=0;l<n;l++){
				for(int k=1;k<n;k++){
					cur[k]=min(cur[k],cur[k-1]+1);
				}
				cur[0]=min(cur[n-1]+1,cur[0]);
				for(int k=1;k<n;k++){
					cur[k]=min(cur[k],cur[k-1]+1);
				}
				cur[0]=min(cur[n-1]+1,cur[0]);
				//cur[n-1]=min(cur[n-1],cur[0]+1);
			//}
		/*	for(int k=n-2;k>=0;k--){
				cur[k]=min(cur[k],cur[k+1]+1);
			}
			cur[n-1]=min(cur[n-1],cur[0]+1);*/
			for(int k=0;k<n;k++){
				if(vis[k]==0){
					dist[k]=min(dist[k],cur[k]+dist[no]);
				}
			}

		}
		//cout<<endl;


		for(int j=0;j<n;j++){
			cout<<dist[j]<<" ";
		}
		cout<<endl;
	}









	return 0;
}