#include<bits/stdc++.h>
using namespace std;

const int nmax=(1<<20)+42;

int n,k;

char inp[nmax];

bool seen[nmax];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>inp[i];

    int possible=n-k+1;

    possible++;

    while((possible&(possible-1)))possible++;

    int steps=0;

    while(possible>1)
    {
        steps++;
        possible=possible/2;
    }

    int not_forced=min(k,steps);
    int forced=k-not_forced;

    possible=1<<not_forced;

    for(int i=0;i<possible;i++)
        seen[i]=0;

    int ones=0;

    for(int i=0;i<=n-not_forced;i++)
    {
        if(i)
        {
            if(inp[i]=='1')ones++;
            else ones=0;
        }

        if(ones>=forced)
        {
            int hsh=0;

            for(int j=i+1;j<=i+not_forced;j++)
                if(inp[j]=='0')hsh=hsh*2+1;
                else hsh=hsh*2;

            //cout<<"block "<<hsh<<" "<<i<<endl;

            seen[hsh]=1;
        }
    }

    for(int i=0;i<possible;i++)
        if(seen[i]==0)
        {
            //cout<<"forced= "<<forced<<" not_forced= "<<not_forced<<" possible= "<<possible<<endl;

            cout<<"YES\n";
            for(int i=1;i<=forced;i++)
                cout<<"0";
            for(int j=not_forced-1;j>=0;j--)
                if((i&(1<<j)))cout<<"1";
                else cout<<"0";
            cout<<"\n";
            return;
        }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int q;
    cin>>q;

    for(int i=1;i<=q;i++)
        solve();

    return 0;
}