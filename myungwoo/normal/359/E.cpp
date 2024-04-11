#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#pragma comment(linker,"/STACK:33554432")

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef pair<int,int> pii;
typedef long long lld;

int yy[]={-1,0,1,0},xx[]={0,1,0,-1}; const char *dir="URDL";
int N,Y,X,A[502][502],D[502][502];
bool vis[502][502];
string ans;

queue <int> que;

void turnon(int y,int x)
{
    if (vis[y][x]) return;
    vis[y][x] = 1;
    if (!A[y][x]) ans.pb('1');
    A[y][x] = 1;
    int i; bool chk[4]={0,};
    for (i=0;i<4;i++){
        for (int ny=y,nx=x;!chk[i];){
            ny += yy[i], nx += xx[i];
            if (ny < 1 || nx < 1 || ny > N || nx > N) break;
            if (A[ny][nx]) chk[i] = 1;
        }
    }
    for (i=0;i<4;i++) if (chk[i]){
        int ny = y+yy[i], nx = x+xx[i];
        if (vis[ny][nx]) continue;
        ans.pb(dir[i]);
        turnon(ny,nx);
        ans.pb(dir[(i+2)%4]);
    }
}

void turnoff(int y,int x)
{
    int i;
    for (i=0;i<4;i++){
        int ny = y+yy[i], nx = x+xx[i];
        if (ny < 1 || nx < 1 || ny > N || nx > N || !A[ny][nx] || D[ny][nx] <= D[y][x]) continue;
        ans.pb(dir[i]);
        turnoff(ny,nx);
        ans.pb(dir[(i+2)%4]);
    }
    ans.pb('2');
    D[y][x] = -1;
}

int main()
{
    int i,j,k;
    scanf("%d%d%d",&N,&Y,&X);
    for (i=1;i<=N;i++) for (j=1;j<=N;j++) scanf("%d",A[i]+j), D[i][j] = 1e9;
    turnon(Y,X);
    for (i=1;i<=N;i++) for (j=1;j<=N;j++) if (A[i][j] && !vis[i][j]){ puts("NO"); return 0; }
    D[Y][X] = 0; que.push(Y), que.push(X);
    while (!que.empty()){
        int y = que.front(); que.pop();
        int x = que.front(); que.pop();
        for (i=0;i<4;i++){
            int ny = y+yy[i], nx = x+xx[i];
            if (ny < 1 || nx < 1 || ny > N || nx > N || !A[ny][nx]) continue;
            if (D[ny][nx] == 1e9) D[ny][nx] = D[y][x]+1, que.push(ny), que.push(nx);
        }
    }
    turnoff(Y,X);
    puts("YES");
    cout << ans << endl;
}