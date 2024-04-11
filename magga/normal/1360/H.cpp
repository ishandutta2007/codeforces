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
set<ll>del;
ll l,r,curr;
void move_right(){
    curr++;
    r--;
    while(del.find(curr)!=del.end()){
        curr++;
    }
}
void move_left(){
    curr--;
    l--;
    while(del.find(curr)!=del.end()){
        curr--;
    }
}
void solve(){
    ll n,m,d;cin>>n>>m;
    del.clear();
    l = (1ll<<(m-1)) - 1 ;
    r = 1ll<<(m-1);
    curr = l;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        ll lst = curr;
        ll d = stoll(s,0,2);
        //cout<<lst<<" "<<d<<"\n";
        //cout<<l<<" "<<r<<"\n";
        del.insert(d);
        if(l==r && d==lst){
            move_left();
        }else if(l!=r && d==lst){
            move_right();
        }
        if(lst>d && l!=r){
            move_right();
        }else if(lst>d){
            l--;
        }
        if(lst<d && l==r){
           // cout<<"Yay"<<"\n";
            move_left();    
        }else if(lst<d){
            r--;
        }
        //cout<<curr<<"\n";
    }
    cout<<(bitset<62>(curr).to_string()).substr(62-m)<<"\n";
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