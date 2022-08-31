//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[200001];
vector<llo> tt;
llo n;
bool check(llo no){
	llo cur=tt.size()-no;
	for(llo i=0;i<no;i++){
		if(it[i]>=tt[cur]){
			return false;
		}
		cur++;
	}
	return true;
}
bool check2(llo no){
	llo cur=n-no;
	for(llo i=0;i<no;i++){
		if(it[cur]<=tt[i]){
			return false;
		}
		cur++;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		cin>>n;
		set<llo> cur;
		for(llo i=1;i<=2*n;i++){
			cur.insert(i);
		}
		for(llo i=0;i<n;i++){
			cin>>it[i];
			cur.erase(it[i]);
		}
		tt.clear();
		for(auto j:cur){
			tt.pb(j);
		}
		llo low=0;
		llo high=n;
		while(low<high-1){
			llo mid=(low+high)/2;
			if(check(mid)){
				low=mid;
			}
			else{
				high=mid;
			}
		}
		llo ind=low;
		if(check(high)){
			ind=high;
		}
		low=0;
		high=n;
		while(low<high-1){
			llo mid=(low+high)/2;
			if(check2(mid)){
				low=mid;
			}
			else{
				high=mid;
			}
		}
		llo ind2=low;
		if(check2(high)){
			ind2=high;
		}
		ind2=n-ind2;
		cout<<max(ind,ind2)-min(ind,ind2)+1<<endl;
		//cout<<ind<<":"<<ind2<<endl;







	}







 
	return 0;
}