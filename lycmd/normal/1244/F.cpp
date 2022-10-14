#include<bits/stdc++.h>
using namespace std;
int const N=2333333;
int n,k,f[N];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
		f[i]=s[i]==s[(i+1)%n]||s[i]==s[(i+n-1)%n]?0:2e9;
	for(int i=0;i<n;i++)f[i]=min(f[i],f[(i+n-1)%n]+1);
	for(int i=0;i<n;i++)f[i]=min(f[i],f[(i+n-1)%n]+1);
	for(int i=n-1;i>=0;i--)f[i]=min(f[i],f[(i+1)%n]+1);
	for(int i=n-1;i>=0;i--)f[i]=min(f[i],f[(i+1)%n]+1);
	for(int i=0;i<n;i++)
		cout<<(char)(s[i]^(min(f[i],k)%2?21:0));
}