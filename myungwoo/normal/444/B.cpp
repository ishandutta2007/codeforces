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

int N,D,X;
int A[MAXN],B[MAXN],C[MAXN],nxt[MAXN],idx[MAXN],to[MAXN];

int rand(){ return X = ((lld)X*37+10007)%1000000007; }

bool cmp(const int &a,const int &b){ return A[a]>A[b]; }

int get(int x){ return x==to[x]?x:(to[x]=get(to[x])); }

int main()
{
    int i,j,k;
    scanf("%d%d%d",&N,&D,&X);
    for (i=1;i<=D;i++) B[i] = 1;
    for (i=1;i<=N;i++) A[i] = i, idx[i] = i;
    for (i=1;i<=N+1;i++) to[i] = i;
    for (i=0;i<N;i++) swap(A[i+1],A[rand()%(i+1)+1]);
    for (i=0;i<N;i++) swap(B[i+1],B[rand()%(i+1)+1]);
    for (i=N,k=N+1;i>=0;i--){
        nxt[i] = k;
        if (B[i]) k = i;
    }
    sort(idx+1,idx+N+1,cmp);
    for (i=1;i<=N;i++){
        int x = idx[i];
        for (j=nxt[0];x+j-1<=N;j=nxt[j]){
            while (x+j-1 <= N && get(x+j-1) != x+j-1){
                int p = get(x+j-1);
                if (p <= N && !B[p-x+1]) p = nxt[p-x+1]+x-1;
                j = p-x+1;
            }
            if (x+j-1 > N) break;
            C[x+j-1] = A[x];
            to[x+j-1] = get(x+j);
        }
    }
    for (i=1;i<=N;i++) printf("%d\n",C[i]);
}