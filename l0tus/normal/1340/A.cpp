#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int N,X[MN],A[MN],T,x;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        fill(A,A+N+2,0);
        for(int i=1; i<=N; i++){
            cin >> x;
            X[x] = i;
            A[i] = x;
        }
        int pre = -1;
        bool pos = 1;
        for(int i=1; i<=N; i++){
            if(A[pre+1]<i) pre = X[i];
            else{
                if(X[i]!=pre+1){
                    pos = 0;
                    break;
                }
                pre++;
            }
        }
        if(pos) cout << "Yes\n";
        else cout << "No\n";
    }
}