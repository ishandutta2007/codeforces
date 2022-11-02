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
    map<int,int> m1,m2;
    int i,a;
    For(i,n){
        scanf("%d",&a);
        m1[a]++;
    }
    For(i,n-1){
        scanf("%d",&a);
        m2[a]++;
        m1[a]--;
        if(m1[a]==0){
            m1.erase(a);
        }
    }
    For(i,n-2){
        scanf("%d",&a);
        m2[a]--;
        if(m2[a]==0) m2.erase(a);
    }
    printf("%d\n%d",m1.begin()->x,m2.begin()->x);






    

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