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

int V,A[10],M=1e9,L;

int main()
{
    int i,j;
    scanf("%d",&V);
    for (i=1;i<10;i++) scanf("%d",A+i), put_min(M,A[i]);
    if (V < M){ puts("-1"); return 0; }
    L = V/M;
    for (i=L;i--;){
        for (j=10;--j;) if (V-A[j] >= i*M) break;
        printf("%d",j);
        V -= A[j];
    }
    puts("");
}