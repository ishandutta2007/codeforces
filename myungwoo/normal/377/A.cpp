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
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;
typedef pair<int,pii> piii;

int yy[]={-1,0,1,0},xx[]={0,1,0,-1};
int N,M,K,E,sy,sx;
char A[501][502];
queue <int> que;

int main()
{
	int i,j,k;
	scanf("%d%d%d",&N,&M,&K);
	for (i=1;i<=N;i++) scanf("%s",A[i]+1);
	for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (A[i][j] == '.') E++, sy = i, sx = j, A[i][j] = 'X';
	E -= K; que.push(sy), que.push(sx); A[sy][sx] = '.'; E--;
	while (!que.empty() && E){
		int y = que.front(); que.pop();
		int x = que.front(); que.pop();
		for (i=0;i<4;i++){
			int ny = y+yy[i], nx = x+xx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M || A[ny][nx] != 'X') continue;
			A[ny][nx] = '.';
			que.push(ny), que.push(nx);
			if (!--E) break;
		}
	}
	for (i=1;i<=N;i++) puts(A[i]+1);
}