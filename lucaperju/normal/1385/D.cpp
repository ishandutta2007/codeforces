#include <bits/stdc++.h>
using namespace std;
char v[200005];
int solve (char c, int st, int dr)
{
    if(st==dr)
    {
        if(v[st]==c)
            return 0;
        else
            return 1;
    }
    int i;
    int mid=(st+dr)/2;
    int cnt=0;
    for(i=st;i<=mid;++i)
    {
        if(v[i]!=c)
            ++cnt;
    }
    int rz1=cnt+solve(c+1,mid+1,dr);
    cnt=0;
    for(i=mid+1;i<=dr;++i)
    {
        if(v[i]!=c)
            ++cnt;
    }
    int rz2=cnt+solve(c+1,st,mid);
    return min(rz1,rz2);
}
int main()
{
    long long n,m,i,j,x,y,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        cout<<solve('a',1,n)<<'\n';
    }
    return 0;
}