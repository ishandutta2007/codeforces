//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[100001];
llo ans[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m,x;
		cin>>n>>m>>x;
		vector<pair<llo,llo>> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			ss.pb({it[i],i});
		}
		sort(ss.begin(),ss.end());
		set<pair<llo,llo>> xx;
		for(llo i=0;i<m;i++){
			xx.insert({ss[i].a,i+1});
			ans[ss[i].b]=i+1;
		}
		for(llo i=m;i<n;i++){
			pair<llo,llo> no=*xx.begin();
			xx.erase(no);
			no.a+=ss[i].a;
			ans[ss[i].b]=no.b;
			xx.insert(no);
		}
		cout<<"YES"<<endl;
		for(llo i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}










	return 0;
}