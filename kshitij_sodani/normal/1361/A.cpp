#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
int n,m;
int it[500001];
int tt[500001];
vector<int> adj[500001];

map<pair<int,int>,int> xx;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int aa,bb;
	for(int i=0;i<m;i++){
		cin>>aa>>bb;
		aa-=1;
		bb-=1;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	queue<int> ss;
	vector<int> ord;
	for(int i=0;i<n;i++){
		cin>>it[i];
		tt[i]=it[i];
		it[i]--;
		if(it[i]==0){
			ss.push(i);
		}
	}
	int st=0;
	while(ss.size()){
		int x=ss.front();
		ss.pop();
		ord.pb(x);
		for(auto j:adj[x]){
			if(tt[j]>tt[x]){
				if(xx.find({j,tt[x]})==xx.end()){
					it[j]--;
					if(it[j]==0){
						ss.push(j);
					}
					xx[{j,tt[x]}]=1;
				}

			}
			else if(tt[j]==tt[x]){
				st=1;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(it[i]<0 or it[i]>0){
			st=1;
		}
	}
	if(st==1){
		cout<<-1<<endl;
	}
	else{
		for(auto j:ord){
			cout<<j+1<<" ";
		}
		cout<<endl;
	}





 
 
 
	return 0;
}