#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    if (n == 0){
        cout << "YES\n1\n1\n3\n3\n";
    }
    else if (n == 1){
        int a1; cin >> a1;
        cout << "YES" << endl;
        cout << 2 * a1 << endl << 2 * a1 << endl << 3 * a1 << endl;
    }
    else if (n == 2){
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);

        if (y == 3 * x) {
            cout << "YES" << endl;
            cout << 2 * x << endl << 2 * x << endl;
        }
        else if (y < 3 * x){
            cout << "YES" << endl;
            cout << 4 * x - y << endl << 3 * x << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else if (n == 3){
        int x, y, z; cin >> x >> y >> z;
        vector<int> V; V.push_back(x), V.push_back(y), V.push_back(z);
        sort(V.begin(), V.end());
        x = V[0], y = V[1], z = V[2];

        if (3 * x == z){
            cout << "YES" << endl;
            cout << 4 * x - y << endl;
        }
        else if (4 * x == y + z){
            cout << "YES" << endl;
            cout << 3 * x << endl;
        }
        else if (z % 3 == 0 && 4 * z / 3 == x + y){
            cout << "YES" << endl;
            cout << z / 3 << endl;
        }
        else
            cout << "NO" << endl;
    }
    else{
        vector<int> V;
        for (int i = 0; i < 4; ++i)
        {
            int v; cin >> v;
            V.push_back(v);
        }
        sort(V.begin(), V.end());
        if (4 * (V[3] - V[0]) == V[0] + V[1] + V[2] + V[3] && 2 * (V[3] - V[0]) == V[1] + V[2])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}