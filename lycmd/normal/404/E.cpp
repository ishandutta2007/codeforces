#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int check(int x){
	int mx=0,cur=0;
	for(int i=0;i<n-1;i++)
		mx=max(mx,cur=max(1-x,cur+1-2*(s[i]=='R')));
	return mx==cur;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>s,n=s.size();
	if(s.back()=='R')for(auto&c:s)c^=30;
	int l=0,r=n+2;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;else r=mid;
	}
	cout<<l-(l>n)*n<<"\n";
}