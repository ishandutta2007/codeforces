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
ll arr[1000001];
ll n;
ll tower[1000001];
void pre(){}
int check(long long int a){
    ll tow[n];
    ll brr[n];
    for(int i=0;i<n;i++){
        tow[i]=tower[i];
        brr[i]=arr[i];
    }
    tow[n-1]-=a;
    brr[0]-=a;
    for(int i=0;i<n-1;i++){
        if(brr[i]>tow[i]){
            return -1;
        }
        tow[i]-=brr[i];
        brr[i+1]-=min(brr[i+1],tow[i]);
    }
    if(tow[n-1]<brr[n-1]){
        return 1;
    }
    return 0;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>tower[i];
    ll start=0,end=min(arr[0],tower[n-1]),mid;
    while(start<=end){
        mid = (start+end+1)/2;
        int d = check(mid);
        if(d==0){
            cout<<"YES"<<"\n";
            return;
        }else if(d==-1){
            start=mid+1;
        }else{
            end = mid-1;
        }
    }
    cout<<"NO"<<"\n";
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