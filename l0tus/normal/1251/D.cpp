#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 2e5+5;
ll L[MN],R[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int N;
        ll S,cnt=0;
        cin >> N >> S;
        for(int i=1; i<=N; i++){
            cin >> L[i] >> R[i];
            cnt += L[i];
        }
        ll s=1,e=S,m,res;
        while(s<e){
            priority_queue<ll> PQ;
            res = cnt;
            m = (s+e+1)/2;
            for(int i=1; i<=N; i++) if(R[i]>=m) PQ.push(L[i]);
            if(PQ.size()<(N+1)/2) e = m-1;
            else{
                for(int i=1; i<=(N+1)/2; i++){
                    res += max(0ll,m-PQ.top());
                    PQ.pop();
                }
                if(res<=S) s = m;
                else e = m-1;
            }
        }
        cout << s << '\n';
    }
}