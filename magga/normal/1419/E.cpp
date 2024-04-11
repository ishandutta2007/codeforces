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
vector<long long int>primes;
set<long long int>divisors;
long long int n;
void calc_primes(){
    long long int a = sqrt(n);
    long long int m = n;
    primes.clear();
    for(long long int i=2;i<=a;i++){
        if(m%i==0){
            primes.push_back(i);
        }
        while(m%i==0){
            m/=i;
        }
    }
    if(m>1){
        primes.push_back(m);
    }
}
void calc_divisors(){
    long long int a = sqrt(n);
    long long int m = n;
    divisors.clear();
    for(long long int i=2;i<=a;i++){
        if(m%i==0){
            divisors.insert(i);
            divisors.insert(n/i);
        }
    }
    divisors.insert(n);
}
void solve(){
    cin>>n;
    calc_primes();
    calc_divisors();
    long long int pans = 0;
    vector<long long int>ans;
    if(primes.size()!=1){
        ans.push_back(primes[0]*primes.back());
        divisors.erase(primes[0]*primes.back());
    }
    for(int i=0;i<primes.size()-1;i++){
        bool flag = 0;
        long long int oo = primes[i]*primes[i+1];
        if(divisors.find(oo)!=divisors.end()){
            divisors.erase(oo);
            flag = 1;
        }else{
            pans++;
            flag = 0;
        }
        set<long long int> k=divisors;
        for(auto j:k){
            if(j%primes[i]==0){
                ans.push_back(j);
                divisors.erase(j);
            }
        }
        if(flag){
            ans.push_back(oo);
        }
    }
    for(auto i:divisors){
        ans.push_back(i);
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
    pans = 0;
    for(int i=0;i<ans.size();i++){
        if(__gcd(ans[i],ans[(i+1)%ans.size()])==1){
            pans++;
            //cout<<i<<" ";
        }
    }
    cout<<pans<<"\n";
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