#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long u,v,m,ok=0,i,j=0,cnt=0,s=0,h,l,r,t,n,k;
    cin>>u>>v;
    if(u==v && u==0)
    {
        cout<<0<<'\n';
        return 0;
    }
    if(u==v)
    {
        cout<<1<<'\n'<<u;
        return 0;
    }
    if(u>v || (v-u)%2)
    {
        cout<<-1;
        return 0;
    }
    if((((v-u)/2)|u)==(((v-u)/2)^u))
    {
        cout<<2<<'\n';
        cout<<(((v-u)/2)|u)<<' '<<(v-u)/2;;
    }
    else
    {
        cout<<3<<'\n';
        cout<<u<<' '<<(v-u)/2<<' '<<(v-u)/2;
    }
    return 0;
}