#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int X, Y, Z;
    int x, y, z;

    cin >> X >> Y >> Z;
    cin >> x >> y >> z;

    int A, B, C, D, E, F;

    cin >> A >> B >> C >> D >> E >> F;

    int answer = 0;

    if (X < 0) answer += E;
    if (X > x) answer += F;

    if (Y < 0) answer += A;
    if (Y > y) answer += B;

    if (Z < 0) answer += C;
    if (Z > z) answer += D;

    cout << answer << endl;
    
    return 0;
}