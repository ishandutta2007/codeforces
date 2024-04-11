#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define push_back pb
const ll INF=1e9;
const ll INFLL=1e18;
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
for (int jj=0;jj<t;jj++)
{
ll n;
cin>>n;
ll ans=n*(n+1)/2;
ll q=-1;
while (n)
{
n= (n>>1);
q++;
}
ans-=2*((1<<(q+1))-1);
cout<<ans<<'\n';
    
}}