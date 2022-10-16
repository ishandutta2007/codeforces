#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
pii check(int m,vector<int> &arr,int n,int k){
    int till = 0;
    for(int i=0;i<m;i++){
        till+=arr[i];
    }
    for(int i=m;i<=n;i++){
        till -= arr[i-m];
        till += arr[i];
        if( n + k <= 2*till ) return {i-m+1,i}; 
    }    
    return {-1,-1};
}
void solve(){
    pii c = {-1,-1};
    int n,k,d;cin>>n>>k;
    vector<int>arr(n+1);
    vector<int>brr(n+1);
    for(int i=0;i<n;i++){
        cin>>d;
        brr[i]=d;
        arr[d]++;
    }
    pii rep = {-1,-1};
    int start = 0,end = n,mid = n-1,ans=n;
    while(start<=end){
        mid = (start + end)/2;
        pii d = check(mid,arr,n,k);
        if(d!=c){
            ans = mid;
            end = mid-1;
            rep = d;
        }else{
            start = mid + 1; 
        }
    }
    cout<<rep.F<<" "<<rep.S<<"\n";
    int count = 0;
    int val = 0;
    int last = 1;
    for(int i=1;i<=n;i++){
        if(brr[i-1]<=rep.S && brr[i-1]>=rep.F){
            count++;
            if(count>0 && val!=k-1){
                val++;
                count=0;
                cout<<last<<" "<<i<<"\n";
                last = i+1;
            }
        }else{
            count--;
        }
    }
    cout<<last<<" "<<n<<"\n";
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