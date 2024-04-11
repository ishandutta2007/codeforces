#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf (long long)1000000000000000




int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	
	sort(a.begin(),a.end());
	
	int last = 0;
	int ans = 0;
	
	rep(i,n){
		if(a[i]-1 > last){
			ans++;
			last = a[i]-1;
		}
		else if(a[i] > last){
			last = a[i];
			ans++;
		}
		else if(a[i]+1>last){
			last = a[i]+1;
			ans++;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}