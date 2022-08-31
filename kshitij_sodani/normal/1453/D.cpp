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
	vector<llo> cur;
	llo cc=2;
	for(llo i=0;;i++){
		if(cc>(llo)1e18){
			break;
		}
		cur.pb(cc);
		cc*=2;
		cc+=2;
	}
	while(t--){
		llo k;
		cin>>k;
		if(k%2==1){
			cout<<-1<<endl;
		}
		else{
			vector<llo> ans;
			while(k){
				llo xx=0;
				llo ind=0;
				for(auto j:cur){

					if(j<=k){
						xx=j;
						ind++;
						//cout<<j<<".";
					}
				}
			//	cout<<endl;
				//cout<<xx<<":"<<ind<<endl;
				ans.pb(1);
				for(llo i=0;i<ind-1;i++){
					ans.pb(0);
				}
				k-=xx;
			}
			cout<<ans.size()<<endl;
			for(auto j:ans){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}



 
 
	return 0;
}