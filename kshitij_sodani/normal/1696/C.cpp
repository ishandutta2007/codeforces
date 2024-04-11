#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[100001];
llo tt[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		vector<pair<llo,llo>> cur;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			llo aa=1;
			while(it[i]%m==0){
				it[i]/=m;
				aa*=m;
			}
			cur.pb({it[i],aa});
		}
		llo k;
		cin>>k;
		vector<pair<llo,llo>> cur2;
		for(llo i=0;i<k;i++){
			cin>>it[i];
			llo aa=1;
			while(it[i]%m==0){
				it[i]/=m;
				aa*=m;
			}
			cur2.pb({it[i],aa});
		}
		vector<pair<llo,llo>> cur3;
		for(auto j:cur){
			if(cur3.size()==0){
				cur3.pb(j);
				continue;
			}
			if(cur3.back().a==j.a){
				cur3[cur3.size()-1].b+=j.b;
				continue;
			}
			cur3.pb(j);
		}
		cur=cur3;
		cur3.clear();
		for(auto j:cur2){
			if(cur3.size()==0){
				cur3.pb(j);
				continue;
			}
			if(cur3.back().a==j.a){
				cur3[cur3.size()-1].b+=j.b;
				continue;
			}
			cur3.pb(j);
		}
		cur2=cur3;
		if(cur.size()!=cur2.size()){
			cout<<"No"<<endl;
		}
		else{
			string ans="Yes";
			for(llo i=0;i<cur.size();i++){
				if(cur[i].a!=cur2[i].a or cur[i].b!=cur2[i].b){
					ans="No";
				}
			}
			cout<<ans<<endl;
		}


		
	}





	return 0;
}