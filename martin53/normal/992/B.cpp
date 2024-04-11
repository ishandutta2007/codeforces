#include<bits/stdc++.h>
using namespace std;
set<long long> div1,div2;
map< pair<int,int>, bool> counted;
int main()
{
int l,r,a,b;
cin>>l>>r>>a>>b;
for(int i=1;i*i<=a;i++)
if(a%i==0){div1.insert(i);div1.insert(a/i);}

for(int i=1;i*i<=b;i++)
    if(b%i==0){div2.insert(i);div2.insert(b/i);}

int ans=0;
for(auto p:div1)
    for(auto q:div2)
    {
    long long aa=1LL*p*q;
    long long bb=1LL*a*b/aa;
    if(counted[{aa,bb}])continue;
    if(__gcd(aa,bb)==a&&l<=aa&&aa<=r&&l<=bb&&bb<=r)ans++;
    counted[{aa,bb}]=1;
    }
cout<<ans<<endl;
return 0;
}