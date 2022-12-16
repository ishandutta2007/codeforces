#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    char c;

    string inp;

    cin>>n>>c>>inp;

    bool wrong[2]={0,0};

    for(int i=0;i<n;i++)
        if(inp[i]!=c)
        {
            if(i==n-1)wrong[1]=1;
            else wrong[0]=1;
        }

    if(wrong[0]==0&&wrong[1]==0)
    {
        cout<<"0\n";
        return;
    }

    for(int i=2;i<=n;i++)
    {
        bool ok=1;

        for(int j=i-1;j<n;j+=i)
            if(inp[j]!=c)ok=0;

        if(ok)
        {
            cout<<"1\n"<<i<<"\n";
            return;
        }
    }

    cout<<"2\n"<<n<<" "<<n-1<<"\n";
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}