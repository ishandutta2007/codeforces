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
    string s;cin>>s; 
    ll ans = s.size()-2;   
    ll n = s.size();
    for(int i=0;i<10;i++){
        for(int j = 0;j<10;j++){
            ll curr = 0;
            bool flag = 0;
            for(int k = 0;k < s.size();k++){
                if(!flag){
                    if( (s[k]-'0') == i){
                        flag = 1;
                    }else{
                        curr++;
                    }
                }else{
                    if( (s[k]-'0')==j ){
                        flag = 0;
                    }else{
                        curr++;
                    }
                }
            }
            if(i!=j && (n-curr)%2==1 ){
                curr++;
            }
            ans = min(ans,curr);
        }
    }
    cout<<ans<<"\n";
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