#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		int ans;
		ans = abs(a-c) + abs(b-d);
		if(a==c && a==e && min(b,d)<=f && f<=max(b,d)){
			ans += 2;
		}
		if(b==d && b==f && min(a,c)<=e && e<=max(a,c)){
			ans += 2;
		}
		
		cout<<ans<<endl;
		
		
		
	}
	
	return 0;
}