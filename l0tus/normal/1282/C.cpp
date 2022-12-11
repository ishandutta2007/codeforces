#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MN = 2e5+5;
ll N,T,A,B,NA,NB,S,M,X,cnt,ans;
pii P[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int m;
    cin >> m;
    while(m--){
        cin >> N >> T >> A >> B;
        NA = NB = 0;
        for(int i=1; i<=N; i++){
            cin >> P[i].vb;
            if(P[i].vb) NB++;
            else NA++;
        }
        for(int i=1; i<=N; i++) cin >> P[i].va;
        sort(P+1,P+N+1);
        ans = 0;
        S = 0;
        if(P[1].va){
            cnt = 0;
            M = P[1].va-1;
            X = min(NA,M/A);
            M -= A*X;
            cnt += X;
            X = min(NB,M/B);
            M -= B*X;
            cnt += X;
            ans = max(ans,cnt);
        }
        for(int i=1; i<=N; i++){
            if(P[i].vb){
                S+=B;
                NB--;
            }
            else{
                S+=A;
                NA--;
            }
            if(i<N&&P[i].va==P[i+1].va) continue;
            if(i<N) M = P[i+1].va-1-S;
            else M = T-S;
            if(M<0) continue;
            cnt = i;
            X = min(NA,M/A);
            M -= A*X;
            cnt += X;
            X = min(NB,M/B);
            M -= B*X;
            cnt += X;
            ans = max(ans,cnt);
        }
        cout << ans << '\n';
    }
}