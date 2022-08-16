//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int adj[30][30];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l,r;
	cin>>l>>r;	
	for(int i=0;i<23;i++){
		for(int j=0;j<23;j++){
			adj[i][j]=-1;
		}
	}
	adj[0][1]=1;
	for(int i=2;i<=20;i++){
		adj[0][i]=1;
		for(int j=1;j<i;j++){
			adj[j][i]=(1<<(j-1));
		}
	}
	vector<int> ss;
	for(int i=0;i<20;i++){
		if((1<<i)&(r-l)){
			ss.pb(1<<i);
		}
		else{
			ss.pb(0);
		}
	}
	adj[0][21]=1;
	for(int i=1;i<=20;i++){
		if(ss[i-1]>0){
			adj[i][21]=1;
			for(int j=0;j<i-1;j++){
				adj[i][21]+=ss[j];
			}
		}
	}
	cout<<"YES"<<endl;
	if(l==1){
		vector<pair<pair<int,int>,int>> ans;
		for(int i=0;i<22;i++){
			for(int j=i+1;j<22;j++){
				if(adj[i][j]!=-1){
					ans.pb({{i,j},adj[i][j]});
				}
			}
		}
		cout<<22<<" "<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j.a.a+1<<" "<<j.a.b+1<<" "<<j.b<<endl;
		}

	}
	else{
		adj[21][22]=l-1;
		vector<pair<pair<int,int>,int>> ans;
		for(int i=0;i<23;i++){
			for(int j=i+1;j<23;j++){
				if(adj[i][j]!=-1){
					ans.pb({{i,j},adj[i][j]});
				}
			}
		}
		cout<<23<<" "<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j.a.a+1<<" "<<j.a.b+1<<" "<<j.b<<endl;
		}




	}











 
	return 0;
}