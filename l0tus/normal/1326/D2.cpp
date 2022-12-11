#include <bits/stdc++.h>
using namespace std;
const int MN = 2e6+5;
int A[MN],B[MN];
int T, N, cnt, ans, l, r;

void mana(string S, int N)
{
    int r = 0, p = 0;
    for(int i = 0; i < N; i++)
    {
        if(i <= r) A[i] = min(A[2 * p - i], r - i);
        else A[i] = 0;
        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1])
            A[i]++;

        if(r < i + A[i])
        {
            r = i + A[i];
            p = i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> T;
    while(T--) {
        string S;
        cin >> S;
        N = S.size();
        cnt = -1, ans = 1, l = 0, r = N;
        for(int i=0; i<N/2; i++) {
            if(S[i]!=S[N-1-i]) {
                break;
            }
            cnt = i;
        }
        if(ans<2*cnt+2){
            ans = 2*cnt+2;
            l = cnt, r = N-1-cnt;
        }
        mana(S,N);
        for(int i=0; i<N; i++){
            int L = i-A[i], R = i+A[i];
            int K = min(L-1,N-2-R);
            if(cnt>=K){
                if(ans<2*K+2+R-L+1){
                    ans = 2*K+2+R-L+1;
                    if(L-1<N-2-R){
                        l = R, r = N-1-K;
                    }
                    else{
                        l = K, r = L;
                    }
                }
            }
        }
        string G;
        G.resize(2*N+1);
        for(int i=0; i<2*N+1; i++){
            if(i%2==0) G[i] = '#';
            else G[i] = S[i/2];
        }
        mana(G,2*N+1);
        for(int i=2; i<2*N; i+=2){
            if(A[i]==0) continue;
            int L = (i-A[i]+1)/2, R = (i+A[i]-1)/2;
            int K = min(L-1,N-2-R);
            if(cnt>=K){
                if(ans<2*K+2+R-L+1){
                    ans = 2*K+2+R-L+1;
                    if(L-1<N-2-R){
                        l = R, r = N-1-K;
                    }
                    else{
                        l = K, r = L;
                    }
                }
            }
        }
        for(int i=0; i<=l; i++) cout << S[i];
        for(int i=r; i<N; i++) cout << S[i];
        cout << '\n';
    }
}