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
void solve(){
    ll n,k;cin>>n>>k;
    if(n<62 && k>(1ll<<(n-1))){
        cout<<-1<<"\n";
        return;
    }
    ll ans[n];
    ans[n-1]=n-1;
    for(ll i=0;i<n-1;i++){
        if(n-i>63){
            ans[i]=i;
            continue;
        }else{
            int j = 0;
            ll change = 1ll<<(n-i-j-2);
            while(k>change && i+j+1<n){
                k-=change;
                j++;
                if(j+i!=n-1){
                    change = 1ll<<(n-i-2-j);
                }else{
                    break;
                }
            }
            for(int p=0;p<=j;p++){
                ans[i+p]=i+j-p;
               
            }
            i=i+j;
        }
    }
    if(k!=1){
        cout<<-1<<"\n";
    }else{
        for(int i=0;i<n;i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<"\n";
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