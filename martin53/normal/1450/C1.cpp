#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;
int n;

char inp[nmax][nmax];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)cin>>inp[i][j];

    int cnt[3]={0,0,0};

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(inp[i][j]=='X')cnt[(i+j)%3]++;

    int which=0;
    if(cnt[which]>cnt[1])which=1;
    if(cnt[which]>cnt[2])which=2;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(inp[i][j]=='X'&&(i+j)%3==which)cout<<"O";
            else cout<<inp[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}