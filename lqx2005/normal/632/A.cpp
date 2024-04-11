#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200005;
ll p,ret,res;
ll n;
string s[N];
int main()
{
    cin>>n>>p;
    ret=0,res=0;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=n;i>=1;i--)
	{
		if(s[i]=="halfplus") ret+=1,res+=ret,ret*=2;
		else res+=ret,ret*=2;
	}
	cout<<res*p/2<<endl;
    return 0;
}