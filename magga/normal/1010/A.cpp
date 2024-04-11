#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long double,long double>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
ll n,m;
pii arr[1000];
bool check(long double a){
    long double curr = a;
    for(int i=0;i<n;i++){
        curr -= (curr+m)/arr[i].F;
        if(curr<-0.0000000001){
            return false;
        }
        curr -= (curr+m*1.0)/arr[(i+1)%n].S;
        if(curr<-0.0000000001){
            return false;
        }
    }
    return true;
}
void solve(){
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i].F>>arr[i].S;
    }   
    long double start = 0,end = 1e9,mid,ans=-1;
    while(end-start>=0.00000001){
        mid = (start+end)/2;
        if(check(mid)){
            ans = mid;
            end =  mid;
        }else{
            start=mid;
        }
    }
    cout<<setprecision(20)<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}