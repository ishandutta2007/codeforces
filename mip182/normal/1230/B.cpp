#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define push_back pb
const ll INF=1e9;
const ll INFLL=1e18;
int main() {
ios_base::sync_with_stdio(0);
cin.tie();
int n,k;
cin>>n>>k;
string s;
cin>>s;
if (s[0]!='1'&&k>0&&n>1){
k--;
s[0]='1';
}
for (int i=1;i<n;i++)
{
if (s[i]!='0'&& k>0){
s[i]='0';
k--;
}
}
if (n==1&&(k==1||s[0]=='0'))
s="0";
cout<<s;}