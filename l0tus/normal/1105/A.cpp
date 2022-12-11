#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5;
const int INF = 1e9;

long long N,M,L,ans,cnt,A[MN],B[MN];
string S;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A,A+N);
    int sum = 0, ans = INF, cnt = 0;
    for(int i=A[0]; i<=A[N-1]; i++){
        cnt = 0;
        for(int j=0; j<N; j++){
            if(i<A[j]) cnt += A[j]-1-i;
            if(i>A[j]) cnt += i-1-A[j];
        }
        if(cnt<ans){
            ans = cnt;
            sum = i;
        }
    }
    cout << sum << ' ' << ans;

}