#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		
		if(x>=4){
			cout<<"YES"<<endl;
			continue;
		}
		if(x==1){
			if(y==1){
				cout<<"YES"<<endl;
				continue;
			}
			else{
				cout<<"NO"<<endl;
				continue;
			}
		}
		if(y<=3){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	
    return 0;
}