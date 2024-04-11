#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<queue>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pl;

const int N_ = 100010;

struct node{
    node(){}
    node(int mx,int mn,Pl rl,Pl lr):mx(mx),mn(mn),rl(rl),lr(lr){}
    int mx, mn;
    Pl rl, lr;
}T[1<<18];

int N, K;
ll inp[N_];

inline ll Get(Pl x){return inp[x.X] - inp[x.Y];}

struct str{
    str(){}
    str(int l,int r,Pl x):l(l),r(r),x(x){}
    Pl x;
    int l, r;
    bool operator<(const str &l)const{
        return Get(x)<Get(l.x);
    }
};

priority_queue <str> pq;

node Merge(node a, node b)
{
    node ret;
    ret.mx = (inp[a.mx] > inp[b.mx] ? a.mx : b.mx);
    ret.mn = (inp[a.mn] < inp[b.mn] ? a.mn : b.mn);
    ll tmp = max(max(Get(a.rl), Get(b.rl)), inp[b.mx]-inp[a.mn]);
    if(tmp == inp[b.mx] - inp[a.mn])ret.rl = Pl(b.mx, a.mn);
    else if(tmp == Get(a.rl))ret.rl = a.rl;
    else ret.rl = b.rl;
    tmp = max(max(Get(a.lr), Get(b.lr)), inp[a.mx]-inp[b.mn]);
    if(tmp == inp[a.mx]-inp[b.mn])ret.lr = Pl(a.mx, b.mn);
    else if(tmp == Get(a.lr))ret.lr = a.lr;
    else ret.lr = b.lr;
    return ret;
}

void build(int s,int d,int rt)
{
    if(s == d){
        T[rt] = node(s, s, Pl(0,0), Pl(0,0));
        return;
    }
    int m = (s+d) >> 1;
    build(s, m, rt<<1);
    build(m+1, d, rt<<1|1);
    T[rt] = Merge(T[rt<<1], T[rt<<1|1]);
}

node Query(int s,int d,int l,int r,int rt)
{
    if(s<=l && r<=d)return T[rt];
    int m = (l+r)>>1;
    if(s<=m && m<d)return Merge(Query(s, d, l, m, rt<<1), Query(s, d, m+1, r, rt<<1|1));
    if(s<=m)return Query(s, d, l, m, rt<<1);
    return Query(s, d, m+1, r, rt<<1|1);
}

node Query(int s,int d){return Query(s, d, 1, N, 1);}

int main()
{
    scanf("%d%d",&N,&K);
    int i;
    for(i=1;i<=N;i++)scanf("%lld",inp+i);
    build(1,N,1);
    node tm = Query(1,N);
    pq.push(str(1, N, tm.rl));
    ll ans = 0;
    for(i=1;i<=K;i++){
        if(pq.empty())break;
        str tmp = pq.top();
        pq.pop();
        ans += Get(tmp.x);
        int pp = tmp.x.X, mm = tmp.x.Y;
        if(mm < pp){
            if(mm - tmp.l >= 2){
                node u = Query(tmp.l, mm-1);
                if(Get(u.rl) > 0)pq.push(str(tmp.l, mm-1, u.rl));
            }
            if(pp - mm >= 3){
                node u = Query(mm+1, pp-1);
                if(Get(u.lr) > 0)pq.push(str(mm+1, pp-1, u.lr));
            }
            if(tmp.r - pp >= 2){
                node u = Query(pp+1, tmp.r);
                if(Get(u.rl) > 0)pq.push(str(pp+1, tmp.r, u.rl));
            }
        }
        else{
            if(pp - tmp.l >= 2){
                node u = Query(tmp.l, pp-1);
                if(Get(u.lr) > 0)pq.push(str(tmp.l, pp-1, u.lr));
            }
            if(mm - pp >= 3){
                node u = Query(pp+1, mm-1);
                if(Get(u.rl) > 0)pq.push(str(pp+1, mm-1, u.rl));
            }
            if(tmp.r - mm >= 2){
                node u = Query(mm+1, tmp.r);
                if(Get(u.lr) > 0)pq.push(str(mm+1, tmp.r, u.lr));
            }
        }
    }
    printf("%lld",ans);
    return 0;
}