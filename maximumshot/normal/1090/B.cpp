#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = (int)1e9;
const ll md = (ll)1e9 + 7, inf64 = (ll)1e18;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
//    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    vector< string > a;

    string buf;

    while(getline(cin, buf)) {
        a.push_back(buf);
    }

    int p = 0;

    while(a[p] != "\\begin{thebibliography}{99}") p++;

    vector< string > m1, m2;

    for(int it = 0;it < p;it++) {
        string &s = a[it];
        for(int i = 0;i < (int)s.size();i++) {
            if(s[i] != '\\') continue;
            if(s.substr(i, 5) != "\\cite") continue;
            int j = i;
            while(s[j] != '}') j++;
//            cout << s.substr(i + 6, j - i + 1 - 7) << "\n";
            m1.push_back(s.substr(i + 6, j - i + 1 - 7));
            i = j;
        }
    }

    for(int it = p + 1;it < (int)a.size();it++) {
        string &s = a[it];
        for(int i = 0;i < (int)s.size();i++) {
            if(s[i] != '\\') continue;
            if(s.substr(i, 8) != "\\bibitem") continue;
            int j = i;
            while(s[j] != '}') j++;
//            cout << s.substr(i + 9, j - i + 1 - 10) <<  " ?\n";
            m2.push_back(s.substr(i + 9, j - i + 1 - 10));
        }
    }

    if(m1 == m2) {
        cout << "Correct\n";
        return 0;
    }

    cout << "Incorrect\n";

    cout << a[p] << "\n";

    for(string need : m1) {
        for(int it = p + 1;it < (int)a.size();it++) {
            string &s = a[it];
            int ok = 0;
            for(int i = 0;i < (int)s.size();i++) {
                if(s[i] != '\\') continue;
                if(s.substr(i, 8) != "\\bibitem") continue;
                int j = i;
                while(s[j] != '}') j++;
//            cout << s.substr(i + 9, j - i + 1 - 10) <<  " ?\n";
//                m2.push_back(s.substr(i + 9, j - i + 1 - 10));
                if(s.substr(i + 9, j - i + 1 - 10) == need) {
                    ok = 1;
                    break;
                }
            }
            if(ok) {
                cout << a[it] << "\n";
                break;
            }
        }
    }

    cout << a.back() << "\n";

    return 0;
}