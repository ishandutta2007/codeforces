#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1001],b[1001];
bool c[1001][1001];
bool cmp(int c1,int c2)
{
    return a[c1]>a[c2];
}
main()
{
    int n,m;
    cin>>n;
    m=n;
    for(int x=0;x<n;x++)
    cin>>a[x],b[x]=x;
    sort(b,b+n,cmp);
    for(int x=0;x<n;x++)
    for(int y=0;y<a[b[x]];y++)
    c[(x+y)%(n+1)][b[x]]=1;
    for(int x=0;x<n&&m==n;x++)
    if(c[n][x]==1)m++;
    cout<<m<<endl;
    for(int x=0;x<m;x++,cout<<endl)
    for(int y=0;y<n;y++)
    if(c[x][y])cout<<1;
    else cout<<0;
}