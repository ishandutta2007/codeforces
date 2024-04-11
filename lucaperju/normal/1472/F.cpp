#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int a,b;
    int av,bv;
}v[200003];
bool cmp (ura a, ura b)
{
    if(a.b<b.b)
        return true;
    if(a.b>b.b)
        return false;
    return a.a<b.a;
}
int mat[2][600005];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=m;++i)
        {
            cin>>v[i].a>>v[i].b;
            v[i].av=v[i].a;
            v[i].bv=v[i].b;
        }
        sort(v+1,v+m+1,cmp);
        if(m%2==1)
        {
            cout<<"No\n";
            continue;
        }
        for(i=1;i<=m;++i)
        {
            if(v[i].bv-v[i-1].bv>=3)
            {
                if(v[i].b%2==v[i-1].b%2)
                    v[i].b=v[i-1].b+2;
                else
                    v[i].b=v[i-1].b+1;
            }
            else
            {
                v[i].b-=(v[i-1].bv-v[i-1].b);
            }
        }
        n=min(n,m*3);
        for(i=1;i<=n;++i)
            mat[0][i]=mat[1][i]=0;
        for(i=1;i<=m;++i)
            mat[v[i].a-1][v[i].b]=1;
        mat[0][n+1]=mat[1][n+1]=1;
        int ok=1;
        for(i=1;i<=n;++i)
        {
            if(mat[0][i]==mat[1][i])
                continue;
            if(mat[0][i]==0)
            {
                if(mat[0][i+1]==1)
                {
                    ok=0;
                    break;
                }
                mat[0][i+1]=1;
            }
            if(mat[1][i]==0)
            {
                if(mat[1][i+1]==1)
                {
                    ok=0;
                    break;
                }
                mat[1][i+1]=1;
            }
        }
        if(ok)
            cout<<"Yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}