#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5+5;
bool ch[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N,M,K,A[4000],B[4000],L,R,ans=0;
        cin >> N >> M >> K;
        for(int i=0; i<N; i++) cin >> A[i];
        if(M-1<K) K = M-1;
        M = M-1-K;
        L = 0, R = K;
        for(int x=0; x<=M+K; x++) B[x] = max(A[x],A[x+N-1-K-M]);
        priority_queue<pii, vector<pii>, greater<pii>> PQ;
        for(int i=0; i<M; i++) PQ.emplace(B[i],i);
        for(int i=M; i<=M+K; i++){
            PQ.emplace(B[i],i);
            while(PQ.top().vb<i-M) PQ.pop();
            ans = max(ans,PQ.top().va);
        }
        cout << ans << '\n';
    }
}