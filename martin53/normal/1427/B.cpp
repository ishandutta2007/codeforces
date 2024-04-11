#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k;

char inp[nmax];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
    }

    vector<int> seen={};

    int w=0;

    for(int i=1;i<=n;i++)
        if(inp[i]=='W')w++;

    int outp=w;

    for(int i=1;i<=n;i++)
        if(inp[i]=='W'&&inp[i-1]=='W')outp++;

    if(k==0)
    {
        cout<<outp<<endl;
        return;
    }

    if(w+k>=n)
    {
        cout<<2*n-1<<endl;
        return;
    }

    if(w==0)
    {
        cout<<2*k-1<<endl;
        return;
    }

    for(int i=1;i<=n;i++)
        if(inp[i]=='L')
        {
            int j=i;

            while(inp[j]=='L')j++;

            if(1<i&&j<=n)seen.push_back(j-i);

            i=j-1;
        }

    sort(seen.begin(),seen.end());

    for(auto w:seen)
    {
        if(w<=k)
        {
            outp+=2*w+1;
            k=k-w;
        }
    }

    outp+=2*k;

    cout<<outp<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin>>t;

    while(t)
    {
        solve();
        t--;
    }

    return 0;
}