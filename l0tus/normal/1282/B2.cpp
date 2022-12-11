#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int N,P,K,A[MN],C[MN],D[MN],ans;
bool ch;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> N >> P >> K;
        for(int i=1; i<=N; i++) cin >> A[i];
        sort(A+1,A+N+1);
        C[0] = D[0] = 0;
        for(int i=1; i<K; i++){
            C[i] = C[i-1] + A[i];
            if(C[i-1]+A[i]<=P){
                D[i] = i;
            }
            else{
                D[i] = 0;
            }
        }
        for(int i=K; i<=N; i++){
            if(C[i%K]+A[i]<=P){
                C[i%K]+=A[i];
                D[i%K]+=K;
            }
        }
        ans = 0;
        for(int i=0; i<K; i++) ans = max(ans,D[i]);
        cout << ans << '\n';
    }
}