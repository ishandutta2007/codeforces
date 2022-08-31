#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo aa,bb;
 
		cin>>aa>>bb;
		if(aa%bb!=0){
			cout<<aa<<endl;
			continue;
		}
 		llo ans=1;
		vector<llo> jj;
		for(llo i=1;i*i<=bb;i++){
			if(bb%i==0){
				jj.pb(bb/i);
				jj.pb(i);
			}
		}
		for(auto i:jj){
			if(i==1){
				continue;
			}
			llo st=0;
				for(llo j=2;j*j<=i;j++){
					if(i%j==0){
						st=1;
						break;
					}
				}
				if(st){
					continue;
				}
 
			llo co=0;
			llo dd=aa;
			while(dd%i==0){
				co++;
				dd/=i;
			}
 
			llo co2=0;
			dd=bb;
			while(dd%i==0){
				co2++;
				dd/=i;
			}
			llo kk=1;
			for(llo j=0;j<max(co-co2+1,(llo)0);j++){
				kk*=i;
			}
			ans=max(ans,aa/(kk));
		} 
		cout<<ans<<endl;
 
	}
 
 
 
 
 
 
 
 
 
	return 0;
}