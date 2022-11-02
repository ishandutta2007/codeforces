#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,a,b,i;
    cin>>n>>m>>a>>b;
    int v[m];
    for(i=0;i<m;i++)
        cin>>v[i];
    sort(v,v+m);
    int dist = b-a, run;
    if(dist < 0)
    {
        run = n-a;
    }
    else
    {
        run = a-1;
    }
    int drop = 0;
    for(i=min(abs(dist)-2,m-1);i>=0;i--)
    {
        if(v[i]+drop+1 > run+abs(dist))
            continue;
        else
            drop++;
    }
    cout<<drop<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
        solve();
}