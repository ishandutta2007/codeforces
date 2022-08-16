//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n;
llo aa[200001];
llo bb[200001];

llo ma=0;
void solve(){
	vector<pair<pair<llo,llo>,llo>> ss;

	for(llo i=0;i<n;i++){
		if(aa[i]<bb[i]){
			ss.pb({{aa[i],bb[i]},i});
		}
		else if(aa[i]>bb[i]){
			ss.pb({{bb[i],-1},i});
			ss.pb({{aa[i],1e9+1},i});
		}
	}
	sort(ss.begin(),ss.end());
	multiset<llo> cur;
	
	for(auto j:ss){
		if(j.a.b==-1){
			cur.insert(aa[j.b]);
		}
		else if(j.a.b>1e9){
			auto jj=cur.find(j.a.a);
			cur.erase(jj);
		}
		else{
			if(cur.size()){
				auto jj=cur.end();
				jj--;
				ma=max(ma,min((*jj),j.a.b)-j.a.a);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo ans=0;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	for(llo i=0;i<n;i++){
		cin>>bb[i];
		ans+=abs(bb[i]-aa[i]);
	}
	solve();
	for(int i=0;i<n;i++){
		swap(aa[i],bb[i]);
	}
	solve();
	
	ans-=2*ma;





	cout<<ans<<endl;
 
 
	return 0;
}