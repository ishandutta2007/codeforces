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
bool is_sorted(vector<int>a,int i){
    if(i==1){
        reverse(a.begin(),a.end());
    }
    for(int i=1;i<a.size();i++){
        if(a[i]<a[i-1])
            return false;
    }
    return true;
}
void simulate(vector<int>&a,vector<int>curr){
    vector<int> b = a;
    vector<int> o;
    vector<vector<int>>v;
    int i =0;
    for(int j=0;j<curr.size();j++){
        v.push_back(o);
        for(int k=0;k<curr[j];k++){
            v[v.size()-1].push_back(a[i]);
            i++;
        }
    }
    a.clear();
    for(int i=v.size()-1;i>=0;i--){
        for(auto j:v[i]){
            a.push_back(j);
        }
    }
}
void solve(){
    int n,d;cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        cin>>d;
        a.push_back(d);
    }
    vector<vector<int>>ans;
    int i = 0;
    while(! (is_sorted(a,0)|is_sorted(a,1)) ){
        auto b = a;
        if(i%2==1){
            reverse(b.begin(),b.end());
        }
        vector<int>curr;
        int t = b[0],count = 1;
        for(int i=1;i<n;i++){
            if(b[i]>t){
                curr.push_back(count);
                count=1;
                t = b[i];
            }else{
                count++;
            }
        }
        curr.push_back(count);
        if(i%2==1){
            reverse(curr.begin(),curr.end());
        }
        simulate(a,curr);
        if(curr.size()!=1)
        ans.push_back(curr);
        i++;
    }
    if(!is_sorted(a,0)){
        vector<int>a;
        for(int i=0;i<n;i++)
            a.push_back(1);
        ans.push_back(a);
    }
    cout<<ans.size()<<"\n";
    for(auto j:ans){
        cout<<j.size()<<" ";
        for(auto k:j){
            cout<<k<<" ";
        }
        cout<<"\n";
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