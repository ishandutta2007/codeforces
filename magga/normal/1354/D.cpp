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
const int N = 1<<20+1;
int n=N;
int t[2*N]{0};
int combine(int &a,int &b){
    return a+b;
}
void build(){
    for(int i=n-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void modify(int p,int value){
    for(t[p+=n]=value;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
void query(int l){
    int ret = 0;
    int curr = 1;
    while(curr<n){
        curr*=2;
        //cout<<t[curr]<<" "<<l<<"\n";
        if(ret+t[curr]>=l){
            continue;
        }else{
            ret+=t[curr];
            curr|=1;
        }
    }
    //cout<<curr-n<<"\n";
    modify(curr-n,t[curr]-1);
}
void pre(){}
void solve(){
    int no,m,d;cin>>no>>m;
    for(int i=0;i<no;i++){
        cin>>d;
        t[n+d]++;
    }
    build();
    for(int i=0;i<m;i++){
        cin>>d;
        if(d>0){
            modify(d,t[d+n]+1);
        }else{
            query(-1*d);
        }
    }
    for(int i=1;i<=1e6;i++){
        if(t[n+i]!=0){
            cout<<i<<"\n";
            return;
        }
    }
    cout<<0<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}