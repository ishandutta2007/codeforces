#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

struct cell {
    int x, y;
};

const int inf = 1000000000;

int main()
{
    vector<cell> p(3);
    cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y;
    if (p[0].x == p[1].x && p[0].x == p[2].x) {
        cout << "1\n";
        cout << p[0].x << ' ' <<  min({p[0].y, p[1].y, p[2].y}) << ' ' << p[0].x << ' ' <<  max({p[0].y, p[1].y, p[2].y});
        return 0;
    }

    if (p[0].y == p[1].y && p[0].y == p[2].y) {
        cout << "1\n";
        cout <<  min({p[0].x, p[1].x, p[2].x}) << ' ' << p[0].y << ' ' << max({p[0].x, p[1].x, p[2].x}) << ' ' << p[0].y;
        return 0;
    }

    int min_y = min({p[0].y, p[1].y, p[2].y});
    int max_y = max({p[0].y, p[1].y, p[2].y});

    vector<int> xs = {p[0].x, p[1].x, p[2].x};
    sort(xs.begin(), xs.end());

    for (int i = 0; i < 3; i++)
        if (p[i].x == xs[1]) {
            vector<vector<int>> q;
            q.pb({p[i].x, min_y, p[i].x, max_y});

            for (int j = 0; j < 3; j++)
                if (i != j)
                    if (p[j].x != p[i].x)
                        q.pb({p[j].x, p[j].y, p[i].x, p[j].y});
            cout << q.size() << "\n";
            for (auto p : q)
                cout << p[0] << ' ' << p[1] << ' ' << p[2] << ' ' << p[3] << endl;
            return 0;
        }

    /*
    ///case for 2
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++) {
            int k = (3 - i - j);
            if (i == k || i == j || j == k)
                continue;
            if (p[i].x == p[j].x) {
                cout << "2\n";
                cout << p[i].x << ' ' << -inf << ' ' << p[i].x << ' ' << inf << "\n";
                cout << -inf << ' ' << p[k].y << ' ' << inf << ' ' << p[k].y << "\n";
                return 0;
            }

            if (p[i].y == p[j].y) {
                cout << "2\n";
                cout << -inf << ' ' << p[i].y << ' ' << inf << ' ' << p[i].y << "\n";
                cout << p[k].x << ' ' << -inf << ' ' << p[k].x << ' ' << inf << "\n";
                return 0;
            }
        }

    ///case for 3
    cout << "3\n";
    cout << -inf << ' ' << p[0].y << ' ' << inf << ' ' << p[0].y << "\n";
    cout << -inf << ' ' << p[1].y << ' ' << inf << ' ' << p[1].y << "\n";
    cout << p[2].x << ' ' << -inf << ' ' << p[2].x << ' ' << inf << "\n";*/
    return 0;
}