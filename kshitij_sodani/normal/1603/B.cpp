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
		llo x,y;
		cin>>x>>y;
		if(x==y){
			cout<<x<<endl;
			continue;
		}
		if(x>y){
			cout<<x+y<<endl;
			continue;
		}
		/*else{

		}*/
		llo z=y/x;
		//x<y


		//if(z>=1){
			//p1=1
			//p2=z
			llo xx=y-x*z;
			//xx<=x-2
			if(xx>=1){
				//q1=xx-1
				cout<<(x*z)+(xx/2)<<endl;
			}
			else{
				//put q1=0
				//p1=z
				//p2=1
				cout<<y<<endl;

			}
		//}
		
	}





 
	return 0;
}