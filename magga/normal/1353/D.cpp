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
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
ll ans[200001];
void solve(){
    ll n;cin>>n;
    int j;
    priority_queue<pair<int,pii>>pq;
    pq.push({n,{0,n-1}});
    int val = 1;
    while(pq.size()!=0 && val!=(n+1)){
        auto i = pq.top();
        i.S.F*=-1;
        pq.pop();
        if(i.first%2==1){
            j = (i.S.F+i.S.S)/2;
        }else{
            j = (i.S.F+i.S.S-1)/2; 
        }
        ans[j]=val;
        val++;
        if(i.S.S-j>0){
            pq.push({i.S.S-j,{-1*(j+1),i.S.S}});
        }
        if(i.S.F<=j-1){
           pq.push({j-i.S.F,{-1*(i.S.F),j-1}}); 
        }
    }   
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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