#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,q;

int inp[nmax];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;

        inp[i]=inp[i-1]+c-'a'+1;
    }

    for(int i=1;i<=q;i++)
    {
        int l,r;

        cin>>l>>r;

        cout<<inp[r]-inp[l-1]<<"\n";
    }

    return 0;
}