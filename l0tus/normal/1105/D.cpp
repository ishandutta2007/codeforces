#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
const int MN = 1e5;
const int INF = 1e9;

long long N,M,P,Sp[10],L,ans,cnt=0,t,S[10],E[10];
int G[1010][1010];
int check[1010][1010];
int dis[1010][1010];
//string S;
queue<ppi> Q[10];
vector<pii> A[10],B[10];
void dfs(int i, int j, int p, int d)
{
    //printf("%d %d %d\n",i,j,cnt);
    int x,y;
    x = i+1, y = j;
    if(G[x][y]==-1 || (G[x][y]==p && check[x][y]==t && dis[x][y]>d))
    {
        if(G[x][y]==-1){
            cnt--;
            S[p]++;
            if(d==Sp[p]-1) A[p].push_back(pii(x,y));
        }
        G[x][y]=p;
        check[x][y]=t;
        dis[x][y]=d;
        if(d!=Sp[p]-1) Q[p].push(ppi(pii(x,y),d+1));
    }
    x = i-1, y = j;
    if(G[x][y]==-1 || (G[x][y]==p && check[x][y]==t && dis[x][y]>d))
    {
        if(G[x][y]==-1){
            cnt--;
            S[p]++;
            if(d==Sp[p]-1) A[p].push_back(pii(x,y));
        }
        G[x][y]=p;
        check[x][y]=t;
        dis[x][y]=d;
        if(d!=Sp[p]-1) Q[p].push(ppi(pii(x,y),d+1));
    }
    x = i, y = j+1;
    if(G[x][y]==-1 || (G[x][y]==p && check[x][y]==t && dis[x][y]>d))
    {
        if(G[x][y]==-1){
            cnt--;
            S[p]++;
            if(d==Sp[p]-1) A[p].push_back(pii(x,y));
        }
        G[x][y]=p;
        check[x][y]=t;
        dis[x][y]=d;
        if(d!=Sp[p]-1) Q[p].push(ppi(pii(x,y),d+1));
    }
    x = i, y = j-1;
    if(G[x][y]==-1 || (G[x][y]==p && check[x][y]==t && dis[x][y]>d))
    {
        if(G[x][y]==-1){
            cnt--;
            S[p]++;
            if(d==Sp[p]-1) A[p].push_back(pii(x,y));
        }
        G[x][y]=p;
        check[x][y]=t;
        dis[x][y]=d;
        if(d!=Sp[p]-1) Q[p].push(ppi(pii(x,y),d+1));
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M >> P;
    int c;
    char ch;
    for(int i=1; i<=P; i++)
        cin >> Sp[i];
    //cout << Sp[P];
    for(int i=0; i<=N+1; i++)
    {
        for(int j=0; j<=M+1; j++)
        {
            if(i==0 || j==0 || i==N+1 || j==M+1){
                G[i][j]=0;
                continue;
            }
            cin >> ch;
            if(ch=='.')
            {
                c = -1;
                cnt++;
                //cout << cnt << '\n';
            }
            else if(ch=='#')
                c = 0;
            else
            {
                c = ch-'0';
                A[c].push_back(pii(i,j));
                S[c]++;
            }
            G[i][j] = c;
        }
    }
    //cout << cnt << '\n';
    while(cnt)
    {
        t++;
        bool act = false;
        for(int i=1; i<=P; i++)
        {
            int l = A[i].size();
            for(int j=E[i]; j<l; j++){
                act = true;
                Q[i].push(ppi(A[i][j],0));
            }
            E[i] = l;
            while(!Q[i].empty()){
                ppi p = Q[i].front();
                Q[i].pop();
                dfs(p.va.va,p.va.vb,i,p.vb);
            }
            if(!cnt) break;
        }
        if(!act) break;
    }
    for(int i=1; i<=P; i++) cout << S[i] << ' ';
}