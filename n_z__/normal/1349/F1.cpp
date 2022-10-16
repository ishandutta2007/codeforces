#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
int a[5001][5001];
main() 
{
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    {
        a[x][0]=1;
        for(int y=1;y<x;y++)
        a[x][y]=(a[x-1][y-1]*(x-y)%p+a[x-1][y]*(y+1)%p)%p;
    }
    for(int x=1;x<=n;x++)
    {
        int ans=1;
        for(int y=x+1;y<=n;y++)
        ans=(ans*y%p+a[y][x-1])%p;
        cout<<ans<<' ';
    }
}