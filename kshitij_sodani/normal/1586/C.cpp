//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<int> it[1000001];
int pre[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='.'){
				it[i].pb(1);
			}
			else{
				it[i].pb(0);
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(it[i][j]==1 and it[i-1][j]==0 and it[i][j-1]==0){
				pre[j+1]+=1;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(it[i][j]==0 and it[i-1][j]==0 and it[i][j-1]==0){
				pre[j+1]+=1;
			}
		}
	}
	for(int j=1;j<=m;j++){
		pre[j]+=pre[j-1];
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		//see sum in L+1 to r
		if(l==r){
			cout<<"YES"<<endl;
		}
		else{
			if(pre[r+1]-pre[l+1]==0){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}

	}
 
 
 

 
	return 0;
}