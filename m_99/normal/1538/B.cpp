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
		
		vector<int> a(n);
		int sum = 0;
		rep(i,n){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		
		if(sum%n!=0){
			cout<<-1<<endl;
			continue;
		}
		
		sum /= n;
		int ans = 0;
		rep(i,n){
			if(a[i] > sum)ans++;
		}
		
		cout<<ans<<endl;
	
	}
	return 0;
}