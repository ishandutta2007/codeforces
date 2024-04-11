#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair <int, int> > V;

int main()
{
    int x1, x2, y1, y2;
    int hor = 0, ver = 0;
    for (int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && y1 != y2) ver++;
        if (y1 == y2 && x1 != x2) hor++;
        V.push_back(make_pair(x1, y1));
        V.push_back(make_pair(x2, y2));
    }
    sort(V.begin(), V.end());
    int len = unique(V.begin(), V.end()) - V.begin();
    if (len != 4 || hor != 2 || ver != 2) cout << "NO\n";
    else if (V[0].first == V[1].first && V[2].first == V[3].first &&
             V[0].second == V[2].second && V[1].second == V[3].second) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}