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

#define MAXN 100005

int N,M,K,W[MAXN],ans;
lld D[2001]={0,1,2,4};

int main()
{
    int i,j,k;
    for (i=4;i<2001;i++){
        if (i&1){
            D[i] = i*(i-1)/2+1;
        }else{
            D[i] = i*(i-1)/2+(i/2);
        }
    }
    scanf("%d%d",&N,&M);
    for (i=1;i<2001;i++) if (D[i] <= N) K = i;
    for (i=1;i<=M;i++) scanf("%*d%d",W+i);
    sort(W+1,W+M+1);
    for (i=0;i<K&&i<M;i++) ans += W[M-i];
    printf("%d\n",ans);
}