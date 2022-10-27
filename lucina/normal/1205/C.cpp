#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,c[55][55];
bool ask(int x1,int y1,int x2,int y2){
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    bool buf;
    scanf("%1d",&buf);
    return buf;
}
void ans(bool t){
    printf("!\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d",c[i][j]^(((i+j)%2)?t:0));
        printf("\n");
    }
    fflush(stdout);
    exit(0);
}
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        assert(c[top.first][top.second]!=-1);
        if(top.first+2<=n&&c[top.first+2][top.second]==-1){
            bool ret=ask(top.first,top.second,top.first+2,top.second);
            c[top.first+2][top.second]=c[top.first][top.second]^(ret^1);
            q.push({top.first+2,top.second});
        }
        if(top.second+2<=n&&c[top.first][top.second+2]==-1){
            bool ret=ask(top.first,top.second,top.first,top.second+2);
            c[top.first][top.second+2]=c[top.first][top.second]^(ret^1);
            q.push({top.first,top.second+2});
        }
        if(top.first+1<=n&&top.second+1<=n&&c[top.first+1][top.second+1]==-1){
            bool ret=ask(top.first,top.second,top.first+1,top.second+1);
            c[top.first+1][top.second+1]=c[top.first][top.second]^(ret^1);
            q.push({top.first+1,top.second+1});
        }
    }
    return;
}
void kill(int x1,int y1,int x2,int y2){
    int x,y;
    if(y2>=3){
        x=x2,y=y2-2;
    }
    else if(x1>=3){
        /**
        Before
        x=x1-2,y=y;
        y=y WTF?
        After :P
        */
        x=x1-2,y=y1;
    }
    else throw;
    bool ret=ask(x,y,x1,y1+1);
    int cur=c[x][y]^(ret^1);
    ans(cur==c[x1][y1+1]?0:1);
}
bool d[55];
void get_diagonal(int x){
    bool same=true;
    int f=c[x][1];
    int cur=x;
    for(int j=2;j<=x;j++){
        same&=(f==c[--cur][j]);
        if(!same){
            kill(cur+1,j-1,cur,j);
        }
    }
    d[x]=f;
    return;
}
void firstcol(){
    bool ret=ask(2,1,2,3);
    c[2][1]=(c[2][3]^(ret^1));
    bfs(2,1);
    return;
}
bool valid1(int x,int y){
    bool ok=true;
    ok&=(c[x][y]==1);
    ok&=((c[x+1][y+1]==0)&&(c[x][y+2]==0)&&(c[x+2][y]==0));
    ok&=(c[x+2][y+2]==0);
    return ok;
}
void solve1(int x,int y){
/** another 2 cases
1 * 0       1 W 0       1 W 0
* 0 * ->    * 0 *   &   * 0 *
0 * 0       0 W 0       0 B 0
*/
///case 1
    if(c[x][y+1]==c[x+2][y+1]){
        bool ret=ask(x,y+1,x+2,y+2);
        ret^=1;
        ans(c[x][y+1]==ret?0:1);
    }
    else{
        bool ret=ask(x,y,x+1,y+2);
        ans(c[x+1][y+2]==ret?0:1);
    }
    throw;
}
bool valid2(int x,int y){
    bool ok=true;
    ok&=(c[x][y]==1);
    ok&=((c[x+1][y+1]==c[x][y+2])&&(c[x+1][y+1]==c[x+2][y]));
    ok&=(c[x+1][y+1]==1);
    ok&=(c[x+2][y+2]==0);
    return ok;
}
void solve2(int x,int y){
    /** another 2 cases
1 * 1       1 W 1       1 W 1
* 1 * ->    * 1 *   &   * 1 *
1 * 0       1 W 0       1 B 0
*/
    if(c[x][y+1]==c[x+2][y+1]){
        bool ret=ask(x,y,x+1,y+2);
        ans(c[x][y+1]==ret?0:1);
        //tested
    }
    else{
        bool ret=ask(x,y+1,x+2,y+2);
        ans(c[x+1][y+2]==ret?0:1);

        //tested
    }
}

int main(){
    scanf("%d",&n);
  /*  if(n==3){
        printf("!\n");
        printf("100\n001\n000");
        fflush(stdout);
        return 0;
    }*/
    memset(c,-1,sizeof(c));
    c[1][1]=1;
    c[n][n]=0;
    bfs(1,1);
    ///assume that (1,2)==1; if not just change later :P
    c[1][2]=1;
    bfs(1,2);
    firstcol();
    for(int i=1;i<=n;i+=2)
        get_diagonal(i);
    ///code getting longer now :P
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=n;j+=2){
            if(valid1(i,j))solve1(i,j);
            if(valid2(i,j))solve2(i,j);
        }
    }
    throw;
}

/*
    Good Luck
        -Lucina
*/