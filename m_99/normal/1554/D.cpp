#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000005


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		string ans = "";
		
		if(n%2==1){
			ans += 'c';
			n--;
		}
		if(n>0){
			rep(i,(n/2)-1)ans += 'a';
			ans += 'b';
			rep(i,n/2)ans += 'a';
		}
		
		
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}