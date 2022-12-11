#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,M,Q;
    cin >> N >> M;
    string S[100],T[100];
    for(int i=0; i<N; i++) cin >> S[i];
    for(int i=0; i<M; i++) cin >> T[i];
    cin >> Q;
    while(Q--){
        int x;
        cin >> x;
        cout << S[(x-1)%N] << T[(x-1)%M] << '\n';
    }
}