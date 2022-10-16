#include <bits/stdc++.h>
using namespace std;
char v[100];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long q,m,i,j,l,r,t,n;
    cin>>t;
    while(t--)
    {
        cin>>(v+1);
        n=strlen(v+1);
        v[n+1]='.';
        for(i=1;i<=n;++i)
            if(v[i]=='a')
                break;
        if(i==n+1)
        {
            cout<<"no\n";
            continue;
        }
        l=r=i;
        --l;
        ++r;
        --n;
        char c='b';
        while(n--)
        {
            if(v[l]==c)
            {
                --l;
                ++c;
                continue;
            }
            else if(v[r]==c)
            {
                ++r;
                ++c;
                continue;
            }
            else
                break;
        }
        if(n!=-1)
            cout<<"No\n";
        else
            cout<<"YEs\n";
    }
    return 0;
}