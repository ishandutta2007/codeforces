#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int N;
int A[101], w[101][101];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++)
        scanf("%1d", w[i]+j);
    for (int i=1;i<=N;i++) scanf("%d", A+i);
    vector <int> arr;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++) if (!A[j]){
            arr.pb(j);
            for (int k=1;k<=N;k++) if (w[j][k]) A[k]--;
        }
    }
    printf("%d\n", sz(arr));
    for (int t: arr) printf("%d ", t); puts("");
}