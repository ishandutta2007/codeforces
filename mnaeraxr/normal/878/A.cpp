#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> value(10);

    for (int i = 0; i < n; ++i){
        string com;
        int num;

        cin >> com >> num;

        if (com == "|"){
            for (int j = 0; j < 10; ++j){
                if (num >> j & 1)
                    value[j] = 3;
            }
        }
        else if (com == "&"){
            for (int j = 0; j < 10; ++j){
                if ((num >> j & 1) == 0)
                    value[j] = 2;
            }
        }
        else if (com == "^"){
            for (int j = 0; j < 10; ++j){
                if (num >> j & 1)
                    value[j] ^= 1;
            }
        }
    }

    int a = 0;
    int b = 0;

    for (int i = 0; i < 10; ++i){
        if (value[i] >= 2){
            a |= 1 << i;
        }

        if (value[i] == 2 || value[i] == 1){
            b |= 1 << i;
        }
    }

    cout << 2 << endl;
    cout << "| " << a << endl;
    cout << "^ " << b << endl;

    return 0;
}