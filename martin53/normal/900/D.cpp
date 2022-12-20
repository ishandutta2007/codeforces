#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int my_pow(int a,int b)
{
    if(b==0)return 1;
    int c=my_pow(a,b/2);
    if(b%2==0)return 1LL*c*c%mod;
    return 1LL*c*c%mod*a%mod;
}
map<int,int> seen_f;
int f(int z)
{
    if(z==1)return 1;
    if(seen_f.count(z))return seen_f[z];
    int ans=my_pow(2,z-1);
    set<int> d={};
    d.insert(1);
    for(int i=2;i*i<=z;i++)
        if(z%i==0)d.insert(i),d.insert(z/i);
    for(auto k:d)
        {
        ans=ans-f(k);
        if(ans<0)ans=ans+mod;
        if(ans>=mod)ans=ans-mod;
        }
    seen_f[z]=ans;
    return ans;
}
int main()
{
int x,y;
scanf("%i%i",&x,&y);
if(y%x!=0)printf("0\n");
else printf("%i\n",f(y/x));
return 0;
}