#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long i,j=0,n,mn=9999999999LL,k=0,pz=-1,s1=0,s2=0,sc=0,x,y,z,a,b,c;
    long long mx=-mn;
    cin>>x>>y>>z>>a>>b>>c;
    int nedc=z-c;
    if(nedc<0)
        nedc=0;
    a-=x;
    if(a<0)
    {
        cout<<"NO";
        return 0;
    }
    if(nedc+y<=a+b)
        cout<<"YES";
    else
        cout<<"NO";
}