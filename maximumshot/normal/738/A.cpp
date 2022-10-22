#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;
    cin >> n;

    string s;

    cin >> s;

    for(int i = 0;i < n;i++) {
        if(s[i] != 'o') {
            cout << s[i];
            continue;
        }
        int j = i;
        while(j < n && s[j] == ((j - i + 1) % 2 ? 'o' : 'g')) j++;
        j--;
        int I = j;
        int ok = 0;
        if(s[j] == 'g') ok = 1, j--;
        if(i < j) {
            cout << "***";
        }else {
            cout << s[i];
        }
        if(ok) cout << s[j + 1];
        i = I;
    }

    return 0;
}