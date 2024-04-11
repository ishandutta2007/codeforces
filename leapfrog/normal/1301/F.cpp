//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    if(f) x=-x;
}
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int n,m,k,Q,ds[45][1005][1005],a[1005][1005];vector<pair<int,int> >v[45];char vq[45];
inline void bfs(int k)
{
    queue<pair<int,int> >q;memset(ds[k],-1,sizeof(ds[k])),memset(vq,0,sizeof(vq));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]==k) q.push(make_pair(i,j)),ds[k][i][j]=0;
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;q.pop();
		if(!vq[a[x][y]]) for(int i=0;i<(int)v[a[x][y]].size();i++,vq[a[x][y]]=1)
			if(ds[k][v[a[x][y]][i].first][v[a[x][y]][i].second]==-1)
				q.push(v[a[x][y]][i]),ds[k][v[a[x][y]][i].first][v[a[x][y]][i].second]=ds[k][x][y]+1;
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m||~ds[k][xx][yy]) continue;
            ds[k][xx][yy]=ds[k][x][y]+1,q.push(make_pair(xx,yy));
        }
    }
}
inline int Abs(int a,int b) {return a>b?a-b:b-a;}
int main()
{
    read(n),read(m),read(k);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]),v[a[i][j]].push_back(make_pair(i,j));
    for(int i=1;i<=k;i++) bfs(i);
    for(read(Q);Q--;)
    {
        int x,y,u,v,rs;read(x),read(y),read(u),read(v),rs=Abs(x,u)+Abs(y,v);
        for(int i=1;i<=k;i++) rs=min(rs,ds[i][x][y]+ds[i][u][v]+1);
        printf("%d\n",rs);
    }
    return 0;
}