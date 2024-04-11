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

int yy[]={-1,0,1,0},xx[]={0,1,0,-1};
int N,M,K,A[1001][1001],B[1001][1001],C[1001][1001],Y,X;
vector <int> ans;

void proc(int len)
{
    int i,j,k;
    set(B,0); set(C,0);
    queue <int> que;
    que.push(Y), que.push(X); B[Y][X] = 1;
    while (!que.empty()){
        int y = que.front(); que.pop();
        int x = que.front(); que.pop();
        C[y][x] = 1;
        for (i=0;i<4;i++){
            int ny = y+yy[i]*len, nx = x+xx[i]*len;
            if (ny < 1 || ny > N || nx < 1 || nx > M || !A[y+yy[i]][x+xx[i]]) continue;
            for (k=1;k<len;k++) B[y+yy[i]*k][x+xx[i]*k] = 1;
            if (B[ny][nx]) continue;
            B[ny][nx] = 1;
            que.push(ny), que.push(nx);
        }
    }
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (A[i][j] != B[i][j]) return;
    int odd=0,even=0;
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (C[i][j]){
        int deg=0;
        for (k=0;k<4;k++){
            int y = i+yy[k]*len, x = j+xx[k]*len;
            if (y < 1 || x < 1 || y > N || x > M || !C[y][x] || !A[i+yy[k]][j+xx[k]]) continue;
            deg++;
        }
        if (deg&1) odd++;
        else even++;
    }
    if (!odd || odd == 2) ans.pb(len);
}

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) scanf("%d",A[i]+j);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (A[i][j]){
        if (!A[i-1][j]){
            for (k=i;k<=N&&A[k][j];k++);
            put_max(K,k-i);
        }
        if (!A[i][j-1]){
            for (k=j;k<=M&&A[i][k];k++);
            put_max(K,k-j);
        }
    }
    for (i=1;i<=N&&!Y;i++) for (j=1;j<=M&&!Y;j++) if (A[i][j]) Y = i, X = j;
    K--;
    if (K > 1) proc(K);
    for (i=2;i*i<=K;i++) if (K%i == 0){
        proc(i);
        if (i*i != K) proc(K/i);
    }
    sort(all(ans));
    if (ans.empty()) puts("-1");
    else{ for (i=0;i<sz(ans);i++) printf("%d ",ans[i]); puts(""); }
}