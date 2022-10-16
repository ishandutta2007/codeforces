#include <bits/stdc++.h>
using namespace std;
int v[505][505],n;
int l[505],c[505];
void afis ()
{
    int i,j;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
            if(v[i][j]==1)
            {
                cout<<'*';
            }
            else
                cout<<'.';
        cout<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,p,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            l[i]=c[i]=0;
        for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            char cc;
            cin>>cc;
            if(cc=='*')
                v[i][j]=1,++l[i],++c[j];
            else
                v[i][j]=0;
        }
        for(i=1;i<=n;++i)
            if(l[i]==2)
                break;
        if(i<=n)
        {
            int lc=2;
            if(i==2)
                lc=1;
            for(j=1;j<=n;++j)
            {
                if(c[j])
                    v[lc][j]=1;
            }
            afis();
            continue;
        }
        for(j=1;j<=n;++j)
            if(c[j]==2)
                break;
        if(j<=n)
        {
            int cc=2;
            if(j==2)
                cc=1;
            for(i=1;i<=n;++i)
            {
                if(l[i])
                    v[i][cc]=1;
            }
            afis();
            continue;
        }
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
            {
                if(l[i] && c[j])
                    v[i][j]=1;
            }
        afis();
    }
	return 0;
}