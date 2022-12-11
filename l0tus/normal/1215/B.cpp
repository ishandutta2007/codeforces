#include <bits/stdc++.h>
using namespace std;
#define first va
#define second vb
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,A[MN],B[MN],C[MN],cnt;
ll ans1,ans2;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[i];
        if(A[i]>0){
            B[i]=B[i-1]+1;
            C[i]=C[i-1];
        }
        else{
            B[i]=C[i-1];
            C[i]=B[i-1]+1;
        }
        ans1 += B[i];
        ans2 += C[i];
    }
    cout << ans2 << ' ' << ans1;
}