#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 1e5+5;
int A[MN],N,M,K,val,cnt;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,M;
    cin >> N >> M;
    for(int i=3; i<MN; i++){
        A[i] = A[i-1]+(i-1)/2;
        if(A[i]>1e9){
            K = i;
            break;
        }
    }
    int X = lower_bound(A+1,A+K+1,M)-A;
    if(X>N){
        cout << -1;
        return 0;
    }
    cnt = M-A[X-1];
    if(M){
        for(int i=1; i<X; i++) cout << i << ' ';
        cout << 2*X-1-2*cnt << ' ';
    }
    else X=0;
    for(int i=X+1; i<=N; i++){
        cout << 100000000+(2*X+1)*i << ' ';
    }
}