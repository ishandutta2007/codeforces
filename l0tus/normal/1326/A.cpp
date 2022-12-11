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
        if(N==1){
            cout << "-1\n";
            continue;
        }
        if(N%3!=1){
            for(int i=1; i<N; i++) cout << "2";
            cout << "3\n";
        }
        else{
            for(int i=1; i<N-1; i++) cout << "2";
            cout << "33\n";
        }
    }
}