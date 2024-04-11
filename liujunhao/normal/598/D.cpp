#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
#define MAXN 1000
int n,m,k;
queue<pair<int,int> >q;
void Read(int &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
char s[MAXN+10][MAXN+10];
int a[MAXN+10][MAXN+10],dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}},cnt[MAXN*MAXN+10],pos;
void bfs(pair<int,int>st,int pos){
    pair<int,int>u;
    q.push(st);
    int d;
    a[st.first][st.second]=pos;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(d=0;d<4;d++)
            if(a[u.first+dir[d][0]][u.second+dir[d][1]])
                continue;
            else if(s[u.first+dir[d][0]][u.second+dir[d][1]]=='.')
                q.push(make_pair(u.first+dir[d][0],u.second+dir[d][1])),a[u.first+dir[d][0]][u.second+dir[d][1]]=pos;
            else
                cnt[pos]++;
    }
}
int main()
{
    int i,j;
    Read(n),Read(m),Read(k);
    for(i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(s[i][j]=='.'&&!a[i][j])
                bfs(make_pair(i,j),++pos);
    while(k--){
        Read(i),Read(j);
        printf("%d\n",cnt[a[i][j]]);
    }
}