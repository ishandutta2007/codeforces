#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,M,K,A[MN],B[MN],S[MN],ans;
pii C[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    int x;
    for(int i=1; i<=N; i++){
        cin >> x;
        A[x] = i;
    }
    for(int i=1; i<=N; i++){
        cin >> x;
        B[x] = i;
    }
    for(int i=1; i<=N; i++) C[i] = pii(A[i],B[i]);
    sort(C+1,C+N+1);
    int cnt = 0;
    for(int i=1; i<=N; i++){
        //cout << C[i].vb;
        if(cnt>C[i].vb) ans++;
        cnt = max(cnt,C[i].vb);
    }
    cout << ans;
}