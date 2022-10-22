#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

bool f = true;

vector<int> dfs(vector<vector<int>> &E,vector<int> &C,int now){
	vector<int> ret;
	
	for(int i=0;i<E[now].size();i++){
		vector<int> K = dfs(E,C,E[now][i]);
		for(int j=0;j<K.size();j++)ret.push_back(K[j]);
	}
	
	if(ret.size() < C[now]){
		f = false;
		return ret;
	}
	
	ret.insert(ret.begin() + C[now],now);
	/*
	cout<<C[now]<<endl;
	for(int i=0;i<ret.size();i++){
			if(i!=0)cout<<' ';
			cout<<ret[i];
		}
		cout<<endl<<endl;;
		*/
	return ret;
	
}

int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>> E(n,vector<int>());
	
	int p;
	vector<int> C(n);
	
	for(int i=0;i<n;i++){
		int P;
		cin>>P>>C[i];
		
		if(P==0)p = i;
		else{
			E[P-1].push_back(i);
		}
	}
	
	vector<int> ret = dfs(E,C,p);
	
	if(f==false){
		cout<<"NO"<<endl;
	}
	else{
		vector<int> ans(n);
		for(int i=0;i<n;i++){
			ans[ret[i]] = i+1;
		}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
	}
	
    return 0;
}