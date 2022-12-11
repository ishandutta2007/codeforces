#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define push_back pb
const ll INF=1e9;
const ll INFLL=1e18;
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
string s;
cin>>s;
ll sum=0;
for (int i=0;i<n;i++)
sum+=s[i]-'0';
string ans="NO";
for (int i=2;i<=n;i++)
{
if (sum%i==0)
{
ll u=0;
ll t=sum/i;
bool ok=true;
for (int j=0;j<n;j++)
{
u+=s[j]-'0';
if (u==t)
u=0;
if (u>t)
ok=false;
}
if (ok)
ans="YES";
}
}
cout<<ans;}