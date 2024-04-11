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

int N,M;
lld A[MAXN],B[MAXN],ans;

bool proc(lld m)
{
    int i,j,p=1;
    for (i=1;i<=N&&p<=M;i++){
        if (B[p] > A[i]){
            if (B[p]-A[i] > m) continue;
            for (j=p+1;j<=M;j++){
                if (B[j]-A[i] > m) break;
            }
            p = j;
        }else{
            if (A[i]-m > B[p]) return 0;
            for (j=p+1;j<=M;j++){
                if (B[j] > A[i]){
                    if (B[j]-B[p]+min(A[i]-B[p],B[j]-A[i]) > m) break;
                }
            }
            p = j;
        }
    }
    return p>M;
}

int main()
{
    int i,j;
    lld s=0,e=1e11,m;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) scanf("%lld",A+i);
    for (i=1;i<=M;i++) scanf("%lld",B+i);
    while (s <= e){
        m = (s+e)>>1;
        if (proc(m)) e = m-1, ans = m;
        else s = m+1;
    }
    printf("%lld\n",ans);
}