#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[200001];
llo le[200001];
llo re[200001];
llo n;
llo pre[200001];
llo solve(){
	for(llo i=1;i<=n;i++){
		pre[i]=pre[i-1]+it[i-1];
	}
	vector<pair<pair<llo,llo>,llo>> ss;
	for(llo i=0;i<n;i++){
		llo cur=pre[i];
		while(ss.size()){
			if(ss.back().a.a<=it[i]){
				cur=min(cur,ss.back().b);
				ss.pop_back();
			}
			else{
				break;
			}
		}
		if(cur<pre[i]){
			return 0;
		}
		ss.pb({{it[i],i},cur});
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo ans=0;
		ans+=solve();
		for(llo i=0;i<n/2;i++){
			swap(it[i],it[n-i-1]);
		}
		ans+=solve();

		if(ans<2){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}

	}







	return 0;
}