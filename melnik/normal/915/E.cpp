#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <time.h>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e7;
const int M = 1e6+1;
const int inf = 1e9;
const int base = 1e9+7;

using namespace std;

struct tree{
    int l,r,val;
};

struct qqqq{
    int l,r;
};

tree t[N];
qqqq q[N];
int n,m,it = 2;


inline void push(int v,ll tl,ll tr,char c){
    if (c == 'l' && q[v].l != 0 && t[v].l != 0){
        ll tm = (tl+tr) / 2;
        int l_ = t[v].l;
        t[l_].val = (tm-tl+1)*(q[v].l-1);
        q[l_].l = q[l_].r = q[v].l;
        q[v].l = 0;
    }

    if (c == 'r' && q[v].r != 0 && t[v].r != 0){
        int tm = (tl+tr) / 2;
        int r_ =  t[v].r;
        t[r_].val = (tr-tm)*(q[v].r-1);
        q[r_].l = q[r_].r = q[v].r;
        q[v].r = 0;
    }
}

inline void update(int v, ll tl, ll tr, ll l, ll r, int val){
    if (l > r) return;
    if (tl == l && tr == r){
        t[v].val = (tr-tl+1)*val;
        q[v].l = q[v].r = val+1;
        //push(v,tl,tr,'l');
        //push(v,tl,tr,'r');
        return;
    }
    ll tm = (tl + tr) / 2;
    ll tl_,tr_,l_,r_;
    tl_ = tl; tr_ = tm; l_ = l; r_ = min(r,tm);
    if (l_ <= r_){
        if (t[v].l == 0) t[v].l = it,it++;
        push(v,tl,tr,'l');
        update(t[v].l,tl,tm,l,min(r,tm),val);
    }

    tl_ = tm+1; tr_ = tr; l_ = max(l,tm+1); r_ = r;
    if (l_ <= r_){
        if (t[v].r == 0) t[v].r = it,it++;
        push(v,tl,tr,'r');
        update(t[v].r,tm+1,tr,max(l,tm+1),r,val);
    }
    push(v,tl,tr,'l');
    push(v,tl,tr,'r');
    l_ = t[v].l;
    r_ = t[v].r;
    int cur = 0;
    if (l_ != 0) cur += t[l_].val;
    if (q[v].l != 0 && l_ == 0) cur += (tm-tl+1)*(q[v].l-1);
    if (r_ != 0) cur += t[r_].val;
    if (q[v].r != 0 && r_ == 0) cur += (tr-tm)*(q[v].r-1);
    t[v].val = cur;
}

int main()
{
    //freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i = 0; i < m; i++) {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        l--;r--;
        update(1,0,n-1,l,r,abs(k-2));
        printf("%d\n",n-t[1].val);
    }

}