//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo t;
llo n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n;
		vector<llo> aa;
		vector<llo> bb;
		for(llo i=0;i<2*n;i++){
			llo x,y;
			cin>>x>>y;
			if(x==0){
				aa.pb(abs(y));
			}
			else{
				bb.pb(abs(x));
			}
		}
		sort(aa.begin(),aa.end());
		sort(bb.begin(),bb.end());
		//reverse(bb.begin(),bb.end());
		long double ans=0;
		for(llo i=0;i<n;i++){
			ans+=sqrt((long double)(aa[i]*aa[i]+bb[i]*bb[i]));
		}
		cout<<setprecision(11)<<ans<<endl;





	}






 
	return 0;
}