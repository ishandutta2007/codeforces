#include <bits/stdc++.h>
using namespace std;
#define first va
#define second vb
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 3e5+5;
ll Q,N,H[MN],A[MN],B[MN],C[MN],W[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> Q;
    for(int j=0; j<Q; j++){
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> H[i] >> W[i];
        }
        A[0] = 0, B[0] = W[0], C[0] = 2*W[0];
        for(int i=0; i<N-1; i++){
            ll tmp = min(A[i],min(B[i],C[i]));
            if(H[i]==H[i+1]-1){
                A[i+1] = min(A[i],C[i]);
                B[i+1] = min(A[i],B[i])+W[i+1];
                C[i+1] = tmp+2*W[i+1];
            }
            else if(H[i]==H[i+1]){
                A[i+1] = min(B[i],C[i]);
                B[i+1] = min(A[i],C[i])+W[i+1];
                C[i+1] = min(A[i],B[i])+2*W[i+1];
            }
            else if(H[i]==H[i+1]+1){
                A[i+1] = tmp;
                B[i+1] = min(B[i],C[i])+W[i+1];
                C[i+1] = min(A[i],C[i])+2*W[i+1];
            }
            else{
                A[i+1] = tmp;
                B[i+1] = tmp+W[i+1];
                C[i+1] = tmp+2*W[i+1];
            }
        }
        cout << min(A[N-1],min(B[N-1],C[N-1])) << '\n';
    }
}