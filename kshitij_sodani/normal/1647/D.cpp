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
		llo x,d;
		cin>>x>>d;
		llo co=0;
		while(x%d==0){
			co++;
			x/=d;
		}
		if(co==1){
			cout<<"NO"<<endl;
			continue;
		}
		if(co>=4){
			llo stt=1;
			for(llo j=2;j*j<=d;j++){
				if(d%j==0){
					stt=0;
				}
			}
			if(stt==0){
				cout<<"YES"<<endl;
				continue;
			}
		}

		llo st=1;
		for(llo j=2;j*j<=x;j++){
			if(x%j==0){
				st=0;
			}
		}
		if(st==1){
			//co=3 case and x is prime or 1
			if(co==3){
				llo stt=1;
				for(llo j=2;j*j<=d;j++){
					if(d%j==0){
						stt=0;
					}
				}
				if(stt==0){
					if(d==(x*x)){

					}
					else{
						cout<<"YES"<<endl;
						continue;
					}
				}

			}
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}





	return 0;
}