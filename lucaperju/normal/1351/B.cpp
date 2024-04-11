#include <bits/stdc++.h>

using namespace std;
int v[1003][1003];
int ocp[1003][1003];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs (int i, int j)
{
    v[i][j]=0;
    for(int x=0;x<=3;++x)
    {
        int ni=i+dx[x];
        int nj=j+dy[x];
        if(v[ni][nj]==1)
            dfs(ni,nj);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0,a;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(max(a,b)==max(c,d) && min(a,b)+min(c,d)==max(a,b))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}