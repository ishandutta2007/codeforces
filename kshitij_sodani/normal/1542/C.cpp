//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

const llo mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	vector<llo> pre={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,47};

	while(t--){
		llo n;
		cin>>n;
		llo cur=1;
		llo ans=0;
		//cout<<ans<<endl;
		for(llo j=1;j<=50;j++){
			if(cur>n){
				break;
			}
			llo xx=n/cur;
			llo yy=j/__gcd(j,cur);

			llo cot=xx-(xx/yy);
			//cout<<j<<":"<<cot<<endl;
			ans=(ans+cot*j)%mod;
			llo cur2=__gcd(j,cur);
			cur*=j;
			cur/=cur2;
		}
		cout<<ans<<endl;;



	}



	return 0;
}