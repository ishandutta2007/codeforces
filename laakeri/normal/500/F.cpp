#include <iostream>
#include <vector>
#include <array>
#define F first
#define S second

using namespace std;

struct item{
    int c,h,a,b;
};

vector<pair<int, int> > qs[20001];
int v[20001];

void go(int l, int r, vector<item>&is, array<int, 4001>&dp, int maxv){
    vector<item> nis;
    int f=0;
    for (auto it:is){
        if (it.a<=l&&r<=it.b){
            f=1;
        }
        else if(!(it.a>r||it.b<l)){
            nis.push_back(it);
        }
    }
    if (f){
        array<int, 4001> ndp=dp;
        for (auto it:is){
            if (it.a<=l&&r<=it.b){
                for (int i=min(4000, maxv+it.c);i>0;i--){
                    if (i>=it.c) ndp[i]=max(ndp[i-it.c]+it.h, ndp[i]);
                }
                maxv+=it.c;
                maxv=min(4000, maxv);
            }
        }
        int mv=0;
        for (int i=0;i<=4001;i++){
            mv=max(mv, ndp[i]);
            ndp[i]=mv;
        }
        if (l==r){
            for (auto qq:qs[l]){
                v[qq.S]=ndp[qq.F];
            }
        }
        else{
            int m=(l+r)/2;
            go(l, m, nis, ndp, maxv);
            go(m+1, r, nis, ndp, maxv);
        }
    }
    else{
        if (l==r){
            for (auto qq:qs[l]){
                v[qq.S]=dp[qq.F];
            }
        }
        else{
            int m=(l+r)/2;
            go(l, m, nis, dp, maxv);
            go(m+1, r, nis, dp, maxv);
        }
    }
}

int main(){
    int n,p;
    cin>>n>>p;
    vector<item> is(n);
    for (int i=0;i<n;i++){
        cin>>is[i].c>>is[i].h>>is[i].a;
        is[i].b=is[i].a+p-1;
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        qs[a].push_back({b, i});
    }
    array<int, 4001> lol;
    for (int i=0;i<=4000;i++){
        lol[i]=0;
    }
    go(1, 20000, is, lol, 0);
    for (int i=0;i<q;i++){
        cout<<v[i]<<'\n';
    }
}