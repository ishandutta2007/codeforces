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

int N,Q,cnt[3][MAXN];
char A[MAXN];

int main()
{
    int i,j,k;
    scanf("%s",A+1); N = strlen(A+1);
    for (i=1;i<=N;i++){
        for (j=0;j<3;j++) cnt[j][i] += cnt[j][i-1];
        cnt[A[i]-'x'][i]++;
    }
    for (scanf("%d",&Q);Q--;){
        int c[3]={0,},s,e;
        scanf("%d%d",&s,&e);
        for (i=0;i<3;i++) c[i] = cnt[i][e]-cnt[i][s-1];
        int mx=0,mn=1e9;
        for (i=0;i<3;i++) put_max(mx,c[i]), put_min(mn,c[i]);
        if (e-s+1 < 3 || mx-mn < 2) puts("YES");
        else puts("NO");
    }
}