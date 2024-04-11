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

int P,A[5],B[5],C[5],D[5];

int main()
{
    int i;
    scanf("%d",&P);
    for (i=0;i<4;i++) scanf("%d%d%d%d",A+i,B+i,C+i,D+i);
    for (i=0;i<4;i++){
        int a = min(A[i],B[i]), b = min(C[i],D[i]);
        if (a+b <= P){ printf("%d %d %d\n",i+1,a,P-a); break; }
    }
    if (i == 4) puts("-1");
}