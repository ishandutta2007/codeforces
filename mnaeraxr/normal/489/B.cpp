#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> read()
{
    vector<int> V;
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        V.push_back(v);
    }
    sort(V.begin(), V.end());
    return V;
}

int main()
{
    vector<int> B = read(), G = read();
    int p1 = 0, p2 = 0;
    int ans = 0;
    while (p1 < B.size() && p2 < G.size())
    {
        if (abs(B[p1] - G[p2]) <= 1){
            ans++;
            p1++;
            p2++;
        }
        else if (B[p1] < G[p2])
            p1++;
        else
            p2++;
    }
    cout << ans << endl;
    return 0;
}