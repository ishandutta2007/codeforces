

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo m,d,w;
		cin>>m>>d>>w;

		if(d==1){
			cout<<0<<endl;
			continue;
		}
		llo x=w/__gcd(d-1,w);
		llo kk=min(m,d);
		llo ans=0;
		/*for(llo i=1;i<=kk;i++){
			ans+=(kk-i)/x;
		}*/
		kk-=1;
		llo yy=kk%x;
		yy+=1;
		ans+=(kk/x)*yy;
	//	cout<<ans<<endl;
	//	cout<<kk<<":"<<x<<endl;
		if(kk-yy>0){
			ans+=x*((kk/x)*(kk/x-1))/2;
		}
		cout<<ans<<endl;
	}


	return 0;
}