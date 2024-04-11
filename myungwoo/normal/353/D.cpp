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

#define MAXN 1000006

int N,num[MAXN],T[MAXN];
char A[MAXN],*S;
vector <int> P;

int main()
{
    int i;
    scanf("%s",A+1); N = strlen(A+1);
    for (i=1;A[i]=='F';i++);
    S = A+i-1, N -= i-1; P.pb(0);
    for (i=1;i<=N;i++) if (S[i] == 'F'){
        num[i] = sz(P); P.pb(i);
    }
    if (sz(P) > 1) T[1] = P[1]-1;
    for (i=2;i<sz(P);i++){
        if (P[i]-i > T[i-1]) T[i] = P[i]-i;
        else T[i] = T[i-1]+1;
    }
    printf("%d\n",T[sz(P)-1]);
}