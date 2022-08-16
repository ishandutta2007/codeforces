//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin>>q;
	int cur=0;
	set<pair<int,int>> ss;
	queue<pair<int,int>> tt;
	map<int,int> vis;
	for(int i=0;i<q;i++){
		int t;
		cin>>t;
		if(t==1){
			int aa;
			cin>>aa;
			cur++;
			ss.insert({-aa,cur});
			tt.push({-aa,cur});
		}
		else if(t==2){
			while(tt.size()){
				pair<int,int> no=tt.front();
				tt.pop();
				if(vis.find(no.b)!=vis.end()){
					continue;
				}
				vis[no.b]=1;
				cout<<no.b<<" ";
				break;
			}
		}
		else{
			while(ss.size()){
				pair<int,int> no=*ss.begin();
				ss.erase(no);
				if(vis.find(no.b)!=vis.end()){
					continue;
				}
				vis[no.b]=1;
				cout<<no.b<<" ";
				break;
			}
		}
	}
	cout<<endl;


 
	return 0;
}