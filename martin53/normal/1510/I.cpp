#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n,m,cnt[nmax];

char inp[nmax];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double prob()
{
    long long MX=1LL<<32;

    long long cur=rng();

    return 1.0*cur/MX;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n>>m;

    /*
    n=2;
    m=1e4;
    */

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)cin>>inp[j];

        /*
        for(int j=1;j<=n;j++)inp[j]='0'+rng()%2;
        inp[1]='0';
        inp[2]='1';
        */

        int mini=1e9;
        for(int j=1;j<=n;j++)mini=min(mini,cnt[j]);

        double seen[2]={0,0};
        for(int j=1;j<=n;j++)
            seen[inp[j]-'0']+=pow(0.5,cnt[j]-mini);

        double p=seen[0]/(seen[0]+seen[1]);

        //cout<<"p= "<<p<<" q= "<<1-p<<" "<<prob()<<endl;

        if(prob()<p)inp[n+1]='0';
        else inp[n+1]='1';

        cout<<inp[n+1]<<endl;

        char ret;
        cin>>ret;
        /*
        ret=rng()%2+'0';
        ret='0';
        */

        for(int j=1;j<=n+1;j++)
            cnt[j]+=(inp[j]!=ret);
    }

    /*
    cout<<"cnt: ";

    for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";

    cout<<" me= "<<cnt[n+1]<<endl;
    */

    return 0;
}