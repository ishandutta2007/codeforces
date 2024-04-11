#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
const int INF = 1e9;
int C[MN],posL[MN],posR[MN],x,ans;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        posL[0] = posR[0] = INF;
        for(int i=1; i<=2*N; i++){
            posL[i] = posR[i] = INF;
            cin >> C[i];
        }
        x = 0;
        posL[0+N] = N;
        for(int i=1; i<=N; i++){
            if(C[i]==1) x++;
            else x--;
            posL[x+N] = min(posL[x+N],N-i);
        }
        x = 0;
        posR[0+N] = N;
        for(int i=N; i>=1; i--){
            if(C[i+N]==1) x++;
            else x--;
            posR[x+N] = min(posR[x+N],i-1);
        }

        ans = 2*INF;
        for(int i=-N; i<=N; i++){
            ans = min(ans,posL[i+N]+posR[-i+N]);
        }
        cout << ans << '\n';
    }
}