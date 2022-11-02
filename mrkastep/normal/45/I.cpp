#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;

void solve(int n){
    vector<int> p,ng;
    int i,a,mn1,mn2;
    bool g=true;
    For(i,n){
        scanf("%d",&a);
        if(a==0) continue;
        if(a>0){
            p.pb(a);
            continue;
        }
        ng.pb(a);
    }
    sort(all(ng));
    For(i,p.size()){
        printf("%d ",p[i]);
    }
    For(i,ng.size()/2*2){
        printf("%d ",ng[i]);
    }
    if(p.size()==0&&ng.size()==1&&n>1){
        printf("0");
        return;
    }
    if(p.size()==0&&ng.size()==1){
        printf("%d",ng[0]);
        return;
    }
    if(p.size()+ng.size()==0){
        printf("0");
        return;
    }




}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#else
    if(0){
        freopen("expedition.in","rt",stdin);
        freopen("expedition.out","wt",stdout);
    }
#endif
    int n,i;
    ll a;
    char c[300];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}