#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int64 c(int64 a){
    return a * (a - 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    vector<int> t(s.length());
    vector<int> q(s.length());

    int x = 0;
    int l = 0;

    for (int i = 0; i < (int)s.length(); ++i){
        if (s[i] == 'v'){
            if (l) x++;
            l = 1;
        } else {
            l = 0;
        }

        t[i] = x;
    }

    x = l = 0;

    for (int i = (int)s.length() - 1; i >= 0; --i){
        if (s[i] == 'v'){
            if (l) x++;
            l = 1;
        } else {
            l = 0;
        }

        q[i] = x;
    }

    int64 answer = 0;

    for (int i = 0; i < s.length(); ++i){
        if (s[i] == 'o'){
            answer += 1LL * t[i] * q[i];
        }
    }

    cout << answer << endl;

    return 0;
}