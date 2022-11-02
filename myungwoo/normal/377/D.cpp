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

int N,ans;
bool chk[MAXN];
priority_queue <pii> que;

struct Z{
    int l,v,r,idx;
    bool operator < (const Z &ot)const{
        return l < ot.l;
    }
} A[MAXN];

struct NODE{
    NODE(): me(0),mx(0),tar(0),left(NULL),right(NULL) {}
    int me,mx,tar;
    NODE *left,*right;
} *root;

void dfs(NODE *now,int s,int e,int l,int r,int v)
{
    if (e < l || s > r) return;
    if (l <= s && e <= r){
        now->me += v;
    }else{
        if (now->left == NULL) now->left = new NODE(), now->right = new NODE(), now->left->tar = s, now->right->tar = e;
        int m = (s+e)>>1;
        dfs(now->left,s,m,l,r,v);
        dfs(now->right,m+1,e,l,r,v);
    }
    if (now->left == NULL){
        now->mx = now->me;
        now->tar = s;
    }else{
        now->mx = now->me+max(now->left->mx,now->right->mx);
        if (now->left->mx > now->right->mx)
            now->tar = now->left->tar;
        else
            now->tar = now->right->tar;
    }
}

void upd(int n,int v)
{
    int l = A[n].v, r = A[n].r;
    dfs(root,1,300000,l,r,v);
}

int proc()
{
    int i,j,ret=0;
    root = new NODE();
    while (!que.empty()) que.pop();
    for (i=1,j=1;i<=300000;i++){
        while (j <= N && A[j].l <= i){
            que.push(mp(-A[j].v,j));
            upd(j,1);
            j++;
        }
        while (!que.empty() && -que.top().fr < i){
            upd(que.top().sc,-1);
            que.pop();
        }
        if (root->mx == ans){
            int t = root->tar;
            while (!que.empty()){
                int n = que.top().sc; que.pop();
                if (A[n].v <= t && t <= A[n].r) chk[A[n].idx] = 1;
            }
            return 0;
        }
        put_max(ret,root->mx);
    }
    return ret;
}

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d%d%d",&A[i].l,&A[i].v,&A[i].r), A[i].idx = i;
    sort(A+1,A+N+1);
    ans = -1e9;
    ans = proc();
    proc();
    printf("%d\n",ans);
    for (i=1;i<=N;i++) if (chk[i]) printf("%d ",i); puts("");
}