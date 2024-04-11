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
	while(t--){
		llo aa,bb;
		cin>>aa>>bb;
		llo ans=1e6;
		for(llo i=bb;i<=2*bb;i++){
			llo cur=i-bb;
			if((aa|i)==i){
				ans=min(ans,cur+1);
			}
			for(llo j=20;j>=0;j--){
				if((1LL<<j)&aa){

				}
				else{
					llo zz=((aa&((1LL<<(j+1))-1)));
					llo cc=(aa-zz)+(1LL<<j);
					if(((cc|i)==i)){
						/*if((cur+((1LL<<j)-zz)+1)==23331){
							cout<<i<<":"<<j<<endl;
						}*/
						ans=min(ans,cur+((1LL<<j)-zz)+1);
					}
				}
			}
		}
		ans=min(ans,bb-aa);
		cout<<ans<<endl;
	}




 
	return 0;
}