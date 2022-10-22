#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int a,b,c;
	cin>>a>>b>>c;
	
	if(a==b){
		cout<<"YES"<<endl;
		return 0;
	}
	
	if(c!=0){
		int k = b-a;
		if(k%c==0&&k/c>=0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	else{
		cout<<"NO"<<endl;
	}
	
	return 0;
	
}