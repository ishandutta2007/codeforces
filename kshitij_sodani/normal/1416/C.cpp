 
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
 
int it[300001];
vector<vector<int>> pre;
int cur=0;
vector<vector<int>> adj;
vector<vector<int>> pp;
void insert(int ii,int jj){
	int cot=0;
	for(int j=29;j>=0;j--){
		int ss=0;
		if((1<<j)&ii){
			ss=1;
		}
		if(pre[cot][ss]==0){
			cur++;
			pre[cot][ss]=cur;
			adj[cot].pb(cur);
			pre.pb({0,0});
			adj.pb({});
			pp.pb({});
		}
		pp[cot].pb(ss);
		cot=pre[cot][ss];
	}
}
llo co[30][2];
void dfs(int no,int lev=29){
	int cot[2];
	cot[0]=0;
	cot[1]=0;
	for(auto j:pp[no]){
		if(j==0){
			co[lev][0]+=cot[1];
		}
		else{
			co[lev][1]+=cot[0];
		}
		if(j==0){
			cot[0]+=1;
		}
		else{
			cot[1]+=1;
		}
	}
	for(auto j:adj[no]){
		dfs(j,lev-1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	pre.pb({0,0});
	adj.pb({});
	pp.pb({});
	for(int i=0;i<n;i++){
		cin>>it[i];
		insert(it[i],i);
	}
 
	dfs(0);
	int ans=0;
	llo ans2=0;
	for(int i=0;i<30;i++){
		if(co[i][0]<=co[i][1]){
		}
		else{
			ans+=(1<<i);
		}
		/*if(i<5){
			cout<<co[i][0]<<","<<co[i][1]<<endl;
		}*/
		ans2+=min(co[i][0],co[i][1]);
	}
	cout<<ans2<<" "<<ans<<endl;
 
 
 
 
 
 
 
	return 0;
}