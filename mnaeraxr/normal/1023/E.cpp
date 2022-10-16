#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

bool ask(int x0, int y0, int x1, int y1){
    cout << "? " << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
    cout.flush();
    string s; cin >> s;
    return s == "YES";
}

int manhattan(int x0, int y0, int x1, int y1){
    return x1 - x0 + y1 - y0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<char> A, B;

    int x = 1, y = 1;

    while (manhattan(x + 1, y, n, n) >= n - 1){
        if (x < n && ask(x + 1, y, n, n)){
            A.push_back('D');
            x++;
        }
        else{
            A.push_back('R');
            y++;
        }
    }

    int tx = x, ty = y;
    x = n, y = n;

    while (x != tx || y != ty){
        if (y > 1 && ask(1, 1, x, y - 1)){
            B.push_back('R');
            y--;
        }
        else{
            B.push_back('D');
            x--;
        }
    }

    cout << "! ";
    for (auto u : A) cout << u;
    reverse(B.begin(), B.end());
    for (auto u : B) cout << u;
    cout << endl;

    return 0;
}