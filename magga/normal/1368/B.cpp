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
    ll k;cin>>k;
    ll ans = 1;
    ll curr = 1;
    while(ans<k){
        curr++;
        ans = pow(curr,10);
    }
    vector<ll>oo;
    for(int i=0;i<10;i++){
        oo.push_back(curr);
    }
    ll val; 
    for(int i = 0 ; i < 10; i++ ){
        val = ans/oo[i];
        val*=oo[i]-1;
        if(val>=k){
            oo[i]--;
        }else{
            break;
        }
        ans = val;
    }
    string s = "codeforces";
    for(int i=0;i<10;i++){
        for(int j=0;j<oo[i];j++){
            cout<<s[i];
        }
    }
    cout<<"\n";
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