#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(i) for(int i=0;i<n;i++)
int c[100]={0};
int main(){
	int n;
	string s;
	cin>>n>>s;
	F(i)c[s[i]-'0']++;
	int ans=0;
	F(i)if(c[8]>=i&&i*11<=n)ans=i;
	cout<<ans;
	return 0;
}