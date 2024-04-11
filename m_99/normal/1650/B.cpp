#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long l,r,a;
		cin>>l>>r>>a;
		
		long long ans = (r/a) + (r%a);
		if((l/a) != (r/a)){
			ans = max(ans,(r/a)-1 + (a-1));
		}
		
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}