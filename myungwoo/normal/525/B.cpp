#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;

#define MAXN 200005

int N, M;
char A[MAXN];

int main()
{
    cin >> (A+1); N = strlen(A+1);
    cin >> M;
    vector <int> arr(M, 0);
    for (int i=0;i<M;i++) cin >> arr[i], arr.pb(N-arr[i]+2);
    sort(all(arr));
    bool rev = 0;
    for (int i=1,j=0;i<=N;i++){
        while (j < sz(arr) && i == arr[j]){
            rev ^= 1;
            j++;
        }
        printf("%c", rev ? A[N-i+1] : A[i]);
    }
    puts("");
}