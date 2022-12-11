#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
bool ch[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,A[MN],B[MN];
    cin >> N;
    for(int i=1; i<=N; i++) cin >> B[i];
    int res = 0;
    for(int i=1; i<=N; i++){
        A[i] = B[i]+res;
        res = max(res,A[i]);
    }
    for(int i=1; i<=N; i++) cout << A[i] << ' ';
}