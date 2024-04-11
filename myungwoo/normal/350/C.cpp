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

int N,X[MAXN],Y[MAXN],order[MAXN];
vector <string> ans;
char buf[999];

bool cmp(const int &a,const int &b)
{
    return abs(X[a])!=abs(X[b])?abs(X[a])<abs(X[b]):abs(Y[a])<abs(Y[b]);
}

int main()
{
    int i,j;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d%d",X+i,Y+i), order[i] = i;
    sort(order+1,order+N+1,cmp);
    for (j=1;j<=N;j++){
        i = order[j];
        sprintf(buf,"1 %d %c",abs(X[i]),X[i]>0?'R':'L');
        if (X[i]) ans.pb(buf);
        sprintf(buf,"1 %d %c",abs(Y[i]),Y[i]>0?'U':'D');
        if (Y[i]) ans.pb(buf);
        ans.pb("2");
        sprintf(buf,"1 %d %c",abs(X[i]),X[i]>0?'L':'R');
        if (X[i]) ans.pb(buf);
        sprintf(buf,"1 %d %c",abs(Y[i]),Y[i]>0?'D':'U');
        if (Y[i]) ans.pb(buf);
        ans.pb("3");
    }
    printf("%d\n",sz(ans));
    for (i=0;i<sz(ans);i++) puts(ans[i].c_str());
}