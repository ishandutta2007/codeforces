#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int n;
	cin>>n;
	
	long long x,y;
	cin>>x>>y;
	
	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		a%=(x+y);
		
		long long ok = x*y;
		long long ng = -1;
		while(ok-ng>1){
			long long mid = (ok+ng)/2;
			if(mid/x+mid/y>=a){
				ok=mid;
			}
			else{
				ng=mid;
			}
		}
		if(ok%x==0&&ok%y==0){
			cout<<"Both"<<endl;
		}
		else if(ok%y==0){
			cout<<"Vanya"<<endl;
		}
		else{
			cout<<"Vova"<<endl;
		}
	}
		
	
    return 0;
}