#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 10000000000000000

int main() {
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long a,b,c,d,x,y,x1,y1,x2,y2;
		cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
		
		if(a+b>0&&x1==x2){
			cout<<"NO"<<endl;
			continue;
		}
		if(c+d>0&&y1==y2){
			cout<<"NO"<<endl;
			continue;
		}
		
		long long A = min(a,b),B = min(c,d);
		a-=A;
		b-=A;
		c-=B;
		d-=B;
		
		x+=b-a;
		y+=d-c;
		
		if(x<=x2&&x>=x1&&y<=y2&&y>=y1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
	
    return 0;
}