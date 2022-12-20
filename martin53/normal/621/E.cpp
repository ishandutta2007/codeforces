#include<bits/stdc++.h>
using namespace std;
const int ans_mod=1e9+7;
vector<int> original;
int mod;
int my_pow(int a,int b)
{
    if(b==0)return 1;
    int c=my_pow(a,b/2);
    if(b%2==0)return c*c%mod;
    return c*c%mod*a%mod;
}
vector<int> rec(int blocks)
{
    if(blocks==1)return original;
    if(blocks%2==0)
    {
        vector<int> now={},half=rec(blocks/2);
        for(int i=0;i<mod;i++)now.push_back(0);
        int pw=my_pow(10%mod,blocks/2);
        for(int i=0;i<mod;i++)
            for(int j=0;j<mod;j++)
            now[(i*pw+j)%mod]=(now[(i*pw+j)%mod]+1LL*half[i]*half[j])%ans_mod;
        return now;
    }
        vector<int> now={},half=rec(blocks-1);
        for(int i=0;i<mod;i++)now.push_back(0);
        int pw=10;
        for(int i=0;i<mod;i++)
            for(int j=0;j<mod;j++)
            now[(i*pw+j)%mod]=(now[(i*pw+j)%mod]+1LL*half[i]*original[j])%ans_mod;
        return now;
}
int main()
{
int n,b,k;
cin>>n>>b>>k>>mod;
for(int i=0;i<mod;i++)original.push_back(0);
int val;
for(int i=1;i<=n;i++)
{
cin>>val;
original[val%mod]++;
}
//cout<<"original: ";for(auto p:original)cout<<p<<" ";cout<<endl;
vector<int> outp=rec(b);
cout<<outp[k]<<endl;
return 0;
}