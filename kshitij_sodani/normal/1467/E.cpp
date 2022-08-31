
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
int n;
vector<int> adj[200001];
int it[200001];
int st[200001];
int endd[200001];
int co=0;
int par[200001];
void dfs(int no,int par2=-1){
	st[no]=co;
	co++;
	par[no]=par2;
	for(auto j:adj[no]){
		if(j!=par2){
			dfs(j,no);
		}
	}
	endd[no]=co-1;
}
int tree[200001];
void u(int i,int j){
	//cout<<i<<",,"<<j<<endl;
	while(i<200001){
		tree[i]+=j;
		i+=(i&-i);
	}
}
int ss(int i){
	int su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<int,int>> xx;
	for(int i=0;i<n;i++){
		cin>>it[i];
		xx.pb({it[i],i});
	}
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
 
	sort(xx.begin(),xx.end());
	int ind=0;
 
	while(ind<n){
		int ind2=ind;
		set<int> ss;
		for(int j=ind2+1;j<n;j++){
			if(xx[j].a==xx[ind2].a){
				ind++;
			}
			else{
				break;
			}
		}
		for(int j=ind2;j<=ind;j++){
			ss.insert(st[xx[j].b]);
			//cout<<xx[j].b<<":";
		}
	//	cout<<endl;
 
		for(int j=ind2;j<=ind;j++){
			int cur=xx[j].b;
			for(auto i:adj[cur]){
				if(i==par[cur]){
					//cout<<i<<"::"<<cur<<endl;
					int kk=0;
					if(*ss.begin()<st[cur]){
						kk=1;
					}
					auto j=ss.upper_bound(endd[cur]);
					if(j!=ss.end()){
						kk=1;
					}
					//cout<<kk<<endl;
					if(kk==1){
 
						u(st[cur]+1,1);
						u(endd[cur]+2,-1);
					}
				}
				else{
					auto jj=ss.lower_bound(st[i]);
					if(jj==ss.end()){
						continue;
					}
					if(*jj<=endd[i]){
						u(1,1);
						u(st[i]+1,-1);
						u(endd[i]+2,1);
					}
				}
			}
		}
 
		ind++;
	}
 
 
	int ans=0;
	for(int i=1;i<=n;i++){
		if(ss(i)==0){
			ans+=1;
		}
	}
	cout<<ans<<endl;
 
 
 
 
 
 
	return 0;
}