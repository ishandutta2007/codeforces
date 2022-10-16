#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,m;
    cin>>t>>n;
    if(n==1)
    {
        for(int i=1;i<=t;++i)
        {
            cout<<'a';
        }
        return 0;
    }
    t--;
    cout<<'a';
    char i=0,j=2,k=0;
    while(t--)
    {
        if(k==0)
        {
            cout<<(char)('a'+i);
            k=1;
            continue;
        }
        if(k==2)
        {
            if(i==0)
            {
                j=2,k=0;
                ++t;
                continue;
            }
            --i;
            cout<<(char)('a'+i);
            if(i==0)
            {
                j=2,k=0;
                continue;
            }
            continue;
        }
        if(j<n)
        {
            cout<<(char)('a'+j);
            k=0;
            ++j;
            continue;
        }
        if(i==n-1)
        {
            --i;
            cout<<(char)('a'+i);
            k=2;
        }
        else
        {
            ++i;
            j=i+2;
            cout<<(char)('a'+i);
            k=0;
        }
    }
	return 0;
}