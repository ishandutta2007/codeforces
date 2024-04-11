#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,x;
		cin>>n>>x;
		multiset<llo> xx;
		for(llo i=0;i<n;i++){
			llo aa;
			cin>>aa;
			xx.insert(aa);
		}
		llo ans=0;
		while(xx.size()){
			auto j=xx.begin();
			llo no=(*j);
			xx.erase(j);
			if(xx.find(x*no)==xx.end()){
				ans++;
			}
			else{
				auto jj=xx.find(x*no);
				xx.erase(jj);
			}
		}
		cout<<ans<<endl;
	}



 
 
 
	return 0;
}