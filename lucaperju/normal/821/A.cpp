#include <bits/stdc++.h>

using namespace std;
int v[55][55];
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,n,m;
    cin>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            cin>>v[i][j];
    int ok=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            if(v[i][j]!=1)
            {
                int okc=0;
                for(int lin=1;lin<=n;++lin)
                    for(int col=1;col<=n;++col)
                    {
                        if(v[i][j]==v[lin][j]+v[i][col])
                            okc=1;
                    }
                if(!okc)
                    ok=0;
            }
        }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}