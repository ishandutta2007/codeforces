#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b;
		cin>>a>>b;
		
		int ans = Inf;
		
		rep(i,50){
			int temp = i;
			int c = b+i;
			if(c==1)continue;
			int d = a;
			while(d!=0){
				d /= c;
				temp++;
			}
			ans = min(ans,temp);
		}
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}