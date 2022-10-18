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
// Please write the recurances once :(
// Don't write trash code
const long long int N = 2e4+10;
long long int tot;
long long int t[2*N];
long long int combine(long long int a,long long int b){
    return max(a,b);
}
void build(){
    for(long long int i=tot-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void modify(long long int p,long long int value){
    for(t[p+=tot]=value;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
long long int query(long long int l,long long int r){
    long long int ret = 0;
    for(l+=tot,r+=tot;l<r;l>>=1,r>>=1){
        if(l&1) ret=combine(ret,t[l++]);
        if(r&1) ret=combine(t[--r],ret);
    }
    return ret;
}
void pre(){}
void solve(){
    int n,k;cin>>n>>k;
    tot = n*k+1;
    int arr[tot];
    for(int i=1;i<tot;i++) cin>>arr[i];
    map<int,pii>m;
    map<int,int>curr;
    set<int>dealt;
    for(int i=1;i<tot;i++){
        if(curr.find(arr[i])!=curr.end()){
            //cout<<"bayaa "<<i<<"\n";
            auto p = curr[arr[i]];
            auto ma = query(p,i+1);
            //cout<<p<<" "<<ma<<"\n";
            if(ma==((n+k-2)/(k-1))){
                curr[arr[i]]=i;
            }else{
                //cout<<"aayaa "<<i<<"\n";
                for(int j=p;j<=i;j++)
                    modify(j,query(j,j+1)+1);
                curr.erase(arr[i]);
                m[arr[i]] = {p,i};
                dealt.insert(arr[i]);
            }
        }else if(dealt.find(arr[i])==dealt.end()){
            curr[arr[i]]=i;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<m[i].F<<" "<<m[i].S<<"\n";
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