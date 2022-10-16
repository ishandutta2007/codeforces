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
struct node{
    ll suff[20]{0},pref[20]{0};
    bool fill[20]{0};
    ll ans[20]{0};
};
const long long int N = 2e5;
long long int n;
node t[2*N];
ll val = 0;
node combine(node &a,node &b){
    node ol;
    for(int i=0;i<20;i++){
        if(a.fill[i] && b.fill[i]){
            ol.fill[i]=1;
            ol.suff[i]=a.suff[i]+b.suff[i];
            ol.pref[i]=a.pref[i]+b.pref[i];
            ol.ans[i]=a.ans[i]+b.ans[i];
        }else if(!a.fill[i] && b.fill[i]){
            ol.fill[i]=0;
            ol.suff[i]=a.suff[i]+b.pref[i];
            ol.pref[i]=a.pref[i];
            ol.ans[i]=a.ans[i]+b.ans[i];
        }else if(a.fill[i] && !b.fill[i]){
            ol.fill[i]=0;
            ol.suff[i]=b.suff[i];
            ol.pref[i]=a.suff[i]+b.pref[i];
            ol.ans[i]=a.ans[i]+b.ans[i];
        }else{
            ol.fill[i]=0;
            ol.suff[i]=b.suff[i];
            ol.pref[i]=a.pref[i];
            val = a.suff[i]+b.pref[i]; 
            ol.ans[i]=a.ans[i]+b.ans[i]+(val*(val+1))/2;
        }
    }
    return ol;
}
void build(){
    for(long long int i=n-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void modify(long long int p,node value){
    for(t[p+=n]=value;p>1;p>>=1){
        if(p<(p^1)){
            t[p>>1]=combine(t[p],t[p^1]);
            //cout<<p<<" "<<(p^1)<<"\n";
        }else{
            t[p>>1]=combine(t[p^1],t[p]);
        }
        
    } 
}
ll va(ll n){
    return (n*(n+1))/2;
}
ll cach[20];
void pre(){
    cach[0]=1;
    for(int i=1;i<20;i++){
        cach[i]=cach[i-1]*2;
    }
}
void solve(){
    ll no,mo,m,u,v;cin>>no>>m;
    mo=no;
    int j = 0;
    while(mo!=0){
        mo/=2;
        j++;
    }
    n = 1<<j;
    ll arr[no];
    for(int i=0;i<no;i++){
        cin>>arr[i];
    }
    string s;
    for(int i=0;i<no;i++){
        s=bitset<20>(arr[i]).to_string();
        reverse(s.begin(),s.end());
        for(int j=0;j<20;j++){
            if(s[j]=='1'){
                t[n+i].fill[j]=1;
                t[n+i].suff[j]=1;
                t[n+i].pref[j]=1;
            }else{
                t[n+i].fill[j]=0;
                t[n+i].suff[j]=0;
                t[n+i].pref[j]=0;
            }
        }
    }
    build();
    ll ans = 0;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        node lo;
        ans=0;
        s=bitset<20>(v).to_string();
        reverse(s.begin(),s.end());
        for(int j=0;j<20;j++){
            if(s[j]=='1'){
                lo.fill[j]=1;
                lo.suff[j]=1;
                lo.pref[j]=1;
            }else{
                lo.fill[j]=0;
                lo.suff[j]=0;
                lo.pref[j]=0;
            }
        }
        modify(u-1,lo);
        for(int i=0;i<20;i++){
            ans+=t[1].ans[i]*cach[i];
            //cout<<t[1].pref[i]<<" "<<t[1].suff[i]<<"\n";
            ans+=va(t[1].suff[i])*cach[i];
            if(!t[1].fill[i]){
                ans+=va(t[1].pref[i])*cach[i];
            }
        }
        cout<<ans<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}