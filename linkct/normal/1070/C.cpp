#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 1000005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int maxv[N*4], minv[N*4], ql, qr, mask[N*4];
LL qk, qv, K;
LL sum[N*4], add[N*4];
struct Interval
{
    int l, r, c, p;
    bool operator <(const Interval &t) const
    {
        return p < t.p;
    }
}l[N];
LL ans = 0;
void push_up(int o)
{
    maxv[o] = max(maxv[o<<1], maxv[o<<1|1]);
    minv[o] = min(minv[o<<1], minv[o<<1|1]);
    sum[o] = sum[o<<1] + sum[o<<1|1];
}

void push_down(int o, int L, int R, int mid)
{
    if(mask[o])
    {
        mask[o<<1] = mask[o<<1|1] = 1;
        maxv[o<<1] = maxv[o<<1|1] = minv[o<<1] = minv[o<<1|1] = K;
        add[o<<1] = add[o<<1|1] = 0;
        sum[o<<1] = (mid-L+1) * K, sum[o<<1|1] = (R-mid) * K;
        mask[o] = 0;
    }
    if(add[o])
    {
        maxv[o<<1] += add[o];
        maxv[o<<1|1] += add[o];
        minv[o<<1] += add[o];
        minv[o<<1|1] += add[o];
        add[o<<1] += add[o];
        add[o<<1|1] += add[o];
        sum[o<<1] += (mid-L+1) * add[o], sum[o<<1|1] += (R-mid) * add[o];
        add[o] = 0;
    }
}

void Add(int o, int L, int R)
{
    int mid = (L+R)>>1;
    //debug(o);
    //debug(L);
    //debug(R);
    //debug(minv[o]);
    //debug(maxv[o]);
    //debug(sum[o]);
    if(L>=ql && R<=qr)
    {
        //debug("here2");
        if(maxv[o] + qk <= K)
        {
            maxv[o] += qk;
            minv[o] += qk;
            ans += (LL)qk * qv * (R-L+1);
            sum[o] += (LL)(R-L+1) * qk;
            add[o] += qk;
        }
        else if(minv[o] + qk >= K)
        {
            //debug("here");
            maxv[o] = K;
            minv[o] = K;
            ans += (LL)((R-L+1) * K - sum[o]) * qv;
            sum[o] = (R-L+1) * K;
            add[o] = 0;
            mask[o] = 1;
        }
        else
        {
            push_down(o, L, R, mid);
            Add(o<<1, L, mid);
            Add(o<<1|1, mid+1, R);
            push_up(o);
        }
        return;
    }
    push_down(o, L, R, mid);
    if(ql<=mid)
        Add(o<<1, L, mid);
    if(qr > mid)
        Add(o<<1|1, mid+1, R);
    push_up(o);
}

int main()
{
    int n, m, i;
    cin >> n >> K >> m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&l[i].l, &l[i].r, &l[i].c, &l[i].p);
    }
    sort(l+1,l+1+m);
    for(i=1;i<=m;i++)
    {
        ql = l[i].l, qr = l[i].r, qk = l[i].c, qv = l[i].p;
        //debug(ql);
        //debug(qr);
        //debug(qk);
        Add(1,1,n);
        //debug(ans);
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2018/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/