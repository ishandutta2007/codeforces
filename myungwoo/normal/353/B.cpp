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

int N,M,A[201],B[201],idx[201],cnt[100],P,Q,ans;
vector <pii> list;

bool cmp(const int &a,const int &b){ return A[a]<A[b]; }

int main()
{
    int i,j,k;
    scanf("%d",&N); M = N+N;
    for (i=1;i<=M;i++) scanf("%d",A+i), idx[i] = i;
    sort(idx+1,idx+M+1,cmp);
    for (i=1;i<=M;i++){
        k = ++cnt[A[idx[i]]];
        if (k > 2) continue;
        if (k == 2) list.pb(mp(idx[i-1],idx[i]));
    }
    for (i=0;i<sz(list);i++){
        B[list[i].fr] = 1, B[list[i].sc] = 2;
        P++, Q++;
    }
    for (i=1;i<=M;i++) if (!B[i] && cnt[A[i]] == 1){
        if (P > Q) B[i] = 2, Q++;
        else B[i] = 1, P++;
    }
    ans = P*Q;
    for (i=1;i<=M;i++) if (!B[i]){
        if (P < N) B[i] = 1, P++;
        else B[i] = 2, Q++;
    }
    printf("%d\n",ans);
    for (i=1;i<=M;i++) printf("%d ",B[i]); puts("");
}