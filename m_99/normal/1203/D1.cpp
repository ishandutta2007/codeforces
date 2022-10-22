#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf (long long)1000000000000000




int main(){
	
	string s,t;
	cin>>s>>t;
	
	int n = s.size();
	int m = t.size();
	vector<int> len0(n+1,0),len1(n+1,0);
	
	rep(i,s.size()){
		int ind = len0[i];
		len0[i+1] = ind;
		if(ind!=m){
			if(s[i]==t[ind])len0[i+1] = ind+1;
		}
	}
	
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	
	rep(i,s.size()){
		int ind = len1[i];
		len1[i+1] = ind;
		if(ind!=m){
			if(s[i]==t[ind])len1[i+1] = ind+1;
		}
	}
	int ans = n;
	rep(i,len0.size()){
		int d = distance(len1.begin(),lower_bound(len1.begin(),len1.end(),m - len0[i]));
		ans = min(ans,d+i);
	}
	ans = n-ans;
	cout<<ans<<endl;
	
	return 0;
}