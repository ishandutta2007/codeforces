#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
typedef long long lld;

#define MAXN 100005

int N;
int A[MAXN];

int main()
{
    cin >> N;
    for (int i=1;i<=N;i++) cin >> A[i];
    sort(A+1, A+N+1);
    vector <int> arr;
    for (int i=N-1;i>0;i--){
        if (A[i+1]-A[i] < 2){
            arr.pb(A[i]); i--;
        }
    }
    lld ans = 0;
    for (int i=0;i+1<sz(arr);i+=2){
        ans += (lld)arr[i]*arr[i+1];
    }
    printf("%lld\n", ans);
}