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
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<llo,llo>> ss;
	map<llo,vector<llo>> tt;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	for(llo i=0;i<n;i++){
		cin>>it[i];
		ss.pb({aa[i],it[i]});
		
		tt[aa[i]].pb(it[i]);
	}
	sort(ss.begin(),ss.end());
	llo ma=-1;
	llo ans=0;
	for(auto i:ss){
		//cout<<i.a<<":"<<ma<<endl;
		if(i.a>=ma){
			priority_queue<llo> ee;
			ma=i.a;
			llo su=0;
			while(ee.size() or ma==i.a){
				if(tt.find(ma)!=tt.end()){
					for(auto j:tt[ma]){
						ee.push(j);
						su+=j;
					}
				}
				su-=ee.top();
				ans+=su;
				ee.pop();
				//cout<<su<<":"<<ma;
				ma++;
			}
			//cout<<endl;
		}
	}
	cout<<ans<<endl;



 
 
	return 0;
}