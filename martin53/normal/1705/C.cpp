#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,c,q;

char inp[nmax];
long long SZ[nmax];

long long l[nmax],r[nmax];

char query()
{
    long long p;
    cin>>p;

    for(int i=c;i>=1;i--)
        if(p>SZ[i-1])
            p=l[i]+p-SZ[i-1]-1;

    return inp[p];
}

void solve()
{
    cin>>n>>c>>q;

    for(int i=1;i<=n;i++)cin>>inp[i];

    SZ[0]=n;

    for(int i=1;i<=c;i++)
    {
        cin>>l[i]>>r[i];

        SZ[i]=SZ[i-1]+r[i]-l[i]+1;
    }

    for(int i=1;i<=q;i++)
        cout<<query()<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}