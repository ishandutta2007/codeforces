#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define ll long long int
#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

const int mod=1e9+7;
const int INF=2e9;
const ll LONGINF=4e18;


map<int,int> m;

void solve(int n){
    int k,a,q,c[5555],ans,t;
    scanf("%d",&k);
    For(i,n){
        scanf("%d",&a);
        c[i]=a;
        FOR(j,1,k+1){
            if(m[a*j]==0){
                m[a*j]=INF;
            }
            m[a*j]=min(m[a*j],j);
        }
    }
    scanf("%d",&q);
    For(i,q){
        ans=INF;
        scanf("%d",&a);
        For(j,n){
            For(h,k+1){
                t=m[a-c[j]*h];
                if(t!=0){
                    ans=min(ans,t+h);
                }
            }
        }
        if(ans>k){
            printf("-1\n");
        }
        else{
            printf("%d\n",ans);
        }
    }



}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    string s;
    while(scanf("%d",&n)==1){
        solve(n);
        printf("\n");
    }



    return 0;
}