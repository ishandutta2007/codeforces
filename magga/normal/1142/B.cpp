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
const long long int N = 2e5;
long long int n1;
long long int t[2*N];
long long int combine(long long int &a,long long int &b){
    return min(a,b);
}
void build(){
    for(long long int i=n1-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void modify(long long int p,long long int value){
    for(t[p+=n1]=value;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
long long int query(long long int l,long long int r){
    long long int ret = 2*n1;
    for(l+=n1,r+=n1;l<r;l>>=1,r>>=1){
        if(l&1) ret=combine(ret,t[l++]);
        if(r&1) ret=combine(t[--r],ret);
    }
    return ret;
}
void pre(){}
ll val[200000+1];
ll arr[200000];
ll brr[200000];
ll oo[200000];
ll st[200000][20];
ll n,m,q;
map<ll,ll>opsie;
void dfs(){
    for(ll i=0;i<m;i++)
        st[i][0]=oo[i];
    for(int i=1;i<19;i++){
       for(ll j=0;j<m;j++)
            st[j][i]=2*m;    
    }
    for(int i=1;i<19;i++){
       for(ll j=0;j<m;j++)
            st[j][i]=min(st[j][i],st[min(st[j][i-1],m-1)][i-1]); 
    }
    vector<int>v;
    string s = bitset<60>(n-1).to_string();
    reverse(s.begin(),s.end());
    for(int i=0;i<60;i++){
        if(s[i]=='1'){
            v.pb(i);
        }
    }
    for(int i=0;i<m;i++){
        int curr = i;
        for(auto i:v){
            if(curr==2*m)
                break;
            curr=st[curr][i];
        }
        t[m+i]=curr;
    }
}
void solve(){
    cin>>n>>m>>q;
    n1=m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        val[arr[i]]=i;
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    map<ll,ll>cac;
    for(int i=m-1;i>=0;i--){
        ll next = arr[(val[brr[i]]+1)%n];
        if(cac.find(next)!=cac.end()){
            oo[i]=cac[next]; 
        }else{
            oo[i]=2*m;
        }
        cac[brr[i]]=i;
    }
    dfs();
    build();
    ll u,v;
    for(int i=0;i<q;i++){
        cin>>u>>v;
        u--;v--;
        auto j = query(u,v+1);
        if(j<=v){
            cout<<1;
        }else{
            cout<<0;
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