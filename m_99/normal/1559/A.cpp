#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		int ans = 1<<30;
		ans--;
		rep(i,n){
			int a;
			scanf("%d",&a);
			ans &= a;
		}
		
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}