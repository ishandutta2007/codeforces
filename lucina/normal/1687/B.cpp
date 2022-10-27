#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;


int n, m;

array <int, 2> v[nax];

int query(string s) {
    cout << "? " << s << endl;
    int res;
    cin >> res;
    return res;
}




int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    string b;
    for (int i = 0 ; i < m ; ++ i) b += '0';

    for (int i = 0 ; i < m ; ++ i) {
        string c = b;
        c[i] = '1';
        v[i] = {query(c), i};
    }
    sort(v, v + m);


    int lst = 0;
    for (int i = 0 ; i < m ; ++ i) {
        auto [w, pos] = v[i];
        string c = b;
        c[pos] = '1';
        int x = query(c);
        if (lst + w == x) {
            b = c;
            lst += w;
        }
    }

    cout << "! " << lst << endl;

}
/**
    Yay Div.1~ GL
    Lucina
*/