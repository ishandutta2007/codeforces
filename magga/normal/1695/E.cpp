#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
multiset<ll>arr[2][600001];
multiset<ll>fre[2][600001];
vector<ll>et;
void eulerTour(int i,int depth){
    while(arr[depth][i].size()>0){
        int to = (*arr[depth][i].begin());
        arr[depth][i].erase(arr[depth][i].find(to));
        arr[depth][to].erase(arr[depth][to].find(i));
        arr[1-depth][i].erase(arr[1-depth][i].find(to));
        arr[1-depth][to].erase(arr[1-depth][to].find(i));
        fre[1-depth][to].insert(i);
        eulerTour(to,1-depth);
         et.push_back(i);
    }
    while(fre[depth][i].size()>0){
        int to = (*fre[depth][i].begin());
        fre[depth][i].erase(fre[depth][i].find(to));
        eulerTour(to,1-depth);
         et.push_back(i);
    }
}
void solve(){
    int n,a,b;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr[1][a].insert(b);
        arr[0][a].insert(b);
        arr[1][b].insert(a);
        arr[0][b].insert(a);
    }
    vector<pii>grid;
    vector<pair<char,char>>monocarp,polycarp;
    for(int i=1;i<=2*n;i++){
        if(arr[0][i].size()==0) continue;
        et.clear();
        eulerTour(i,0);
        if(et.size()==2){
            cout<<-1<<"\n";
            return;
        }
        int t = et.size()/2;
        vector<pii>grid2(t);
        for(int i=0;i<et.size();i++){
            if(i<t){
                grid2[i].F = et[i];
            }else{
                grid2[2*t-i-1].S = et[i];
            }
        }
        for(auto i:grid2){
            grid.push_back(i);
        }
        if(t&1){
            monocarp.push_back({'U','D'});
            for(int i=1;i<=t/2;i++){
                monocarp.push_back({'L','L'});
                monocarp.push_back({'R','R'});
            } 
            for(int i=1;i<=t/2;i++){
                polycarp.push_back({'L','L'});
                polycarp.push_back({'R','R'});
            }  
            polycarp.push_back({'U','D'});
        }else{
            for(int i=0;i<t/2;i++){
                monocarp.push_back({'L','L'});
                monocarp.push_back({'R','R'});
            } 
            polycarp.push_back({'U','D'});
            for(int i=0;i<(t/2)-1;i++){
                polycarp.push_back({'L','L'});
                polycarp.push_back({'R','R'});
            }  
            polycarp.push_back({'U','D'});
        }
        et.clear();
    }
    cout<<2<<" "<<n<<"\n";
    for(auto i:grid) cout<<i.F<<" ";
    cout<<"\n";
    for(auto i:grid) cout<<i.S<<" ";
    cout<<"\n";
    for(auto i:monocarp) cout<<i.F;
    cout<<"\n";
    for(auto i:monocarp) cout<<i.S;
    cout<<"\n";
    for(auto i:polycarp) cout<<i.F;
    cout<<"\n";
    for(auto i:polycarp) cout<<i.S;
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}