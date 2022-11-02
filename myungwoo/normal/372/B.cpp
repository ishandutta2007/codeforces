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

int N,M,Q,A[42][42],L[42][42];
lld D[42][42][42][42],E[42][42][42][42];

int main()
{
    int i,j,k,l;
    scanf("%d%d%d",&N,&M,&Q);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) scanf("%1d",A[i]+j);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++){
        for (k=j;k&&!A[i][k];k--);
        L[i][j] = k;
    }
    for (i=1;i<=N;i++) for (j=1;j<=M;j++){
        for (k=j;k>L[i][j];k--){
            for (l=i;l&&L[l][j]<k;l--){
                D[l][k][i][j]++;
            }
        }
    }
    for (i=1;i<=N;i++) for (j=1;j<=M;j++){
        for (k=i;k;k--) for (l=j;l;l--){
            D[k][l][i][j] = D[k][l][i][j]+D[k+1][l][i][j]+D[k][l+1][i][j]-D[k+1][l+1][i][j];
        }
    }
    for (i=1;i<=N;i++) for (j=1;j<=M;j++){
        for (k=i;k<=N;k++) for (l=j;l<=M;l++){
            E[i][j][k][l] = D[i][j][k][l]+E[i][j][k-1][l]+E[i][j][k][l-1]-E[i][j][k-1][l-1];
        }
    }
    while (Q--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%lld\n",E[a][b][c][d]);
    }
}