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

int N,M,K; lld ans;

void test(int n,int m)
{
    if (n < 0 || m < 0 || n >= N || m >= M) return;
    lld a = (lld)(N/(n+1))*(M/(m+1));
    if (ans < a)
        ans = a;
}

int main()
{
    int v,i;
    scanf("%d%d%d",&N,&M,&K);
    if (K > N+M-2){ puts("-1"); return 0; }
    if (K >= M) test(K-(M-1),M-1);
    else test(0,K);
    if (K >= N) test(N-1,K-(N-1));
    else test(K,0);
    v = (lld)K*N/(N+M);
    for (i=-10;i<11;i++) test(v+i,K-v-i);
    printf("%lld\n",ans);
}