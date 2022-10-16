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

    int n; cin >> n;
    string s; cin >> s;

    bool vowel = false;
    string V = "aeiouy";

    for (auto c : s){
        if (V.find(c) != V.npos){
            if (!vowel){
                cout << c;
                vowel = true;
            }
        }
        else{
            vowel = false;
            cout << c;
        }
    }

    cout << endl;

    return 0;
}