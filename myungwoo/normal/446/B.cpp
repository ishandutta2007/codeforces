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

#define MAXN 1003
#define MAXK 1000006

int N,M,K,P;
lld R[MAXN],C[MAXN],X[MAXK],Y[MAXK];
lld ans=-1e17;

priority_queue <pli> row,col;

int main()
{
    int i,j,k;
    scanf("%d%d%d%d",&N,&M,&K,&P);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++){
        scanf("%d",&k);
        R[i] += k; C[j] += k;
    }
    for (i=1;i<=N;i++) row.push(mp(R[i],i));
    for (i=1;i<=M;i++) col.push(mp(C[i],i));
    lld val = 0;
    for (i=1;i<=K;i++){
        j = row.top().second;
        row.pop();
        val += R[j];
        X[i] = val;
        R[j] -= P*M;
        row.push(mp(R[j],j));
    }
    val = 0;
    for (i=1;i<=K;i++){
        j = col.top().second;
        col.pop();
        val += C[j];
        Y[i] = val;
        C[j] -= P*N;
        col.push(mp(C[j],j));
    }
    for (i=0;i<=K;i++){
        val = X[i]+Y[K-i];
        put_max(ans,val-(lld)P*i*(K-i));
    }
    printf("%lld\n",ans);
}