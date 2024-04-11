
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int query(string s) {
    int n;
    cout << s << endl;
    cin >> n;
    if(n == 0) exit(0);
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a = query("a");
    int b = query(string(a, 'b'));
    int n = a + 1;
    b = n - b;
    string str(n, 'a'), t(n, 'a');
    for(int i = 0; i < n - 1; i++) {
        str[i] = 'b';
        if(query(str) == b - 1) {
            b--;
        }else {
            str[i] = 'a';
        }
    }
    if(b > 0) str[n - 1] = 'b';
    query(str);
    assert(false);
}