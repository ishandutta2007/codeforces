#include <bits/stdc++.h>
#define first va
#define second vb
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e3+5;
int N;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if((i+j)%2) cout << 'W';
            else cout << 'B';
        }
        cout << '\n';
    }
}