#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define push_back pb
const ll INF=1e9;
const ll INFLL=1e18;
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
string s;
cin>>s;
int m;
cin>>m;
for (int jj=0;jj<m;jj++)
{
ll l,r,k;
cin>>l>>r>>k;
l--;
r--;
k=k%(r-l+1);
ll f=r-l+1;
string g=s;
for (int i=0;i<f;i++)
{
g[l+(i+k)%f]=s[l+i];
}
s=g;

}
cout<<s<<endl;}