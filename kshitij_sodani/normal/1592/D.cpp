//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n;
vector<int> adj[1001];
vector<pair<int,int>> ss;
void dfs(int no,int par=-1){
	for(auto j:adj[no]){
		if(j!=par){
			ss.pb({j,no});
			dfs(j,no);
		}
	}
}
int check(int aa){
	set<int> xx;
	for(int j=0;j<=aa;j++){
		xx.insert(ss[j].a);
		xx.insert(ss[j].b);
	}
	cout<<"? "<<xx.size()<<" ";
	for(auto j:xx){
		cout<<j+1<<" ";
	}
	cout<<endl;
	int x;
	cin>>x;
	return x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	int x=check(n-2);
	//cout<<x<<"::"<<endl;
	int low=n-2;
	for(int j=19;j>=0;j--){
		if((low-(1<<j))>=0){
			if(check(low-(1<<j))==x){
				low-=(1<<j);
			}
		}
	}
	cout<<"! "<<ss[low].a+1<<" "<<ss[low].b+1<<endl;




 
 
 
	return 0;
}