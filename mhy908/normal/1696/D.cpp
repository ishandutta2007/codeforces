#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define svec(x) sort(all(x))
#define press(x) x.erase(unique(all(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF=1e9;
const LL LLINF=1e18;

int n;
int arr[250010], rev[250010];
int stk[250010], re, minl[250010], maxl[250010];

struct MINSEG{
    pii tree[1000010];
    void upd(int point, int s, int e, int num, int val){
        if(s==e){
            tree[point]=mp(val, s);
            return;
        }
        if(num<=(s+e)/2)upd(point*2, s, (s+e)/2, num, val);
        else upd(point*2+1, (s+e)/2+1, e, num, val);
        tree[point]=min(tree[point*2], tree[point*2+1]);
    }
    pii query(int point, int s, int e, int a, int b){
        //printf("point %d -> %d %d\n", point, tree[point].F, tree[point].S);
        if(e<a||s>b)return mp(INF, 0);
        if(a<=s&&e<=b)return tree[point];
        return min(query(point*2, s, (s+e)/2, a, b), query(point*2+1, (s+e)/2+1, e, a, b));
    }
}minseg;

struct MAXSEG{
    pii tree[1000010];
    void upd(int point, int s, int e, int num, int val){
        if(s==e){
            tree[point]=mp(val, s);
            return;
        }
        if(num<=(s+e)/2)upd(point*2, s, (s+e)/2, num, val);
        else upd(point*2+1, (s+e)/2+1, e, num, val);
        tree[point]=max(tree[point*2], tree[point*2+1]);
    }
    pii query(int point, int s, int e, int a, int b){
        if(e<a||s>b)return mp(-INF, 0);
        if(a<=s&&e<=b)return tree[point];
        return max(query(point*2, s, (s+e)/2, a, b), query(point*2+1, (s+e)/2+1, e, a, b));
    }
}maxseg;



void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        minseg.upd(1, 1, n, i, arr[i]);
        maxseg.upd(1, 1, n, i, arr[i]);
    }
    for(int i=1; i<=n; i++){
        while(re){
            if(arr[stk[re]]<arr[i])break;
            minl[stk[re]]=i;
            re--;
        }
        stk[++re]=i;
    }
    while(re){
        minl[stk[re]]=n+1;
        re--;
    }
    for(int i=1; i<=n; i++){
        while(re){
            if(arr[stk[re]]>arr[i])break;
            maxl[stk[re]]=i;
            re--;
        }
        stk[++re]=i;
    }
    while(re){
        maxl[stk[re]]=n+1;
        re--;
    }
    int nw=1, cnt=0;
    while(nw!=n){
        int lim;
        if(arr[nw]>arr[nw+1]){
            lim=maxl[nw]-1;
            nw=minseg.query(1, 1, n, nw, lim).S;
        }
        else{
            lim=minl[nw]-1;
            nw=maxseg.query(1, 1, n, nw, lim).S;
        }
        cnt++;
    }
    printf("%d\n", cnt);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}