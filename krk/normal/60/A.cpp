#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
    string s, dir;
    int l, r, tmp;
    cin >> n >> m;
    l = 1; r = n;
    for (int i = 0; i < m; i++) {
        cin >> s >> s >> dir >> s >> tmp;
        if (dir == "left") r = min(r, tmp - 1);
        else l = max(l, tmp + 1);
        if (l > r) break;
    }
    if (l > r) cout << "-1\n";
    else cout << r - l + 1 << endl;
    return 0;
}