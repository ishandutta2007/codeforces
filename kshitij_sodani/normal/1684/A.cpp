#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ma=10;
		vector<llo> ss;
		while(n){
			ma=min(ma,n%10);
			ss.pb(n%10);
			n/=10;
		}

		if(ss.size()==2){
			cout<<ss[0]<<endl;
			continue;
		}
		cout<<ma<<endl;
	/*	reverse(ss.begin(),ss.end());
		llo tt=ss.size();
		for(llo i=0;i<ss.size();i++){
			if((i%2)==((tt-1)%2)){
				ma=min(ma,ss[i]);
			}
		}*/
	//	cout<<ma<<endl;
	}



	







	return 0;
}