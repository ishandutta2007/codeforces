
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
ll arr[1001];
ll ans[1001][1001]{0};
ll maa[1001][1001]{0};
ll sum[1001][1001]{0};
bool vis[1001][1001]{0};
pair<ll,pii>calc(int i,int j){
    if(i>j)
        return {0,{0,0}};
    if(i==j)
        return {0,{min(0ll,arr[i]),arr[i]}};
    if(vis[i][j])
        return {ans[i][j],{maa[i][j],sum[i][j]}};
    vis[i][j]=1;
    auto prev = calc(i+1,j-1);
    sum[i][j]=prev.S.S+arr[i]+arr[j];
    maa[i][j]=min(0ll,min(sum[i][j],prev.S.F+arr[i]));
    if(arr[i]>0){
        ans[i][j]=arr[i];
        if(ans[i][j]+prev.S.F<0){
            ans[i][j]=0;
            return {ans[i][j],{maa[i][j],sum[i][j]}};
        }
        ans[i][j]=max(0ll,ans[i][j]+prev.S.F);
        
        ll new_sum = prev.S.S + arr[i] - ans[i][j];
        if(arr[j]+new_sum>0){
            ans[i][j]=0;
            return {ans[i][j],{maa[i][j],sum[i][j]}};
        }
        if(i+1!=j)
            ans[i][j]=min(-1*(arr[j]+new_sum),ans[i][j])+1;
        else 
            ans[i][j]=min(-1*(arr[j]+new_sum),ans[i][j]);
    }else{
        ans[i][j]=0;
    }
    return {ans[i][j],{maa[i][j],sum[i][j]}}; 
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i%2==1) arr[i]*=-1;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         ans[i][j]=0;
    //         maa[i][j]=0;
    //         sum[i][j]=0;
    //     }
    // }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans += calc(i,j).first;
            //cout<<calc(i,j).first<<" "<<calc(i,j).second.first<<" "<<calc(i,j).second.second<<" "<<i<<" "<<j<<"\n";
        }
        //cout<<"\n";
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}