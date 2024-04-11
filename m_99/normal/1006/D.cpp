#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){

	int n;
	cin>>n;
	
	string a,b;
	cin>>a>>b;
	int ans = 0;
	rep(i,(1+n)/2){
		map<char,int> mp;
		if(n%2==1&&i==n/2){
			mp[a[i]]++;
			mp[b[i]]++;
			if(mp.size()==2){
				ans ++;
			}
			
		}
		else{
			mp[a[i]]++;
			mp[b[i]]++;
			mp[a[n-1-i]]++;
			mp[b[n-1-i]]++;
			if(mp.size()==4){
				ans +=2;
			}
			else if(mp.size()==3){
				ans ++;
				if(a[i]==a[n-1-i])ans++;
			}
			else if(mp.size()==2){
				if(mp.begin()->second != 2){
					ans ++;
				}
			}
		}
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}