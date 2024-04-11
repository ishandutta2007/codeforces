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

#define MAXN 300005
#define MAXV 1000006

int N,M;
int bit[MAXV];
int ans[MAXN];
vector <int> P;

struct Z{
    int s,e;
    bool operator < (const Z &ot)const{
        return e<ot.e;
    }
} A[MAXN];

struct INFO{
    INFO(){}
    INFO(int pos,int bef,int num): pos(pos),bef(bef),num(num) {}
    int pos,bef,num;
    bool operator < (const INFO &ot)const{
        return bef<ot.bef;
    }
};
vector <INFO> inf;

void _add(int pos,int val)
{
    for (;pos<MAXV;pos+=(pos&-pos)) bit[pos] += val;
}

int _read(int pos)
{
    int ret=0;
    for (;pos;pos-=(pos&-pos)) ret += bit[pos];
    return ret;
}

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) scanf("%d%d",&A[i].s,&A[i].e);
    sort(A+1,A+N+1);
    for (i=1;i<=M;i++){
        P.clear();
        for (scanf("%d",&j);j--;){
            scanf("%d",&k);
            P.pb(k);
        }
        P.pb(MAXV);
        for (j=0;j<sz(P)-1;j++){
            inf.pb(INFO(P[j],P[j+1],i));
        }
    }
    sort(all(inf));
    for (i=0,k=1;i<sz(inf);i++){
        while (k <= N && A[k].e < inf[i].bef){
            _add(A[k].e+1,-1);
            _add(A[k].s,1);
            k++;
        }
        ans[inf[i].num] += _read(inf[i].pos);
    }
    for (i=1;i<=M;i++) printf("%d\n",ans[i]);
}