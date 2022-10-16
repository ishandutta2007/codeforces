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
void solve(){
    ll n,d;cin>>n;
    vector<ll>odd,even;
    for(int i=0;i<2*n;i++){
        cin>>d;
        if(d%2==0){
            even.push_back(i+1);
        }else{
            odd.push_back(i+1);
        }
    }
    if(odd.size()%2==1){
        odd.pop_back();
        even.pop_back();
    }
    for(int i=0;i<n-1;i++){
        if(odd.size()>0){
            cout<<odd.back()<<" ";
            odd.pop_back();
            cout<<odd.back()<<"\n";
            odd.pop_back();
        }else{
            cout<<even.back()<<" ";
            even.pop_back();
            cout<<even.back()<<"\n";
            even.pop_back();
        }
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