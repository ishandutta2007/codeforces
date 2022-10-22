#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 1005
using namespace std;
int cs[maxn*maxn];
int co[maxn][maxn];
int fn[maxn][maxn];
char s[maxn][maxn];
int n,m,t;
int cc=1;
vector<int> cx;
vector<int> cy;
void vis(int x,int y) {
    cx.push_back(x);
    cy.push_back(y);
    int id=0;
    while(id<cx.size()) {
        x=cx[id];
        y=cy[id];
        id++;
        co[x][y]=cc;
        cs[cc]++;
        if(s[x-1][y]==s[x][y] && co[x-1][y]==0) {
            co[x-1][y]=cc;
            cx.push_back(x-1);
            cy.push_back(y);
        }
        if(s[x+1][y]==s[x][y] && co[x+1][y]==0) {
            co[x+1][y]=cc;
            cx.push_back(x+1);
            cy.push_back(y);
        }
        if(s[x][y-1]==s[x][y] && co[x][y-1]==0) {
            co[x][y-1]=cc;
            cx.push_back(x);
            cy.push_back(y-1);
        }
        if(s[x][y+1]==s[x][y] && co[x][y+1]==0) {
            co[x][y+1]=cc;
            cx.push_back(x);
            cy.push_back(y+1);
        }
    }
    cx.clear();
    cy.clear();
}
void bfs() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(cs[co[i][j]]>1) {
                cx.push_back(i);
                cy.push_back(j);
                fn[i][j]=0;
            }
        }
    }
    int x,y;
    int id=0;
    while(id<cx.size()) {
        x=cx[id];
        y=cy[id];
        id++;
        if(fn[x-1][y]==-1) {
            fn[x-1][y]=fn[x][y]+1;
            cx.push_back(x-1);
            cy.push_back(y);
        }
        if(fn[x+1][y]==-1) {
            fn[x+1][y]=fn[x][y]+1;
            cx.push_back(x+1);
            cy.push_back(y);
        }
        if(fn[x][y-1]==-1) {
            fn[x][y-1]=fn[x][y]+1;
            cx.push_back(x);
            cy.push_back(y-1);
        }
        if(fn[x][y+1]==-1) {
            fn[x][y+1]=fn[x][y]+1;
            cx.push_back(x);
            cy.push_back(y+1);
        }
    }
    cx.clear();
    cy.clear();
}
int main() {
    scanf("%d %d %d",&n,&m,&t);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(co[i][j]==0) {
                vis(i,j);
                cc++;
            }
            fn[i][j]=-1;
        }
    }
    bfs();
    int x,y;
    long long p;
    while(t--) {
        scanf("%d %d %lld",&x,&y,&p);
        if(cc==n*m+1) printf("%c\n",s[x][y]);
        else {
            long long ct=fn[x][y];
            if(p<=ct) printf("%c\n",s[x][y]);
            else {
                p-=ct;
                int cur=s[x][y]-'0';
                if(p%2ll) cur^=1;
                printf("%d\n",cur);
            }
        }
    }
	return 0;
}