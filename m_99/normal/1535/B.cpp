#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		{
			vector<int> b;
			rep(i,n){
				if(a[i]%2==0)b.push_back(a[i]);
			}
			rep(i,n){
				if(a[i]%2==1)b.push_back(a[i]);
			}
			swap(a,b);
		}
		
		int ans = 0;
		
		rep(i,n){
			for(int j=i+1;j<n;j++){
				if(gcd(a[i],a[j]*2)>1)ans++;
			}
		}
		
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}