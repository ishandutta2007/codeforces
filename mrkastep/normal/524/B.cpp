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

bool srt(pair<int,int> a,pair<int,int> b){
    return a>b;
}

void solve(int n){
    if(n==0){
        printf("0");
        return;
    }
    vector<pair<ll,ll>> a(n);
    vector<ll> mxh(n);
    ll answ=0,ansh=0,ans=LONGINF,H=0;
    int t;
    For(i,n){
        scanf("%I64d%I64d",&a[i].x,&a[i].y);
        if(a[i].y>a[i].x){
            t=a[i].x;
            a[i].x=a[i].y;
            a[i].y=t;
        }
    }
    sort(all(a),srt);
    For(i,n){
        answ+=a[i].y;
    }
    ansh=a[0].x;
    mxh[0]=a[0].y;
    FOR(i,1,n){
        mxh[i]=max(mxh[i-1],a[i].y);
    }
    ans=answ*ansh;
    For(i,n){
        ansh=max(mxh[i],((i<n-1)?a[i+1].x:0));
        answ-=a[i].y;
        answ+=a[i].x;
        ans=min(ans,answ*ansh);
        if(i<n-1){
            if(ansh==a[i].y&&ansh>a[i+1].y){
                H=ansh;
            }
        }
    }
    printf("%I64d",ans);
    
        




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