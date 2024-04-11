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
vector<vector<ll>>arr;
vector<vector<bool>>flag;
int n,m;
int counter = 0;
int check(int i,int j){
    if(i<=0 || j<=0 || i>=n+1 || j>=m+1) return 0;
    if(arr[i][j]>arr[i-1][j]) return 0;
    if(arr[i][j]>arr[i+1][j]) return 0;
    if(arr[i][j]>arr[i][j-1]) return 0;
    if(arr[i][j]>arr[i][j+1]) return 0;
    return 1;
}
void remove(int i,int j){
    int upperleft = max(i-1,1);
    int upperRight = min(i+1,n);
    int lowerleft = max(j-1,1);
    int lowerRight = min(j+1,m);
    for(int a=upperleft;a<=upperRight;a++){
        for(int b=lowerleft;b<=lowerRight;b++){
            if(flag[a][b]){
                counter-=check(a,b);
                flag[a][b]=false;
            }
        }
    }
}
void add(int i,int j){
    int upperleft = max(i-1,1);
    int upperRight = min(i+1,n);
    int lowerleft = max(j-1,1);
    int lowerRight = min(j+1,m);
    for(int a=upperleft;a<=upperRight;a++){
        for(int b=lowerleft;b<=lowerRight;b++){
            if(!flag[a][b]){
                counter+=check(a,b);
                flag[a][b]=true;
            }
        }
    }
}
void swaps(int i,int j,int x,int y){
    remove(i,j);
    remove(x,y);
    swap(arr[i][j],arr[x][y]);
    add(i,j);
    add(x,y);
}
void solve(){
    cin>>n>>m;
    arr.assign(n+2,vector<ll>(m+2,1e9));
    flag.assign(n+2,vector<bool>(m+2,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
    pii ref = {0,0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int k = check(i,j);
            flag[i][j]=1;
            if(k==1 && arr[i][j]!=1) ref = {i,j}; 
            counter+=k;
        }
    if(counter==1){
        cout<<0<<"\n";
        return;
    }
    vector<pii>candidates({ref,{ref.F+1,ref.S},{ref.F-1,ref.S},{ref.F,ref.S+1},{ref.F,ref.S-1}});
    int elligibleSwaps = 0;
    for(auto p:candidates){
        if(p.F>0 && p.S>0 && p.F<=n && p.S<=m){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(abs(ref.F-i)+abs(ref.S-j)<2) continue;
                    swaps(i,j,p.F,p.S);
                    if(counter==1) elligibleSwaps++;     
                    swaps(i,j,p.F,p.S);
                }
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(candidates[i].F<=0 || candidates[i].S<=0 || candidates[i].F>n || candidates[i].S>m) continue;
            if(candidates[j].F<=0 || candidates[j].S<=0 || candidates[j].F>n || candidates[j].S>m) continue;
            swaps(candidates[i].F,candidates[i].S,candidates[j].F,candidates[j].S);
            if(counter==1) elligibleSwaps++; 
            swaps(candidates[i].F,candidates[i].S,candidates[j].F,candidates[j].S);
        }
    }
    if(elligibleSwaps>0){
        cout<<1<<" "<<elligibleSwaps<<"\n";
        return;
    }
    cout<<2<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}