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

#define MAXN 100005

int N,A[MAXN],B[MAXN];

int main()
{
    int i,j;
    vector <int> pos;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i), B[i] = A[i];
    sort(B+1,B+N+1);
    for (i=1;i<=N;i++) if (A[i] != B[i]){
        pos.pb(i);
    }
    if (!sz(pos)){ puts("yes\n1 1"); return 0; }
    for (i=pos[0];i<=pos.back();i++){
        int j = pos.back()-(i-pos[0]);
        if (A[i] != B[j]){ puts("no"); return 0; }
    }
    puts("yes");
    printf("%d %d\n",pos[0],pos.back());
}