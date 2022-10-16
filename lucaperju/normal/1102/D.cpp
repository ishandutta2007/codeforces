#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
char v[300005];
int main()
{
    long long i,j,mx=-999999999999LL,pz,n,k,cur=1,a=0,b=0,c=0,x;
    long long mn=-mx;
    cin>>n;
    cin>>(v+1);
    for(i=1;i<=n;++i)
    {
        if(v[i]=='0')
            ++a;
        else
            if(v[i]=='1')
                ++b;
            else
                ++c;
    }
    x=n/3;
    if(a<x)
    {
        for(i=1;i<=n;++i)
        {
            if(v[i]=='1' && b>x && a<x)
                v[i]='0',--b,++a;
            else
                if(v[i]=='2' && c>x && a<x)
                    v[i]='0',--c,++a;
        }
    }
    if(c<x)
    {
        for(i=n;i>=1;--i)
        {
            if(v[i]=='0' && c<x && a>x)
                v[i]='2',++c,--a;
            else
                if(v[i]=='1' && c<x && b>x)
                    v[i]='2',++c,--b;
        }
    }
    if(b<x)
    {
        for(i=1;i<=n;++i)
        {
            if(v[i]=='2' && b<x && c>x)
                v[i]='1',++b,--c;
        }
        for(i=n;i>=1;--i)
        {
            if(v[i]=='0' && b<x && a>x)
                v[i]='1',++b,--a;
        }
    }
    cout<<(v+1);
}