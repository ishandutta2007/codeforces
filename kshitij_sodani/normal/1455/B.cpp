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
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		/*if(n==1){
			cout<<1<<endl;
		}
		else if(n==3){
			cout<<2<<endl;
		}
		else if(n==2 or n==4){
			cout<<3<<endl;
		}
		else if(n==5){
			cout<<4<<endl;
		}
		else{*/
			for(int i=1;i<3000;i++){
					llo cot=i+n;
					/*if(cot==2){
						cout<<1<<endl;
						break;
					}
					if(cot==3 or cot==5){
						cout<<2<<endl;
						break;
					}*/
					
					llo cur=(i+1)*(i+2);
					cur/=2;
					if(cot<=(cur-1) and cot>=2 and cot!=(cur-2)){
					//	cout<<cot<<":"<<cur-1<<endl;
						cout<<i<<endl;
						break;
					}
			}
	//	}
		
	}


 
 
	return 0;
}