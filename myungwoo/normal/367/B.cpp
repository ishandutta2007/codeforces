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

#define MAXN 200005

int N,M,K,P;
int A[MAXN],B[MAXN],C[MAXN];
int cnt[MAXN],now[MAXN];
vector <int> ans;

int main()
{
    int i,j,k;
    scanf("%d%d%d",&N,&M,&P);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    for (i=1;i<=M;i++) scanf("%d",B+i), C[i] = B[i];
    sort(C+1,C+M+1); K = unique(C+1,C+M+1)-C-1;
    for (i=1;i<=M;i++) B[i] = lower_bound(C+1,C+K+1,B[i])-C, cnt[B[i]]++;
    for (i=1;i<=N;i++){
        int p = lower_bound(C+1,C+K+1,A[i])-C;
        if (C[p] != A[i]) A[i] = K+1;
        else A[i] = p;
    }
    // for (i=1;i<=N;i++) printf("%d ",A[i]); puts("");
    // for (i=1;i<=M;i++) printf("%d ",B[i]); puts("");
    for (i=1;i<=P;i++){
        int wrong = K;
        for (j=i;j<=N;j+=P){
            if (now[A[j]] == cnt[A[j]]) wrong++;
            if (++now[A[j]] == cnt[A[j]]) wrong--;
            if (j-(lld)M*P > 0){
                int p = j-(lld)M*P;
                if (now[A[p]] == cnt[A[p]]) wrong++;
                if (--now[A[p]] == cnt[A[p]]) wrong--;
            }
            if (!wrong && j-(lld)(M-1)*P > 0) ans.pb(j-(lld)(M-1)*P);
        }
        for (j=i;j<=N;j+=P) now[A[j]] = 0;
    }
    sort(all(ans));
    printf("%d\n",sz(ans));
    for (i=0;i<sz(ans);i++) printf("%d ",ans[i]); puts("");
}