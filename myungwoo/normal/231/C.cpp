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

int N,K,A[MAXN],X,Y;

int main()
{
    int i,j;
    scanf("%d%d",&N,&K);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    sort(A+1,A+N+1);
    lld sum=0;
    for (i=j=1;i<=N;i++){
        sum += A[i];
        while ((lld)(i-j+1)*A[i]-sum > K) sum -= A[j++];
        if (X < i-j+1) X = i-j+1, Y = A[i];
    }
    printf("%d %d\n",X,Y);
}