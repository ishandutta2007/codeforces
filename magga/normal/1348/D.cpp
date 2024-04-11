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
int fi(ll n){
    string s = bitset<30>(n).to_string();
    int j = 0;
    while(s[j]=='0'){
        j++;
    }
    j= 30 - j;
    return j;
}
void solve(){
    ll n;
    cin>>n;
    string s = bitset<30>(n).to_string();
    int j = fi(n);
    reverse(s.begin(),s.end());
    vector<int>v;
    ll curr = 1;
    ll boo = n;
    ll val = 1;
    for(int i=0;i<j;i++){
        v.push_back(-1);
        v.push_back(val);
        val*=2;
        curr+=val;
    }
    int k = fi(  n - (1<<(j-1))+1);
    if(k==2*val){
        v.push_back(val);
    }else{
        ll p = n - (1<<(j-1))+1;
        ll oo = p - (1<<(k-1));
        v[2*(k-1)]=oo;
        v[2*(k-1)+1]-=oo;
        cout<<j-1<<"\n";
    }   
    curr = 1;
    val = 1;
    for(auto i:v){
        if(curr==n){
            break;
        }
        if(i!=-1){
            val+=i;
            curr+=val;
            cout<<i<<" ";
        }
        //if(i!=-1)
          //  cout<<i<<" ";
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