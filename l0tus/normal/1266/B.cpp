#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N;
long long x;
int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;
        if(x>=15&&x%14>=1&&x%14<=6) cout << "YES\n";
        else cout << "NO\n";
    }
}