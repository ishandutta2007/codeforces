#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n,m;
int aa[200001];
pair<int,int> it[200001];
set<int> ind[200001];
int vis[200001];
int vis2[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>aa[i];
	}
	for(int i=0;i<m;i++){
		cin>>it[i].a>>it[i].b;
		ind[it[i].a-1].insert(i);
		ind[it[i].b-1].insert(i);
		it[i].a--;
		it[i].b--;
	}
	vector<int> ans;
	queue<int> ss;

	for(int i=0;i<m;i++){

		if(ind[it[i].a].size()<=aa[it[i].a]){
			if(vis[it[i].a]==0){
				vis[it[i].a]=1;
				ss.push(it[i].a);
			}
		}
		if(ind[it[i].b].size()<=aa[it[i].b]){
			if(vis[it[i].b]==0){
				vis[it[i].b]=1;
				ss.push(it[i].b);
			}
		}
	}
	while(ss.size()){
		int x=ss.front();
		ss.pop();
	//	cout<<x<<endl;
		for(auto j:ind[x]){
			if(vis2[j]==0){
				ans.pb(j);
			}
			vis2[j]=1;
			if(x==it[j].a){
				ind[it[j].b].erase(j);
				if(vis[it[j].b]==0){
					if(ind[it[j].b].size()<=aa[it[j].b]){
						vis[it[j].b]=1;
						ss.push(it[j].b);
					}
				}
			}
			else{
				ind[it[j].a].erase(j);
				if(vis[it[j].a]==0){
					if(ind[it[j].a].size()<=aa[it[j].a]){
						vis[it[j].a]=1;
						ss.push(it[j].a);
					}
				}
			}
		}
	}
	reverse(ans.begin(),ans.end());
	if(ans.size()<m){
		cout<<"DEAD"<<endl;
	}
	else{
		cout<<"ALIVE"<<endl;
		for(auto j:ans){
			cout<<j+1<<" ";
		}
		cout<<endl;
	}





	return 0;
}