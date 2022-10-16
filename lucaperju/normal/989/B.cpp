#include <iostream>
#include <cstring>
using namespace std;
char s[2005],c[2005];
int main()
{
    int n,p,ok=1,i;
    cin>>n>>p>>ws;
    cin>>s;
    for(i=0;i<p;++i)
    {
        c[i]=s[i];
    }
    for(i=p;i<n;++i)
    {
        if(s[i]=='.' || c[i%p]=='.')
        {
            ok=0;
            if(s[i]=='0')
                c[i%p]='1';
            else
            if(s[i]=='1')
                c[i%p]='0';
            else
            if(c[i%p]=='0')
                s[i]='1';
            else
            if(c[i%p]=='1')
                s[i]='0';
            if(c[i%p]=='.' && s[i]=='.')
                c[i%p]='0',s[i]='1';
            break;
        }
        else
        if(s[i]!=c[i%p])
            ok=0;
    }
    if(ok==1)
        cout<<"No";
    else
    {
        for(i=0;i<p;++i)
        {
            if(c[i%p]!='.')
                cout<<c[i%p];
            else
                cout<<'0';
        }
        for(i=p;i<n;++i)
        {
            if(s[i]!='.')
                cout<<s[i];
            else
                cout<<'0';
        }
    }
    return 0;
}