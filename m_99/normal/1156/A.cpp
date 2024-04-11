#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001



int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	int ans = 0;
	rep(i,n-1){
		if(a[i]*a[i+1]==6){
			cout<<"Infinite"<<endl;
			return 0;
		}
		
		if(a[i]==1){

			if(a[i+1]==2)ans += 3;
			else ans += 4;
			if(i!=0&&a[i-1]==3&&a[i+1]==2)ans--;
		}
		else{
			if(a[i]==2)ans += 3;
			else ans += 4;
		}
		
	}
	
	cout<<"Finite"<<endl;
	cout<<ans<<endl;
	
	return 0;
}