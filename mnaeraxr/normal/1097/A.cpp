#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a; cin >> a;

    for (int i = 0; i < 5; ++i){
        string b; cin >> b;

        if (b[0] == a[0] || b[1] == a[1]){
            cout << "YES" << endl;
            exit(0);
        }
    }

    cout << "NO" << endl;

    return 0;
}