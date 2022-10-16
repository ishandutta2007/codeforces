#include <bits/stdc++.h>

using namespace std;
vector<int>v[404];
const int mod=998244353;
int dst[404][404];
void bfs (int pz)
{
    dst[pz][pz]=0;
    queue<int>q;
    q.push(pz);
    while(!q.empty())
    {
        int pzc=q.front();
        q.pop();
        for(int i=0;i<v[pzc].size();++i)
        {
            if(dst[pz][v[pzc][i]]>dst[pz][pzc]+1)
            {
                dst[pz][v[pzc][i]]=dst[pz][pzc]+1;
                q.push(v[pzc][i]);
            }
        }
    }
}
int cnt[505];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j,m;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            dst[i][j]=500;
    for(i=1;i<=n;++i)
        bfs(i);
    int a,b,c;
    for(a=1;a<=n;++a)
    {
        for(b=1;b<=n;++b)
        {
            int d=dst[a][b];
            for(i=0;i<=d;++i)
                cnt[i]=0;
            long long rzc=1;
            for(c=1;c<=n;++c)
            {
                if(dst[a][c]+dst[c][b]==d)
                {
                    ++cnt[dst[a][c]];
                    if(cnt[dst[a][c]]>1)
                    {
                        rzc=0;
                        break;
                    }
                    continue;
                }
                int cntc=0;
                for(int i=0;i<v[c].size();++i)
                {
                    int pz=v[c][i];
                    if(dst[a][pz]+1==dst[a][c] && dst[b][pz]+1==dst[b][c])
                        ++cntc;
                }
                rzc=(rzc*1LL*cntc)%mod;
            }
            cout<<rzc<<' ';
        }
        cout<<'\n';
    }
	return 0;
}