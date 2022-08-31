//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		pair<llo,llo> mi={1e9+1,0};
		pair<llo,llo> ma={-1,-1};
		map<pair<llo,llo>,llo> zz;

		
		for(llo i=0;i<n;i++){
			llo aa,bb,cc;
			cin>>aa>>bb>>cc;
			if(zz.find({aa,bb})==zz.end()){
				zz[{aa,bb}]=cc;
			}
			zz[{aa,bb}]=min(zz[{aa,bb}],cc);
			if(aa<mi.a){
				mi={aa,cc};
			}
			else if(aa==mi.a){
				mi.b=min(mi.b,cc);
			}
			if(bb>ma.a){
				ma={bb,cc};
			}	
			else if(bb==ma.a){
				ma.b=min(ma.b,cc);
			}
			llo ans=mi.b+ma.b;
			pair<llo,llo> kk={mi.a,ma.a};
		//	cout<<mi.a<<","<<ma.a<<endl;
			if(zz.find(kk)!=zz.end()){
			//	cout<<zz[{kk}]<<":"<<endl;
				ans=min(ans,zz[kk]);
			}
			cout<<ans<<endl;
		}
		
	}





 
	return 0;
}