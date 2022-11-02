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

int N,Q,L,S;
int A[MAXN],bit[MAXN];
bool rev;

int get(int n)
{
    int ret = 0;
    for (;n;n-=(n&-n)) ret += bit[n];
    return ret;
}

void upd(int n,int v)
{
    for (;n<=N;n+=(n&-n)) bit[n] += v;
}

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&Q); L = N;
    for (i=1;i<=N;i++) A[i] = 1, upd(i,1);
    while (Q--){
        int t;
        scanf("%d",&t);
        if (t == 1){
            int p;
            scanf("%d",&p);
            if (p+p > L) p = L-p, rev ^= 1;
            if (rev){
                for (i=1;i<=p;i++){
                    A[S+L-p-p+i] += A[S+L-i+1];
                    upd(S+L-p-p+i,A[S+L-i+1]);
                }
            }else{
                for (i=1;i<=p;i++){
                    A[S+p+p-i+1] += A[S+i];
                    upd(S+p+p-i+1,A[S+i]);
                }
                S += p;
            }
            L -= p;
        }else if (t == 2){
            int l,r;
            scanf("%d%d",&l,&r);
            if (rev){
                printf("%d\n",get(S+L-l)-get(S+L-r));
            }else{
                printf("%d\n",get(S+r)-get(S+l));
            }
        }
    }
}