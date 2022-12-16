#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,p,k;

char inp[nmax];

int x,y;

int cnt_wrong[nmax];

void solve()
{
    cin>>n>>p>>k;
    for(int i=1;i<=n;i++)cin>>inp[i];
    cin>>x>>y;

    for(int i=n;i>=1;i--)
    {
        cnt_wrong[i]=(inp[i]=='0');
        if(i+k<=n)cnt_wrong[i]+=cnt_wrong[i+k];

        //cout<<i<<" -> "<<cnt_wrong[i]<<endl;
    }

    int outp=n*x;

    for(int cut=0;cut<=n-p;cut++)
    {
        int cur=cut*y;

        cur+=x*cnt_wrong[cut+p];

        outp=min(outp,cur);
    }

    cout<<outp<<"\n";
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
        solve();
    }
    return 0;
}