#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5+5;
int A[MN],S[MN],pos[MN],N,K,M,P,cur;
ll cnt,ans,out=1e12;
bool ch[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[i];
        K += A[i];
        if(A[i]) pos[K]=i;
        S[i] = S[i-1]+A[i];
    }
    if(K==1){
        cout << -1;
        return 0;
    }
    for(int i=2; i<=N; i++){
        if(K%i==0){
            M = K/i;
            P = i;
            cur = 1;
            ans = 0;
            for(int t=0; t<M; t++){
                cnt = 0;
                for(int i=1+t*P; i<=P+t*P; i++) cnt += abs(pos[i]-cur);
                while(cur<N&&2*max(0,(S[cur]-t*P))-P<0){
                    cnt += 2*max(0,(S[cur]-t*P))-P;
                    cur++;
                }
                ans += cnt;
                cur++;
            }
            out = min(out,ans);
        }
    }
    cout << out;
}