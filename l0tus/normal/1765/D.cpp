#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MAXN = 200010;
int N, M, A[MAXN];
bool solve(int m){
    if(m == N) return 1;
    int x = A[N-m];
    int s = 0, e = N-m-1;
    for(int j=0 ; s<=e ; j++){
        if(j%2==0){
            if(x + A[s] > M) return 0;
            x = A[s++];
        } else{
            if(x + A[e] > M) return 0;
            x = A[e--];
        }
    }
    return 1;
}
int main(){
    cin>>N>>M;
    ll ans = 0;
    for(int i=0 ; i<N ; i++) {
        cin>>A[i];
        ans += A[i];
    }
    sort(A, A+N);
    // m  value  
    int s = 1, e = N;
    while(s!=e){
        int m = (s+e)>>1;
        if(solve(m)){
            e = m;
        } else{
            s = m+1;
        }
    }
    cout<<ans+s<<"\n";
}