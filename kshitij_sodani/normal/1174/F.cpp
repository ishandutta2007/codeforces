//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
vector<int> adj[200001];
int sss[200001];
int n;
int it[200001];
void dfs(int no,int par=-1){
	sss[no]=it[no];
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			sss[no]+=sss[j];
		}
	}
}
int find(int no,int par=-1){
	for(auto j:adj[no]){
		if(sss[j]>sss[no]/2 and j!=par){
			return find(j,no);
		}
	}
	return no;
}
/*void rec(int no){
	dfs(no);
	no=find(no);
	cout<<"d "<<no<<endl;
	int aa;
	cin>>aa;
	if(aa==0){
		cout<<"! "<<no<<endl;
		return;
	}

	cout<<"s "<<no<<endl;
	cin>>aa;
	adj[aa].erase(no);
	rec(aa);
}*/
vector<int> ss;
set<int> cur;
int cot=0;
void dfs4(int no,int par=-1,int levv=0){
	if(levv==cot and it[no]==1){
		ss.pb(no);
		//cout<<no<<":"<<endl;
	}
	for(auto j:adj[no]){
		if(j!=par){
			dfs4(j,no,levv+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	for(int i=1;i<=n;i++){
		it[i]=1;
	}
	cout<<"d "<<1<<endl;
	
	cin>>cot;
	if(cot==0){
		cout<<"! "<<1<<endl;
		return 0;
	}
	dfs4(1);
	for(auto j:ss){
		cur.insert(j);
	}
	int co=1;
	while(cur.size()>1){
		for(int i=1;i<=n;i++){
			it[i]=0;
		}
		for(auto j:cur){
			it[j]=1;
		}
		dfs(1);
		int cen=find(1);
		cout<<"d "<<cen<<endl;
		cin>>cot;

		if(cot==0){
			cout<<"! "<<cen<<endl;
			return 0;
		}
		ss.clear();
		dfs4(cen);
		int xx=cur.size();
		cur.clear();
		for(auto j:ss){
			cur.insert(j);
		}
		co+=1;
		if(cur.size()<=((xx+1)/2)){
			continue;
		}
		cout<<"s "<<cen<<endl;
		co+=1;
	/*	if(co>36){
			while(true){
				continue;
			}
		}*/
		cot-=1;
		int x;
		cin>>x;
		ss.clear();
		dfs4(x);
		cur.clear();
		for(auto j:ss){
			cur.insert(j);
		}
		if(cur.size()>((xx+1)/2)){
			while(true){
				continue;
			}
		}


	}
	cout<<"! "<<(*(cur.begin()))<<endl;



 
	return 0;
}