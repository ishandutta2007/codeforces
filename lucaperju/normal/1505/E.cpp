#include <bits/stdc++.h>

using namespace std;
char v[6][6];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j,m;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            cin>>v[i][j];
    int x,y;
    x=1;
    y=1;
    int cnt=0;
    if(v[1][1]=='*')
        ++cnt;
    while(x!=n || y!=m)
    {
        int a,b;
        a=n;
        b=m;
        int bst=m+n-x-y;
        for(i=x;i<=n;++i)
        {
            for(j=y;j<=m;++j)
            {
                if(i==x && j==y)
                    continue;
                if(v[i][j]=='*')
                {
                    int vlc=i+j-x-y;
                    if(vlc<bst)
                    {
                        bst=vlc;
                        a=i;
                        b=j;
                    }
                }
            }
        }
        x=a;
        y=b;
        if(v[x][y]=='*')
            ++cnt;
    }
    cout<<cnt;
	return 0;
}