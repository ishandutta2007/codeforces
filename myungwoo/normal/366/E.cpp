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

int N,M,K,S,ans;
int A[2001][2001],P[100005],Q[2002][2002],W[2002][2002],E[2002][2002],R[2002][2002];
bool w[10][10];

int farest(int y,int x)
{
	int ret=0;
	put_max(ret,y+x+Q[y][x]);
	put_max(ret,y-x+W[y][x]);
	put_max(ret,-y+x+E[y][x]);
	put_max(ret,-y-x+R[y][x]);
	return ret;
}

int main()
{
	int i,j,k,color;
	scanf("%d%d%d%d",&N,&M,&K,&S);
	for (i=1;i<=N;i++) for (j=1;j<=M;j++) scanf("%d",A[i]+j);
	for (i=1;i<=S;i++) scanf("%d",P+i);
	for (i=1;i<S;i++) w[P[i]][P[i+1]] = w[P[i+1]][P[i]] = 1;
	for (color=1;color<=K;color++){
		for (i=0;i<=N+1;i++) for (j=0;j<=M+1;j++) Q[i][j] = W[i][j] = E[i][j] = R[i][j] = -1e9;
		for (i=1;i<=N;i++){
			for (j=1;j<=M;j++){
				int now=-i-j;
				Q[i][j] = max(Q[i-1][j],Q[i][j-1]);
				if (A[i][j] == color) put_max(Q[i][j],now);
			}
			for (j=M;j>0;j--){
				int now=-i+j;
				W[i][j] = max(W[i-1][j],W[i][j+1]);
				if (A[i][j] == color) put_max(W[i][j],now);
			}
		}
		for (i=N;i>0;i--){
			for (j=1;j<=M;j++){
				int now=i-j;
				E[i][j] = max(E[i+1][j],E[i][j-1]);
				if (A[i][j] == color) put_max(E[i][j],now);
			}
			for (j=M;j>0;j--){
				int now=i+j;
				R[i][j] = max(R[i+1][j],R[i][j+1]);
				if (A[i][j] == color) put_max(R[i][j],now);
			}
		}
		for (i=1;i<=N;i++) for (j=1;j<=M;j++){
			if (w[A[i][j]][color]){
				int dist = farest(i,j);
				if (ans < dist) ans = dist;
			}
		}
	}
	printf("%d\n",ans);
}