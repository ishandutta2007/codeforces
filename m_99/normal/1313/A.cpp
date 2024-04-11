#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 100000000



int main() {
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int a,b,c;
		cin>>a>>b>>c;
		
		int ans = 0;
		if(a>0){
			a--;ans++;
		}
		if(b>0){
			b--;ans++;
		}
		if(c>0){
			c--;ans++;
		}
		
		if(a<b)swap(a,b);
		if(a<c)swap(a,c);
		if(b<c)swap(b,c);
		
		if(a>=2){
			if(b>0){
				a--;b--;ans++;
			}
			if(c>0){
				a--;c--;ans++;
			}
			if(b>0&&c>0){
				b--;c--;ans++;
			}
		}
		else if(b>0){
			ans++;
			a--;b--;
		}
		
		if(a>0&&b>0&&c>0){
			ans++;
		}
		
		cout<<ans<<endl;
	}
	
    return 0;
}