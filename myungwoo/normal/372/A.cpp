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

#define MAXN 500005

int N,A[MAXN],ans;

bool proc(int m)
{
    int i,j,k;
    for (i=N,k=N-m;k>0;i--,k--){
        if (A[i] < A[k]+A[k]) return 0;
    }
    return 1;
}

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    sort(A+1,A+N+1);
    int s=(N+1)/2,e=N,m;
    while (s <= e){
        m = (s+e)>>1;
        if (proc(m)) ans = m, e = m-1;
        else s = m+1;
    }
    printf("%d\n",ans);
}