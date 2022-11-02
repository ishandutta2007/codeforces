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

#define MAXN 100005

const int MOD = 1e9+7;
int N,M,K,X,A[MAXN],ans;
int others,cnt[1024],D[1024][1024],choose[MAXN]={1},fact[MAXN]={1};
vector <int> num;
map <int,int> idx;

int inv(int n)
{
    int ret=1,m=(MOD-2);
    lld v=n;
    for (;m;m>>=1,v=v*v%MOD) if (m&1){
        ret = ret*v%MOD;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k;
    scanf("%d%d",&N,&K);
    for (i=1;i<=N;i++) scanf("%d",A+i), put_max(X,A[i]);
    lld v;
    for (i=1,v=1;v*4<=X;i++,v*=10){
        for (j=0;j<(1<<i);j++){
            int n=0;
            for (k=0;k<i;k++) n = n*10+((j>>(i-k-1))&1?7:4);
            num.pb(n);
        }
    }
    M = sz(num);
    for (i=0;i<M;i++) idx[num[i]] = i;
    for (i=1;i<=N;i++) if (idx.count(A[i])){
        cnt[idx[A[i]]]++;
    }else others++;
    D[0][0] = 1;
    for (i=0;i<M;i++) for (j=0;j<=i;j++) if (D[i][j]){
        add(D[i+1][j],D[i][j],MOD);
        if (cnt[i]) add(D[i+1][j+1],(lld)D[i][j]*cnt[i],MOD);
    }
    for (i=1;i<=others;i++) fact[i] = (lld)fact[i-1]*i%MOD;
    for (i=1;i<=others;i++){
        choose[i] = (lld)fact[others]*inv(fact[i])%MOD*inv(fact[others-i])%MOD;
    }
    for (i=0;i<=K&&i<=M;i++) if (i+others >= K && i+others <= N && D[M][i]){
        add(ans,(lld)choose[K-i]*D[M][i],MOD);
    }
    printf("%d\n",ans);
}