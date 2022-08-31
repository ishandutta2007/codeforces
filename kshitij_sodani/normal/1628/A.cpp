//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int it[200001];
int co[200001];
set<int> pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> ss;
		vector<int> zz;
		for(int i=0;i<=n;i++){
			co[i]=0;
			pre[i].clear();
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
			co[it[i]]++;
			pre[it[i]].insert(i);
		}
		int ind=0;
		set<int> cur;
		int me;
		for(int j=0;j<=n;j++){
			if(co[j]==0){
				me=j;
				break;
			}
			else{
				cur.insert(*pre[j].begin());
			}

		}

		while(ind<n){
			ss.pb(me);
			if(me==0){
				ind++;
				continue;
			}
			auto j=cur.end();
			j--;
			int x=(*j);
			
			int me2=me;
			for(int j=ind;j<=x;j++){
				co[it[j]]--;
				if(co[it[j]]==0){
					me=min(me,it[j]);
				}
				pre[it[j]].erase(j);
			}
			cur.clear();
			for(int j=0;j<=me;j++){
				cur.insert(*(pre[j].begin()));
			}
			ind=x+1;
		}

		cout<<ss.size()<<endl;
		for(auto j:ss){
			cout<<j<<" ";
		}
		cout<<endl;

	}




 
	return 0;
}