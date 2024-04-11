#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define a first
#define b second
#define pb push_back
llo n,m;
llo aa[1001][1001];
llo bb[1001][1001];
llo dist[1001][1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m,t;
	cin>>n>>m>>t;
	char s;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<m;j++){
			cin>>s;
			if(s=='0'){
				aa[i][j]=0;
			}
			else{
				aa[i][j]=1;
			}
			bb[i][j]=aa[i][j];
		}
	}
	queue<pair<llo,llo>> cc;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<m;j++){
			llo st=0;
			if(i>0){
				if(aa[i-1][j]==aa[i][j]){
					st=1;
				}
			}
			if(i<n-1){
				if(aa[i+1][j]==aa[i][j]){
					st=1;
				}
			}
			if(j>0){
				if(aa[i][j-1]==aa[i][j]){
					st=1;
				}
			}
			if(j<m-1){
				if(aa[i][j+1]==aa[i][j]){
					st=1;
				}
			}
			if(st){
				dist[i][j]=1;
				cc.push({i,j});
			}
			else{
				dist[i][j]=-1;
			}
		}
	}
	while(cc.size()){
		pair<llo,llo> x=cc.front();
		cc.pop();
		for(llo i=-1;i<2;i+=1){
			for(llo j=-1;j<2;j+=1){
				if(i!=0 and j!=0){
					continue;
				}
				pair<llo,llo> y={x.a+i,x.b+j};
				if(y.a<0 or y.b<0 or y.a>=n or y.b>=m){
					continue;
				}
				if(dist[y.a][y.b]==-1 or dist[y.a][y.b]>dist[x.a][x.b]+1){
					dist[y.a][y.b]=dist[x.a][x.b]+1;
					bb[y.a][y.b]=bb[x.a][x.b];

			//		cout<<y.a<<","<<y.b<<","<<x.a<<","<<x.b<<endl;
					cc.push(y);
				}
			}
		}
	}
	while(t--){
		llo i,j,p;
		cin>>i>>j>>p;
		i-=1;
		j-=1;
	//	cout<<dist[i][j]<<endl;
		if(dist[i][j]<=p and dist[i][j]!=-1){
			llo ko=((p)%2);
			if(ko%2==1){
				cout<<1-bb[i][j]<<endl;
			}
			else{
				cout<<bb[i][j]<<endl;
			}
			continue;
		}
		cout<<aa[i][j]<<endl;
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/

	return 0;
}