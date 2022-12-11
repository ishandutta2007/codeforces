#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 1e5+5;
int A[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N,K;
        cin >> N >> K;
        bool pos = 0;
        for(int i=1; i<=N; i++){
            cin >> A[i];
            if(A[i]==K) pos = 1;
        }
        if(!pos){
            cout << "no\n";
            continue;
        }
        if(N==1){
            cout << "yes\n";
            continue;
        }
        pos = 0;
        for(int i=1; i<N; i++){
            if(A[i]>=K&&A[i+1]>=K) pos = 1;
        }
        int cnt = 0;
        for(int i=1; i<=N; i++){
            if(A[i]>=K) cnt++;
            if(i>3&&A[i-3]>=K) cnt--;
            if(cnt>=2) pos = 1;
        }
        if(pos) cout << "yes\n";
        else cout << "no\n";
    }

}