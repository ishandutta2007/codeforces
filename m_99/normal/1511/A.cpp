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
		cin>>n;
		int ans = 0;
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
			if(a[i]!=2)ans++;
		}
		
		cout<<ans<<endl;
		
		
		
		
		
		
	}
	
    return 0;
}