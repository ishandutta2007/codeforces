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
void solve(){
    ll n,k;cin>>n>>k;
    ll arr[n+10];
    bool f2=0;
    int f1= 0;
    arr[0]=0;
    arr[1]=0;
    int i=2;
    for(;i<n+2;i++){
        cin>>arr[i];
        if(arr[i]==k) f1++;
        arr[i]=(arr[i]>=k);
    }
    
    arr[i]=0;
    arr[i+1]=0;
    int j = i;
    for(int i=0;i<j;i++){
        if(arr[i]+arr[i+1]+arr[i+2]>=2){
            f2=1;
        }
    }
    if((f1&&f2)||f1==n){
        cout<<"yes"<<"\n";
    }else{
        cout<<"no"<<"\n";
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