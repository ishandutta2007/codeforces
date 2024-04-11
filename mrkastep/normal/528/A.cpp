#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;





void solve(int a){
    map<int,int> rh,rv,h,v;
    map<int,int>::iterator it;
    pair<int,int> p1,p2;
    int i,b,c,n,l;
    ll ans;
    scanf("%d%d",&b,&n);
    getchar();
    rh[0]=1;
    rh[b]=1;
    rv[0]=1;
    rv[a]=1;
    h[b]=1;
    v[a]=1;
    For(i,n){
        if(getchar()=='H'){
            scanf("%d",&c);
            rh[c]=1;
            it=rh.find(c);
            p1=*(next(it));
            p2=*(prev(it));
            h[p1.x-p2.x]--;
            if(h[p1.x-p2.x]==0) h.erase(p1.x-p2.x);
            h[c-p2.x]++;
            h[p1.x-c]++;
        }
        else{
            scanf("%d",&c);
            rv[c]=1;
            it=rv.find(c);
            p1=*(next(it));
            p2=*(prev(it));
            v[p1.x-p2.x]--;
            if(v[p1.x-p2.x]==0) v.erase(p1.x-p2.x);
            v[c-p2.x]++;
            v[p1.x-c]++;
        }
        printf("%I64d\n",(ll)h.rbegin()->x*v.rbegin()->x);
        getchar();
    }








#ifdef HOME
    printf("\n\nTime in ms: %.0lf\n",clock()/CLOCKS_PER_SEC*1000);
#endif
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[200200];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}