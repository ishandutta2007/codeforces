#include <bits/stdc++.h>
using namespace std;
const int MN = 105;
int N,A[MN],B[MN],ans;
int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A,A+N);
    for(int i=0; i<N; i++){
        if(B[i]) continue;
        ans++;
        for(int j=i; j<N; j++){
            if(A[j]%A[i]==0) B[j] = 1;
        }
    }
    cout << ans;
}