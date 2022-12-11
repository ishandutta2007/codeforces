#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 105;
const int MOD = 1e9+7;
const int INF = 1e9;

int A[MN];
int main()
{
    #ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N,sum=0;
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> A[i];
            sum += A[i];
        }
        sort(A,A+N);
        if(N==1){
            cout << "T\n";
        }
        else{
            if(sum%2||A[N-1]>sum-A[N-1]) cout << "T\n";
            else cout << "HL\n";
        }
    }

}