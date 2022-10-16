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
void solve(){
    int n;cin>>n;
    map<char,set<char>>s;
    string a,b;cin>>a>>b;
    bool flag = 1;
    for(int i =0;i<a.size();i++){
        if(b[i]<a[i]){
            flag = 0;
        }
        if(a[i]!=b[i])
            s[a[i]].insert(b[i]);
    }
    int ans = 0 ;
    while(s.size()!=0){
        ans++;
        auto k = *s.begin();
        s.erase(s.begin());
        auto p = *k.S.begin();
        for(auto t:k.S){
            if(t!=p){
                s[p].insert(t);
            }
        }
    }
    if(!flag){
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
    }
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