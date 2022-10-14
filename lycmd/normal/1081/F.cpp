#include<bits/stdc++.h>
using namespace std;
int const N=305;
int n,pre,cur,s[N];
int ask(int l,int r){
	return cout<<"? "<<l<<" "<<r<<endl,pre=cur,cin>>cur,(cur-pre)&1;
}
int solve(int l,int r,int flg){
	int t[2]={0,0},a=cur;
	while(!t[0]||t[1])t[ask(l,r)^(!flg&&r&1)]^=1;
	a=flg?s[n]-(n-1-cur+a)/2:(r-cur+a)/2;
	while(t[0]||t[1])t[ask(l,r)^(!flg&&r&1)]^=1;
	return a;
}
int main(){
	cin>>n>>s[n],cur=s[n];
	for(int i=1;i<n;i++)
		s[i]=i==1&&n&1?solve(2,n,1):solve(i-n%2,i,0);
	cout<<"! ";
	for(int i=1;i<=n;i++)
		cout<<s[i]-s[i-1];
	cout<<endl;
}