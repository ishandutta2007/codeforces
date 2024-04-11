
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

llo it[10001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo su=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			su+=it[i];
		}
		if(su%n!=0){
			cout<<-1<<endl;
			continue;
		}
		vector<pair<pair<llo,llo>,llo>> ans;
		for(llo i=1;i<n;i++){
			llo x=it[i]%(i+1);
			x=(i+1-x)%(i+1);
			ans.pb({{1,i+1},x});
			it[i]+=x;
			it[0]-=x;
			ans.pb({{i+1,1},it[i]/(i+1)});
			it[0]+=it[i];
			it[i]=0;

		}
		llo xx=su/n;
		for(llo i=1;i<n;i++){
			ans.pb({{1,i+1},xx});
		}
		cout<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j.a.a<<" "<<j.a.b<<" "<<j.b<<endl;
		}



	




	}
	









	return 0;
}