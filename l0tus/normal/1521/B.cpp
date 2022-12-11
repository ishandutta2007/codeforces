#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MN = 2e5+5;

//int A[MN],S[MN];

int main()
{
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> A(N);
        int x = 0;
        for(int i=0; i<N; i++){
            cin >> A[i];
            if(A[x]>A[i]) x = i;
        }
        cout << N-1 << '\n';
        for(int i=0; i<N; i++){
            if(i==x) continue;
            int t = A[x];
            if(i%2!=x%2) t++;
            cout << x+1 << ' ' << i+1 << ' ' << A[x] << ' ' << t << '\n';
        }
    }
    return 0;
}