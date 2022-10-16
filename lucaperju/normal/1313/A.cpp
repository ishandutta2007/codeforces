#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,t,n,m,l,k,s,p,cnt=0;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b>a)
            swap(a,b);
        if(c>b)
            swap(c,b);
        if(b>a)
            swap(a,b);
        if(c>b)
            swap(c,b);
        if(b>a)
            swap(a,b);
        int cnt=0;
        if(a>0)
        {
            --a;
            ++cnt;
        }
        if(b>0)
        {
            --b;
            ++cnt;
        }
        if(c>0)
        {
            --c;
            ++cnt;
        }
        if(a>0 && b>0)
        {
            --a;
            --b;
            ++cnt;
        }
        if(a>0 && c>0)
        {
            --a;
            --c;
            ++cnt;
        }
        if(c>0 && b>0)
        {
            --c;
            --b;
            ++cnt;
        }
        if(a>0 && b>0 && c>0)
        {
            ++cnt;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}