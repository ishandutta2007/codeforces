#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int solve(int l,int r,char op){
	if(l==r)return s[l]!=op;
	int mid=(l+r)>>1,cnt1=0,cnt2=0;
	for(int i=l;i<=mid;i++)cnt1+=s[i]!=op;
	for(int i=mid+1;i<=r;i++)cnt2+=s[i]!=op;
	return min(cnt1+solve(mid+1,r,op+1),cnt2+solve(l,mid,op+1));
}
int main(){
	for(cin>>t;t--;){
		cin>>n>>s,s=" "+s;
		cout<<solve(1,n,'a')<<"\n";
	}
}