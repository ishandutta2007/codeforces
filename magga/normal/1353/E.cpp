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
ll a,b;
ll ans;
ll oo;
string arr[1000000];
void evalv(string &s){
    a=0;b=0;
    for(int i=1;i<=s.size();i++){
        if(s[i-1]=='0'){
            a++;
        }else{
            if(a>=b){
                a=0;b=0;
            }
            b++;
            ans=min(ans,oo-b+a);
        }
    }
}
void solve(){
    oo=0;
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    for(int i=0;i<k;i++){
        arr[i]="";
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            oo++;
        }
        arr[i%k]+=s[i];
    }
    ans = oo;
//cout<<oo<<"====\n";
    for(int i=0;i<k;i++){
        evalv(arr[i]);
  //      cout<<arr[i]<<" "<<ans<<"\n";
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