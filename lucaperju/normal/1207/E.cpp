#include <bits/stdc++.h>

using namespace std;
const int mod=998244353;
struct ura
{
    int a,b;
}v[300005];
bool cmp1 (ura a, ura b)
{
    if(a.a<b.a)
        return true;
    if(a.a>b.a)
        return false;
    return a.b<b.b;
}
bool cmp2 (ura a, ura b)
{
    return a.b<b.b;
}
long long perm[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,n,i,j,cnt=0,m,p,h,a,b,s=1,sc=1;
    cout<<"? ";
    for(i=1;i<=100;++i)
        cout<<i<<' ';
    cout<<'\n';
    cout.flush();
    cin>>a;
    s=((a>>7)<<7);
    cout<<"? ";
    for(i=1;i<=100;++i)
        cout<<(i<<7)<<' ';
    cout<<'\n';
    cout.flush();
    cin>>a;
    p=1;
    for(i=1;i<=7;++i)
    {
        if(a%2)
            s+=p;
        a>>=1;
        p<<=1;
    }
    cout<<"! "<<s<<'\n';
    cout.flush();
    return 0;
}