//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[2021];
vector<int> cur;
void apply(int x){
	for(int i=0;i<x/2;i++){
		swap(cur[i],cur[x-i-1]);
	}
}
int find(int x){
	for(int i=0;i<cur.size();i++){
		if(cur[i]==x){
			return i;
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int st=1;
		cur.clear();
		for(int i=0;i<n;i++){
			cin>>it[i];
			it[i]--;
			cur.pb(it[i]);
			if((it[i]%2)!=(i%2)){
				st=0;
			}
		}
		if(st==0){
			cout<<-1<<endl;
			continue;
		}
		vector<int> ans;
		while(cur.size()>1){
			int x=cur.size()-2;
			int ind=find(x+1);
			ans.pb(ind+1);
			apply(ind+1);

			ind=find(x)-1;
			ans.pb(ind+1);
			apply(ind+1);

			ind=find(x)+1;
			ans.pb(ind+1);
			apply(ind+1);

		/*	for(auto j:cur){
				cout<<j<<",";
			}
			cout<<endl;*/
			ans.pb(3);
			apply(3);

			ans.pb(cur.size());
			apply(cur.size());

			cur.pop_back();
			cur.pop_back();
		/*	for(auto j:cur){
				cout<<j<<",";
			}
			cout<<endl;*/
		}
		cout<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j<<" ";
		}
		cout<<endl;;
	}



 
 
 
	return 0;
}