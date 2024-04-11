#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
bool ch[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        if(N%2){
            cout << 7;
            for(int i=0; i<N/2-1; i++) cout << 1;
            cout << '\n';
        }
        else{
            for(int i=0; i<N/2; i++) cout << 1;
            cout << '\n';
        }
    }
}