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
#define MAXN   200001 
int spf[MAXN];  
void sieve(){ 
    spf[1] = 1; 
   // prime.pb(2);
    for (int i=2; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++){  
        if (spf[i] == i){  
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}  
ll oo;
map<int,int> getFactorization(int x){ 
    map<int,int> ret; 
    while (x != 1){
        oo =spf[x];
        while(x%oo==0){
            ret[spf[x]]++; 
            x = x / spf[x];
        } 
    } 
    return ret; 
}
void pre(){}
void solve(){
        ll n;cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        map<int,multiset<int>>m;
        for(int i=0;i<n;i++){
            auto h = getFactorization(arr[i]);
            for(auto i:h){
                m[i.first].insert(i.second);
            }
        }
        ll ans = 1;
        for(auto &i:m){
            if(i.second.size()<n-1){
                continue;
            }
            auto y = i.second.begin();
            oo = *y;
            y++;
            if(y!=i.second.end() && i.second.size()==n){
                oo=*y;
            }
            //cout<<i.first<<" "<<oo<<"\n";    
            ans*=pow((ll)i.first,oo);    
        }
        cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}