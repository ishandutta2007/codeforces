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
vector<long long int>v;
vector<long long int>b;
long double o  = 1.0;
long double calc(long double t,vector<long long int>&a){
    long double s = 1,ret=0;
    for(int i=1;i<a.size();i++){
        ret+=min( (a[i]-a[i-1])*o , t*s );
        t -= min(t, (a[i]-a[i-1])/s );
        if(t<=0.000){
            break;
        }
        s+=1;
    }
    return ret;
}
void solve(){
    long long int n,l,k;cin>>n>>l;
    v.clear();
    b.clear();
    v.push_back(0);
    b.push_back(0);
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
        b.push_back(l-k);
    }
    sort(v.begin(),v.end());
    sort(b.begin(),b.end());
    v.push_back(l);
    b.push_back(l);
    long double start = 0,end = 1e10,mid;
    while(abs(start-end)>1e-8){
        mid = (start+end)/2;
        if(calc(mid,v) + calc(mid,b) < l ){
            start = mid;
        }else{
            end = mid;
        }
    }
    cout<<setprecision(20)<<start<<"\n";
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