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
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

int yy[]={-1,0,1,0},xx[]={0,1,0,-1};
int N,M,C[1501][1501],Y[1501][1501],X[1501][1501],sy,sx;
char A[1501][1501];
queue <int> que;

char val(int y,int x){ return A[(y%N+N)%N][(x%M+M)%M]; }

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=0;i<N;i++) scanf("%s",A[i]);
    for (i=0;i<N;i++) for (j=0;j<M;j++) if (A[i][j] == 'S'){
        sy = i, sx = j;
    }
    C[sy][sx]++, Y[sy][sx] = sy, X[sy][sx] = sx, que.push(sy), que.push(sx);
    while (!que.empty()){
        int y = que.front(); que.pop();
        int x = que.front(); que.pop();
        for (i=0;i<4;i++){
            int ny = y+yy[i], nx = x+xx[i];
            int ty = (ny%N+N)%N, tx = (nx%M+M)%M;
            if (A[ty][tx] == '#') continue;
            if (C[ty][tx]){
                if (Y[ty][tx] == ny && X[ty][tx] == nx) continue;
                puts("Yes");
                return 0;
            }
            C[ty][tx]++; Y[ty][tx] = ny, X[ty][tx] = nx;
            que.push(ny), que.push(nx);
        }
    }
    puts("No");
}