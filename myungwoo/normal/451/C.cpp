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

int T;
lld N,M,K,A,B;

int main()
{
    int i,j;
    for (scanf("%d",&T);T--;){
        scanf("%lld%lld%lld%lld",&N,&K,&A,&B); M = N/3;
        if (N%3){ puts("no"); continue; }
        bool valid = false;
        for (i=-1;i<2;i+=2) for (j=-1;j<2;j+=2){
            lld p = A*i, q = B*j, v = K-p-q;
            if (v < 0 || v%3) continue;
            lld a = v/3;
            if (a+p < 0 || a+p > M || a+q < 0 || a+q > M || a > M) continue;
            if (!valid) fprintf(stderr,"Valid wins: %lld %lld %lld\n",a+p,a,a+q);
            valid = 1;
        }
        puts(valid?"yes":"no");
    }
}