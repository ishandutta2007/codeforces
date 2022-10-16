#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
    ll n;cin>>n;
    int o = 0;
    ll n1 = n+1;
    while(n1!=0){
        n1/=2;
        o++;
    }
    ll q;cin>>q;
    ll curr,bi;
    string s;
    o--;
    for(int i=0;i<q;i++){
        cin>>curr>>s;
        string a = bitset<63>(curr).to_string();
        reverse(a.begin(),a.end()); 
        bi=0;
        while(a[bi]=='0'){
            bi++;
        }
        for(auto i:s){
            if(i=='U'){
                if(bi==o-1){
                    continue;
                }
                a[bi]='0';
                a[bi+1]='1';
                bi++;
            }else if(i=='L'){
                if(bi==0){
                    continue;
                }
                a[bi]='0';
                a[bi-1]='1';
                bi--;
            }else{
                if(bi==0){
                    continue;
                }
                a[bi]='1';
                a[bi-1]='1';
                bi--;
            }
        }
        ll ret= 0;
        for(int i=0;i<63;i++){
            if(a[i]=='1'){
                ret+=(ll)1<<i;
            }
        }
        cout<<ret<<"\n";
    }
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