    #include<bits/stdc++.h>
    #pragma GCC optimize("Ofast")
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
    #pragma GCC optimization ("O3")
    #pragma GCC optimization ("unroll-loops")
    #define pii pair<long long int,long long int>
    #define pb(a) push_back(a)
    #define F first
    #define S second
    typedef long long ll;
    using namespace std;
    // Please write the recurances once :(
    void pre(){}
    int v(char c){
        return int(c);
    }
    void solve(){
        ll n;cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<3*n<<"\n";
        for(int i=0;i<n;i+=2){
            cout<<1<<" "<<i+1<<" "<<i+2<<"\n";
            cout<<2<<" "<<i+1<<" "<<i+2<<"\n";
            cout<<1<<" "<<i+1<<" "<<i+2<<"\n";
            cout<<1<<" "<<i+1<<" "<<i+2<<"\n";
            cout<<2<<" "<<i+1<<" "<<i+2<<"\n";
            cout<<1<<" "<<i+1<<" "<<i+2<<"\n";
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