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

#define MAXN 5003

int N,M,A[MAXN],MN[MAXN];

struct Q{
    Q(int t=0,int l=0,int r=0,int v=0): t(t),l(l),r(r),v(v) {}
    int t,l,r,v;
};
vector <Q> que;

int main()
{
    int i,j,t,l,r,v;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) MN[i] = 1e9;
    for (i=1;i<=M;i++){
        scanf("%d%d%d%d",&t,&l,&r,&v);
        if (t == 1){
            for (j=l;j<=r;j++) A[j] += v;
        }else{
            for (j=l;j<=r;j++){
                if (MN[j] > v-A[j]) MN[j] = v-A[j];
            }
        }
        que.pb(Q(t,l,r,v));
    }
    for (i=1;i<=N;i++) A[i] = 0;
    for (i=0;i<M;i++){
        t = que[i].t, l = que[i].l, r = que[i].r, v = que[i].v;
        if (t == 1){
            for (j=l;j<=r;j++) A[j] += v;
        }else{
            for (j=l;j<=r;j++){
                if (MN[j] == v-A[j]) break;
            }
            if (j > r){ puts("NO"); return 0; }
        }
    }
    puts("YES");
    for (i=1;i<=N;i++) printf("%d ",MN[i]);
    puts("");
}