//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


llo n,k;
vector<llo> pre[41];
llo vis[41];
vector<llo> pre2[41];
vector<llo> pre3[41];
llo st=1;

void dfs(llo aa,int ind){
	/*if(ind==1){
		cout<<aa<<":"<<ind<<endl;
	}*/

	if(ind==k){
		
		if((1LL<<n)!=((1LL<<__builtin_ctzll(aa))+aa)){
			if(aa==0){
				return;
			}
			cout<<"REJECTED"<<endl;
			st=0;
			exit(0);
		}
		/*for(auto i:pre3[k]){
			if(i==aa){
				return;
			}
		}
		st=0;*/
		return;
	}
	else{
			int xx=__builtin_popcountll(aa&pre3[ind].back());
			int x=pre[ind].size();
		for(int i=0;i<=pre2[ind].size();i++){
		/*	llo cur=aa;

			for(llo j=0;j<i;j++){
				cur=(cur+(1LL<<pre2[ind][j]));
			}
			*/
			/*llo co=0;
			for(auto j:pre[ind]){
				if(((1LL<<j))&cur){
					co++;
				}
			}*/
			//llo cur=aa;
			
			//cur|=(pre3[ind].back()-pre3[ind][x-xx-i]);
			//cur-=(cur&(pre3[ind][x-xx-i]));
			dfs((aa|(pre3[ind].back()-pre3[ind][x-xx-i]))-(aa&(pre3[ind][x-xx-i])),ind+1);

			/*for(llo j=0;j<x-co;j++){
				cur-=(cur&(1LL<<pre[ind][j]));
			}
			for(llo j=x-co;j<pre[ind].size();j++){
				cur|=(1LL<<pre[ind][j]);
			}*/
			/*if(ind==0){
				cout<<aa<<":"<<co<<":"<<cur<<endl;
			}*/
			//cout<<aa<<":"<<cur<<"::"<<ind<<endl;
		//	cout<<co<<endl;
			/*if(ind==2){
				return;
			}*/
			//dfs(cur,ind+1);
			//return;
		}



	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(llo i=0;i<k;i++){
		llo x;
		cin>>x;
		pre3[i].pb(0);
		for(llo j=0;j<x;j++){
			llo aa;
			cin>>aa;
			aa--;
			if(vis[aa]==0){
				pre2[i].pb(aa);

				//cout<<aa<<",";
			}
			pre3[i].pb(pre3[i].back()+(1LL<<aa));
			vis[aa]=1;
			pre[i].pb(aa);
		}
		//cout<<endl;
	}
	pre3[k].pb(0);
	for(int i=n-1;i>=0;i--){
		pre3[k].pb(pre3[k].back()+(1LL<<i));
	}
	if(n==1){
		cout<<"ACCEPTED"<<endl;
		return 0;
	}
		for(llo i=0;i<n;i++){
			if(vis[i]==0){
				cout<<"REJECTED"<<endl;
				return 0;
			}
		}
		if(k>1){
			if(pre2[k-1].size()){
				if(pre[k-1].size()<n){
					cout<<"REJECTED"<<endl;
						return 0;
				}
			}
		}
		dfs(0,0);
			if(st==1){
				cout<<"ACCEPTED"<<endl;
			}
			else{
				cout<<"REJECTED"<<endl;
			}





 
	return 0;
}