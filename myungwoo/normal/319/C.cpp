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

#define MAXN 100005

int N;
int stk[MAXN],scnt;
lld A[MAXN],B[MAXN],D[MAXN];

lld f(lld x,int i){ return x*B[i]+D[i]; }
double g(int i,int j){ return (double)(D[j]-D[i])/(B[i]-B[j]); }

int main()
{
    int i,j,p;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%lld",A+i);
    for (i=1;i<=N;i++) scanf("%lld",B+i);
    stk[++scnt] = 1;
    for (i=2,p=1;i<=N;i++){
        while (p < scnt && f(A[i],stk[p]) >= f(A[i],stk[p+1])) p++;
        j = stk[p];
        D[i] = A[i]*B[j]+D[j];
        while (p < scnt && g(i,stk[scnt]) <= g(stk[scnt-1],stk[scnt])) scnt--;
        stk[++scnt] = i;
    }
    printf("%lld\n",D[N]);
}