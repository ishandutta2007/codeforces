#include <bits/stdc++.h>
using namespace std;
char v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,p,j;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cin>>(v+1);
        if(a%2 && b%2)
        {
            cout<<"-1\n";
            continue;
        }
        if(a%2)
        {
            if(v[(a+b+1)/2]=='1')
            {
                cout<<"-1\n";
                continue;
            }
            v[(a+b+1)/2]='0';
        }
        if(b%2)
        {
            if(v[(a+b+1)/2]=='0')
            {
                cout<<"-1\n";
                continue;
            }
            v[(a+b+1)/2]='1';
        }
        int ok=1;
        int n=a+b;
        for(i=1;n-i+1>i;++i)
        {
            if(v[i]=='?' && v[n-i+1]!='?')
            {
                v[i]=v[n-i+1];
            }
            else if(v[i]!='?' && v[n-i+1]=='?')
            {
                v[n-i+1]=v[i];
            }
            else if(v[i]!='?' && v[n-i+1]!='?' && v[i]!=v[n-i+1])
            {
                ok=0;
                break;
            }
        }
        if(!ok)
        {
            cout<<"-1\n";
            continue;
        }
        for(i=1;i<=n;++i)
        {
            if(v[i]=='0')
                --a;
            if(v[i]=='1')
                --b;
        }
        if(a<0 || b<0)
        {
            cout<<"-1\n";
            continue;
        }
        for(i=1;n-i+1>i;++i)
        {
            if(v[i]=='?')
            {
                if(a>0)
                {
                    v[i]=v[n-i+1]='0';
                    a-=2;
                }
                else
                    v[i]=v[n-i+1]='1';
            }
        }
        cout<<(v+1)<<'\n';
    }
	return 0;
}