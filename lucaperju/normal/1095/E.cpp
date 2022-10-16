#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
char v[1000006];
int sp[1000006];
int main()
{
    long long t,n,i,j=0,k,s=0,okneg=0,cnt=0;
    cin>>n>>ws>>(v+1);
    for(i=1;i<=n;++i)
    {
        if(v[i]=='(')
            ++s;
        else
            --s;
        sp[i]=s;
        if(s<0)
            okneg=1;
    }
    if(s!=2 && s!=-2 || n&1)
    {
        cout<<0;
        return 0;
    }
    if(s==2)
    {
        s=0;
        if(okneg)
            cout<<0;
        else
        {
        for(i=n;i>=1;--i)
            if(sp[i]<2)
                break;
        s=sp[i];
        for(++i;i<=n;++i)
        {
            if(v[i]=='(')
            {
                ++s;
                if(s>=2)
                    ++cnt;
            }
            else
                --s;
        }
        cout<<cnt;
        }
    }
    else
    if(s==-2)
    {
        okneg=s=0;
        for(i=n;i>=1;--i)
        {
            if(v[i]=='(')
                ++s;
            else
                --s;
            if(s>0)
                okneg=1;
        }
        s=0;
        if(okneg)
            cout<<0;
        else
        {
        for(i=n;i>=1;--i)
        {
            if(v[i]=='(')
                ++s;
            else
                --s;
            sp[i]=s;
        }
        for(i=1;i<=n;++i)
            if(sp[i]>-2)
                break;
        s=sp[i];
        for(--i;i>=1;--i)
        {
            if(v[i]=='(')
            {
                ++s;
            }
            else
            {
                --s;
                if(s<=-2)
                    ++cnt;
            }
        }
        cout<<cnt;
        }
    }
}