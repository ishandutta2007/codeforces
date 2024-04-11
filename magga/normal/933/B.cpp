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
    ll p,k;cin>>p>>k;
    vector<long long int>v;
    while(p>0){
        v.push_back(p%k);
        p = p/k;
    }
    for(int i=0;i<v.size();i++){
        if(i%2==1 && v[i]!=0){
            v[i]=k-v[i];
            if(v.size()-1==i){
                v.push_back(0);
            }
            v[i+1]++;
        }else if(i%2==0 && v[i]>=k){
            v[i]-=k;
            if(v.size()-1==i){
                v.push_back(0);
            }
            v[i+1]++;
        }
    }
    cout<<v.size()<<"\n";
    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}