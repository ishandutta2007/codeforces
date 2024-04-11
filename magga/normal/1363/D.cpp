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
set<int>arr[1001];
void query(vector<int>&s){
    cout<<"? "<<s.size()<<" ";
    for(int i:s){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout.flush();
}
void ans(vector<int>&ans){
    cout<<"!"<<" ";
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout.flush(); 
}
void pre(){}
void solve(){
    ll n,k,f,d;cin>>n>>k;
    for(int i=0;i<=k;i++){
        arr[i].clear();
    }
    for(int i=0;i<k;i++){
        cin>>f;
        for(int j=0;j<f;j++){
            cin>>d;
            arr[i+1].insert(d);
        }
    }
    vector<int>ell;
    for(int i=0;i<k;i++){
        ell.pb(i+1);
    }
    vector<int>se;
    for(int i=0;i<n;i++){
        se.pb(i+1);
    }
    query(se);
    ll ma;
    cin>>ma;
    while(ell.size()!=1){
        se.clear();
        for(int i=0;i<ell.size()/2;i++){
            for(auto j:arr[ell[i]]){
                se.pb(j);
            }
        }
        query(se);
        cin>>d;
        if(d==ma){
            int oo = ell.size()/2;
            while(ell.size()!=oo){
                ell.pop_back();
            }
            continue;
        }
        vector<int>re;
        for(int i=ell.size()/2;i<ell.size();i++){
            re.pb(ell[i]);
        }
        ell = re;
    }
    se.clear();
    for(int i=1;i<=n;i++){
        if(arr[ell[0]].find(i)==arr[ell[0]].end()){
            se.pb(i);
        }
    }
    if(se.size()!=0){
        query(se);
        cin>>d;
    }else{
        d=0;
    }
    se.clear();
    for(int i=1;i<=k;i++){
        if(i==ell[0]){
            se.pb(d);
        }else{
            se.pb(ma);
        }
    }
    ans(se);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
        string s;
        cin>>s;
    }   
}