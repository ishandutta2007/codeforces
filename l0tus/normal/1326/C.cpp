#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
const int MOD = 998244353;
vector<int> V;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,K;
    int A[MN];
    ll val=0,ans=1;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(A[i]>N-K){
            V.push_back(i);
            val += A[i];
        }
    }
    for(int i=1; i<V.size(); i++){
        ans = ans*(V[i]-V[i-1])%MOD;
    }
    cout << val << ' ' << ans;

}