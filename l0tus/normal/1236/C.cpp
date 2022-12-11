#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,M,K,A[MN],B[MN],S[MN],ans,sum;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    if(N%2==0){
        for(int i=0; i<N; i++){
            for(int j=1; j<=N/2; j++){
                cout << j+i*N/2 << ' ';
            }
            for(int j=1; j<=N/2; j++){
                cout << j+(N-1-i)*N/2+N*N/2 << ' ';
            }
            cout << '\n';
        }
        return 0;
    }
    for(int i=0; i<N; i++){
        for(int j=1; j<=(N-1)/2; j++){
            cout << j+i*(N-1)/2 << ' ';
        }
        for(int j=1; j<=(N-1)/2; j++){
            cout << j+(N-1-i)*(N-1)/2+N*(N-1)/2 << ' ';
        }
        cout << i+(N-1)*N+1 << ' ';
        cout << '\n';
    }
}


//(N-1)/2     N-1   (N+1)/2      1   1