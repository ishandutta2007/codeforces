#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <time.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define ll long long int
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const ll LONGINF=4e18;

template<typename T>void swap(T *x1,T *x2){
    T t;
    t=*x1;
    *x1=*x2;
    *x2=t;
}





void solve(int n){
    map<int,int> m;
    auto it=m.begin();
    int i,a,l,r,s,j;
    vector<pair<int,int>> v;
    vector<int> one;
    vector<vector<int>> ans;
    For(i,n){
        scanf("%d",&a);
        m[a]++;
    }
    for(it=m.begin();it!=m.end();it++){
        v.pb(mp(it->second,it->first));
    }
    sort(all(v));
    s=v.size();
    a=0;
    while(1){
        if(s<3||v[s-3].x<=0) break;
        a++;
        v[s-1].x--;
        v[s-2].x--;
        v[s-3].x--;
        one.pb(v[s-1].y);
        one.pb(v[s-2].y);
        one.pb(v[s-3].y);
        sort(all(one));
        ans.pb(one);
        one.clear();
        For(i,3){
            if(s>3&&v[s-3+i].x<v[s-4+i].x){
                l=0;
                r=s-3+i;
                while(r-l>1){
                    int c=(l+r)/2;
                    if(v[c].x==v[s-4+i].x) r=c;
                    else l=c;
                }
                if(v[l].x==v[s-4+i].x){
                    swap(&v[l],&v[s-3+i]);
                }
                else{
                    swap(&v[r],&v[s-3+i]);
                }
            }
        }
    }
    printf("%d",a);
    For(i,a){
        printf("\n");
        For(j,3){
            printf("%d ",ans[i][2-j]);
        }
    }



#ifndef ONLINE_JUDGE
    printf("\n\nTime in ms: %.0lf",(double)clock() / CLOCKS_PER_SEC * 1000);
#endif
}


int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}