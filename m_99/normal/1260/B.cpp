#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000



int main(){
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		int Y = a*2-b;
		if(Y%3!=0){
			cout<<"NO"<<endl;
			continue;
		}
		int y = Y/3;
		int x = a-2*y;
		if(x>=0&&y>=0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
	
}