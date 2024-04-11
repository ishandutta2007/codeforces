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

set<llo> xx;
set<llo> yy;
llo ne(llo i){
	auto j=xx.upper_bound(i);
	if(j==xx.end()){
		return *(xx.begin());
	}
	return (*j);
}
llo pre(llo i){
	auto j=xx.lower_bound(i);
	if(j!=xx.begin()){
		j--;
		return (*j);
	}
	j=xx.end();
	j--;
	return (*j);
}
llo ne2(llo i){
	auto j=yy.lower_bound(i);
	if(j==yy.end()){
		return *(yy.begin());
	}
	return (*j);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		xx.clear();
		yy.clear();
		for(llo i=0;i<n;i++){
			cin>>it[i];
			xx.insert(i);
		}
		for(llo i=0;i<n;i++){
			if(__gcd(it[i],it[(i+1)%n])==1){
				yy.insert({i});
			}
		}
		llo ind=0;
		vector<llo> ans;
		while(yy.size()){
			llo ac=ne2(ind);
			llo de=ne(ac);
			ans.pb(de);
			/*for(auto j:xx){
				cout<<j<<"<";
			}
			cout<<endl;
*/
			

			llo le=pre(de);
			llo re=ne(de);
			xx.erase(de);
			if(le==re){
				break;
			}
			
			yy.erase(de);
			yy.erase(le);
			if(__gcd(it[le],it[re])==1){
				yy.insert(le);
			}
			ind=re;
			/*cout<<le<<":"<<de<<":"<<re<<endl;
			for(auto j:xx){
				cout<<j<<"::";
			}
			cout<<endl;
			for(auto j:yy){
				cout<<j<<",,";
			}
			cout<<endl;*/
		}
		if(xx.size()==1){
			if(it[*(xx.begin())]==1){
				ans.pb(*(xx.begin()));
			}
		}
		cout<<ans.size()<<" ";
		for(auto j:ans){
			cout<<j+1<<" ";
		}
		cout<<endl;

	//	cout<<endl;
	}








 
	return 0;
}