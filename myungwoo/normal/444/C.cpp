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

#define MAXN 503
#define MAXM 124755
#define MAX_SIZE 319
//#define MAX_SIZE 3

int N,M,K;

struct GROUP{
    int size,all_color; lld sum_val,all_diff_val;
    int color[320]; lld val[320];
} G[320];

int get_gorup_num(int idx){ return (idx-1)/MAX_SIZE+1; }

int get_group_val(int gn){ return G[gn].sum_val+G[gn].all_diff_val; }

void set_all_color(int gn,int x)
{
    if (G[gn].all_color) G[gn].all_diff_val += abs(G[gn].all_color-x);
    else{
        G[gn].sum_val = 0;
        for (int i=1;i<=G[gn].size;i++){
            G[gn].val[i] += abs(G[gn].color[i]-x);
            G[gn].color[i] = x;
            G[gn].sum_val += G[gn].val[i];
        }
    }
    G[gn].all_color = x;
}

void color_interval(int gn,int l,int r,int x)
{
    int i;
    if (G[gn].all_color){
        for (i=1;i<=G[gn].size;i++) G[gn].color[i] = G[gn].all_color;
    }
    G[gn].all_color = 0;
    for (i=l;i<=r;i++) G[gn].val[i] += abs(G[gn].color[i]-x), G[gn].color[i] = x;
    G[gn].sum_val = 0;
    for (i=1;i<=G[gn].size;i++) G[gn].sum_val += G[gn].val[i];
}

void coloring(int l,int r,int x)
{
    int gl = get_gorup_num(l), gr = get_gorup_num(r);
    if (gl == gr){
        color_interval(gl,l-(gl-1)*MAX_SIZE,r-(gl-1)*MAX_SIZE,x);
        return;
    }
    color_interval(gl,l-(gl-1)*MAX_SIZE,G[gl].size,x);
    color_interval(gr,1,r-(gr-1)*MAX_SIZE,x);
    for (int i=gl+1;i<gr;i++) set_all_color(i,x);
}

lld get_value_interval(int gn,int l,int r)
{
    int i;
    lld ret = G[gn].all_diff_val*(r-l+1);
    for (i=l;i<=r;i++) ret += G[gn].val[i];
    return ret;
}

lld get_value_group(int gn)
{
    return G[gn].all_diff_val*G[gn].size+G[gn].sum_val;
}

lld get_value(int l,int r)
{
    lld ret = 0;
    int gl = get_gorup_num(l), gr = get_gorup_num(r);
    if (gl == gr){
        ret += get_value_interval(gl,l-(gl-1)*MAX_SIZE,r-(gl-1)*MAX_SIZE);
        return ret;
    }
    ret += get_value_interval(gl,l-(gl-1)*MAX_SIZE,G[gl].size);
    ret += get_value_interval(gr,1,r-(gr-1)*MAX_SIZE);
    for (int i=gl+1;i<gr;i++) ret += get_value_group(i);
    return ret;
}

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M); K = 1;
    for (i=1;i<=N;i++){
        if (G[K].size == MAX_SIZE) K++;
        G[K].size++;
        G[K].color[G[K].size] = i;
    }
    for (i=1;i<=M;i++){
        int t,l,r,x;
        scanf("%d%d%d",&t,&l,&r);
        if (t == 1){
            scanf("%d",&x);
            coloring(l,r,x);
        }else{
            printf("%lld\n",get_value(l,r));
        }
        //for (int i=1;i<=N;i++) printf("%d ",G[1].color[i]); puts("");
    }
}