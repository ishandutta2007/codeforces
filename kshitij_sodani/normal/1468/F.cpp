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
		map<pair<pair<llo,llo>,llo>,llo> ss;
		for(llo i=0;i<n;i++){
			llo aa,bb,cc,dd;
			cin>>aa>>bb>>cc>>dd;
			llo cur=1;
			if(aa<cc){
				cur=0;
			}
			else if(aa==cc){
				if(bb<dd){
					cur=0;
				}
			}
			pair<llo,llo> ac;
			if(aa==cc){
				ac={0,0};
			}
			else{
				ac.a=bb-dd;
				ac.b=aa-cc;
				if(ac.b<0){
					ac.b=-ac.b;
					ac.a=-ac.a;
				}
				llo xx=__gcd(ac.a,ac.b);
				ac.a/=xx;
				ac.b/=xx;
			}
		//	long double ac=()
			ss[{ac,cur}]++;
			//cout<<ac.a<<":"<<ac.b<<":"<<cur<<endl;
		}
		llo ans=0;
		for(auto j:ss){
			if(j.a.b==0){
				if(ss.find({j.a.a,1})!=ss.end()){
					ans+=j.b*ss[{j.a.a,1}];
				}
			}
		}
		cout<<ans<<endl;
	}


 
	return 0;
}