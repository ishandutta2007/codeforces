#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<pii> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

vector<pii> V;
bool M[650][650];

int end(string &s){
    cout << s << endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int len = (int)s.length();
    int ld = s[len - 1] - '0';

    for (int i = 0; i < len - 1; ++i){
        int val = s[i] - '0';
        if (val % 2 == 0 && val < ld){
            swap(s[i], s[len - 1]);
            return end(s);
        }
    }
    for (int i = len - 2; i >= 0; --i){
        int val = s[i] - '0';
        if (val % 2 == 0){
            swap(s[i], s[len - 1]);
            return end(s);
        }
    }
    s = "-1";
    return end(s);

    return 0;
}