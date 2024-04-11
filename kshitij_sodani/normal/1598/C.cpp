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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		map<llo,llo> ss;
		llo su=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			it[i]*=2;
			su+=it[i];
			ss[it[i]]++;
		}
		if(su%n==0){
			su/=n;
			su*=2;
			llo ans=0;
			for(auto j:ss){
				if(su>=j.a){
					if(su-j.a==j.a){
						ans=(ans+((j.b*(j.b-1))/2));
					}
					if(su-j.a>j.a){
						if(ss.find(su-j.a)!=ss.end()){
							ans+=ss[su-j.a]*j.b;
						}
					}
				}
			}
			cout<<ans<<endl;

		}
		else{
			cout<<0<<endl;
		}

	}
	
 
 
	return 0;
}