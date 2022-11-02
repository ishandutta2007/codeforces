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

#define bit(n) (1<<((n)-1))

int N,M,A[101];
int D[1<<20];
bool V[1<<20];
char type[21]; int team[21];

int dy(int turn,int msk)
{
    int &ret = D[msk];
    if (V[msk]) return ret;
    V[msk] = 1;
    ret = -2e9;
    int now = team[turn], i;
    if (turn == M){
        if (type[turn] == 'b') return ret=0;
        for (i=1;i<=M;i++) if (!(msk&bit(i))){
            put_max(ret,A[i]);
        }
        return ret;
    }
    int next = team[turn+1];
    for (i=1;i<=M;i++) if (!(msk&bit(i))){
        int val = (type[turn]=='p')*A[i]+dy(turn+1,msk|bit(i))*(next==now?1:-1);
        put_max(ret,val);
    }
    return ret;
}

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    sort(A+1,A+N+1,greater<int>());
    scanf("%d",&M);
    for (i=1;i<=M;i++) scanf(" %c%d",type+i,team+i);
    int ans = dy(1,0);
    printf("%d\n",ans*(team[1]==1?1:-1));
}