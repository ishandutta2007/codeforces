
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
const complex<int> I(0,1);
string s;
int n;
complex<int> p[N];
vector<complex<int>> v;
map<char, complex<int>> m = {{'L', -1}, {'R', 1}, {'U', -I}, {'D', I}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    complex<int> p = 0;
    v.push_back(0);
    for(int i = 0; i < n; i++) {
        p += m[s[i]];
        for(int j = 0; j <= i; j++) {
            int x = norm(v[j] - p);
            if(x == 0 || (x == 1 && j < i)) {
                cout << "BUG" << endl;
                return 0;
            }
        }
        v.push_back(p);
    }
    cout << "OK" << endl;
}