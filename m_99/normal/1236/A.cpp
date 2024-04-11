#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int a,b,c;
		cin>>a>>b>>c;
		int maxi = 0;
		for(int j=0;j<=100;j++){
			int aa = a;
			int bb = b;
			int cc = c;
			aa-=j;
			bb-=j*2;
			if(aa<0||bb<0)continue;
			maxi = max(maxi,(min(bb,cc/2)+j)*3);
		}
		
		cout<<maxi<<endl;
	}
	
	
    return 0;
}