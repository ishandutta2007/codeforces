#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MN = 2e5+5;
const int INF = 1e9;

int main()
{
    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        int t,i,j,x;
        int s=1, e=N, res;
        vector<int> A(N+1);
        while(s<e){
            int m = (s+e)/2;
            cout << "? " << 1 << ' ' << 2 << ' ' << 1 << ' ' << m << '\n';
            cout.flush();
            cin >> res;
            if(res==m+1) s = m+1;
            else e = m;
        }
        A[1] = s;
        if(A[1]<=N/2){
            for(int j=2; j<=N; j++){
                cout << "? " << 1 << ' ' << 1 << ' ' << j << ' ' << N-1 << '\n';
                cout.flush();
                cin >> res;
                if(res!=A[1]){
                    A[j] = res;
                    continue;
                }
                cout << "? " << 2 << ' ' << j << ' ' << 1 << ' ' << 1 << '\n';
                cout.flush();
                cin >> res;
                A[j] = res;         
            }
        }
        else{
            for(int j=2; j<=N; j++){
                cout << "? " << 2 << ' ' << j << ' ' << 1 << ' ' << 1 << '\n';
                cout.flush();
                cin >> res;
                if(res!=A[1]){
                    A[j] = res;
                    continue;
                }
                cout << "? " << 1 << ' ' << 1 << ' ' << j << ' ' << N-1 << '\n';
                cout.flush();
                cin >> res;
                A[j] = res;
            }            
        }
        cout << "!";
        for(int i=1; i<=N; i++){
            cout << ' ' << A[i];
        }
        cout << '\n';
        cout.flush();
    }
    return 0;
}