#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,a[nmax],b[nmax];

int solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;

        a[i]=c-'0';
    }

    a[0]=0;
    a[n+1]=0;

    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;

        b[i]=c-'0';
    }

    int outp=0;

    for(int i=1;i<=n;i++)
        if(b[i]==1)
        {
            if(a[i-1]==1)
            {
                a[i-1]=2;
                outp++;
            }
            else if(a[i]==0)
            {
                a[i]=2;
                outp++;
            }
            else if(a[i+1]==1)
            {
                a[i+1]=2;
                outp++;
            }
        }

    return outp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}