//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,h;
		cin>>n>>h;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			it[i]=-it[i];
		}
		sort(it,it+n);
		llo aa=-it[0];
		llo bb=-it[1];
		if(h<=aa){
			cout<<1<<endl;
		}
		else{
			llo x=(h)/(aa+bb);
			llo ans=x*2;
			h-=x*(aa+bb);
			if(h==0){
				cout<<ans<<endl;
			}
			else if(h<=aa){
				cout<<ans+1<<endl;
			}
			else{
				cout<<ans+2<<endl;
			}
			
		}


	}


 
 
 
	return 0;
}