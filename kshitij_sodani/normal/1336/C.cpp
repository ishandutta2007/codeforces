#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
#define pb push_back
typedef long long int llo;
llo mod=998244353;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	string t;
	cin>>s;
	cin>>t;
	llo n=s.size();
	llo m=t.size();
	char ac[n+1];
	char cc[m+1];
	strcpy(ac,s.c_str());
	strcpy(cc,t.c_str());
	llo aa[n];
	llo bb[n];
	for(llo i=0;i<n;i++){
		aa[i]=s[i]-'a';
	}
	for(llo i=0;i<m;i++){
		bb[i]=t[i]-'a';
	}
	for(llo i=m;i<n;i++){
		bb[i]=-1;
	}
	llo dp[n];

	for(llo i=0;i<n;i++){
		if(bb[i]==-1 or bb[i]==aa[0]){
			dp[i]=2;
		}
		else{
			dp[i]=0;
		}
	}
	llo ans=0;
	if(m==1){
		ans+=dp[0];
		ans%=mod;
	}
	for(llo i=1;i<n;i++){
		llo dp2[n];
		for(llo j=0;j<n;j++){
			dp2[j]=0;
		}
		for(llo j=0;j<n-i;j++){
			if(bb[j]==aa[i] or bb[j]==-1){
				dp2[j]+=dp[j+1];
				dp2[j]%=mod;
			}
		}
		for(llo j=0;j<n-i;j++){
			if(bb[j+i]==aa[i] or bb[j+i]==-1){
				dp2[j]+=dp[j];
				dp2[j]%=mod;
			}
		}
		if(i+1>=m){
			ans+=dp2[0];
			ans%=mod;
		}
		for(llo j=0;j<n;j++){
			dp[j]=dp2[j];
		}
		/*for(llo j=0;j<n;j++){
			cout<<dp[j]<<" ";
		}
		cout<<endl;*/
	}
	ans%=mod;
	cout<<ans<<endl;



	return 0;
}