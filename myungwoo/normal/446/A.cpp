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

#define MAXN 100005

int N,A[MAXN],D[MAXN],E[MAXN],ans;

int main()
{
    int i;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i); A[N+1] = 2e9;
    for (i=1;i<=N;i++){
        if (A[i-1] < A[i]) D[i] = D[i-1]+1;
        else D[i] = 1;
        put_max(ans,D[i]);
    }
    for (i=N;i;i--){
        if (A[i] < A[i+1]) E[i] = E[i+1]+1;
        else E[i] = 1;
    }
    for (i=1;i<=N;i++){
        if (A[i-1]+1 < A[i+1]) put_max(ans,D[i-1]+E[i+1]+1);
        put_max(ans,E[i+1]+1);
        put_max(ans,D[i-1]+1);
    }
    printf("%d\n",ans);
}