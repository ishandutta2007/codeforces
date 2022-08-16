//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo t;
llo it[200001];
llo par(llo x){
	for(llo i=0;i<33;i++){
		if((1LL<<i)>=x){
			if((1LL<<i)-x<x){
				return (1LL<<i)-x;
			}
		}
	}
	return 0;
}
vector<llo> pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	map<llo,llo> ss;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		llo cur=it[i];
		while(true){
			pre[i].pb(cur);
			if(cur==0){
				break;
			}
			cur=par(cur);
		}
		reverse(pre[i].begin(),pre[i].end());
	}
	pair<llo,llo> ma={0,0};
	for(llo i=1;i<n;i++){
		llo cot=1e9;
		for(llo j=0;j<pre[i].size();j++){
			if(j>=pre[0].size()){
				continue;
			}
			if(pre[i][j]==pre[0][j]){
				cot=min(cot,(llo)pre[i].size()+(llo)pre[0].size()-j-j-2);
			}
		}
		ma=max(ma,{cot,i});
	}
	llo x=ma.b;
	ma={0,x};
	for(llo i=0;i<n;i++){
		llo cot=1e9;
		for(llo j=0;j<pre[i].size();j++){
			if(j>=pre[x].size()){
				continue;
			}
			if(pre[i][j]==pre[x][j]){
				cot=min(cot,(llo)pre[i].size()+(llo)pre[x].size()-j-j-2);
			}
		}
		ma=max(ma,{cot,i});
	}
	cout<<x+1<<" "<<ma.b+1<<" "<<ma.a<<endl;



	return 0;
}