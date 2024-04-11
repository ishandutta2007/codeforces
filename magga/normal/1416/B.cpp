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
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int sum = 0;
    long long int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
        sum+=arr[i+1];
    }
    if(sum%n!=0){
        cout<<-1<<"\n";
        return;
    }
    sum/=n;
    vector<pair<int,pii>>ans;
    for(long long int i=2;i<=n;i++){
        ans.push_back({ 1 , { i , (i - (arr[i]%i))%i }});
        ans.push_back({ i , { 1 , (arr[i]+i-1)/i }});
    }
    for(int i=2;i<=n;i++){
        ans.push_back({1,{i,sum}});
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.F<<" "<<i.S.F<<" "<<i.S.S<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}