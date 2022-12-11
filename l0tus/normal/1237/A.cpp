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
    for(int i=1; i<=N; i++){
        cin >> A[i];
        sum += A[i];
    }
    for(int i=1; i<=N; i++){
        if(A[i]%2==0){
            cout << A[i]/2 << '\n';
            continue;
        }
        if(sum>0){
            cout << (A[i]-1)/2 << '\n';
            sum--;
        }
        else{
            cout << (A[i]+1)/2 << '\n';
            sum++;
        }
    }
    //cout << ans;
}