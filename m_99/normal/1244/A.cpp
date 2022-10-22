#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		
		int x = (a+c-1)/c;
		int y = (b+d-1)/d;
		
		if(x+y>k){
			cout<<-1<<endl;
		}
		else{
			cout<<x<<' '<<y<<endl;
		}
	}
	
	
	
	
	
    return 0;
}