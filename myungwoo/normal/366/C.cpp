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

#define MAXN 101

int N,K,A[MAXN],B[MAXN],D[200001],E[200001],T=100000;

int main()
{
    int i,j;
    set(D,-1);
    D[T] = 0;
    scanf("%d%d",&N,&K);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    for (i=1;i<=N;i++) scanf("%d",B+i), B[i] *= K;
    for (i=1;i<=N;i++){
        for (j=0;j<200001;j++) E[j] = D[j];
        for (j=0;j<200001;j++) if (D[j] >= 0){
            if (E[j+A[i]-B[i]] < D[j]+A[i])
                E[j+A[i]-B[i]] = D[j]+A[i];
            if (E[j] < D[j]) E[j] = D[j];
        }
        for (j=0;j<200001;j++) D[j] = E[j];
    }
    printf("%d\n",D[T]?D[T]:-1);
}