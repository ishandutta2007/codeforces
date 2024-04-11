#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    int n,a,b;

    cin>>n>>a>>b;

    string inp;

    cin>>inp;

    int SZ=inp.size();

    int groups=1;

    for(int i=1;i<SZ;i++)
        if(inp[i]!=inp[i-1])groups++;

    return a*SZ+max((1+groups/2)*b,SZ*b);
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

        cout<<solve()<<"\n";
    }

    return 0;
}