#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		int ans = 0;
		rep(i,n){
			int sum = 0;
			for(int j=i;j<n;j++){
				ans += j-i+1;
				if(a[j]==0)sum++;
				ans += sum;
			}
		}
		cout<<ans<<endl;
				
		
		
	}
	
	return 0;
}