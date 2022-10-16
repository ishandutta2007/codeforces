#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    string s; cin >> s;

    int begin = -1;

    for (int i = 0; i < (int)s.length(); ++i){
        if (s[i] != 'a'){
            begin = i;
            break;
        }
    }

    if (begin == -1){
        for (int i = 0; i < (int)s.length() - 1; ++i)
            cout << "a";
        cout << "z";
        cout << endl;
    }
    else{
        while (begin < (int)s.length() && s[begin] != 'a'){
            s[begin++]--;
        }

        cout << s << endl;
    }

    return 0;
}