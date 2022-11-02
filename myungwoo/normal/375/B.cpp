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

#define MAXN 5004

int N,M,R[MAXN],B[MAXN],cnt[MAXN],ans;
bool A[MAXN][MAXN];
char buf[MAXN];

int main()
{
    int i,j;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++){
        scanf("%s",buf+1);
        for (j=1;j<=M;j++) A[i][j] = buf[j]-'0';
    }
    for (j=1;j<=M;j++){
        for (i=1;i<=N;i++){
            if (!A[i][j]) R[i] = 0;
            else R[i]++;
        }
        for (i=1;i<=N;i++) cnt[R[i]]++;
        int idx=0;
        for (i=0;i<=M;i++){
            for (;cnt[i];cnt[i]--) B[++idx] = i;
        }
        int mx=0;
        for (i=1;i<=N;i++) put_max(mx,B[i]*(N-i+1));
        put_max(ans,mx);
    }
    printf("%d\n",ans);
}