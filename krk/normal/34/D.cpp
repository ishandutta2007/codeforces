#include <iostream>
#include <vector>
using namespace std;

const int Maxn = 50001;

int n, r1, r2, p[Maxn];
vector <int> neigh[Maxn];

void Search(int v, int par)
{
     p[v] = par;
     for (int i = 0; i < neigh[v].size(); i++) if (neigh[v][i] != par)
        Search(neigh[v][i], v);
}

int main()
{
    cin >> n >> r1 >> r2;
    int a;
    for (int i = 1; i <= n; i++) if (i != r1) {
        cin >> a;
        neigh[a].push_back(i); neigh[i].push_back(a);
    }
    Search(r2, -1);
    bool pr = false;
    for (int i = 1; i <= n; i++) if (i != r2) {
        if (pr) cout << " "; pr = true;
        cout << p[i];
    }
    cout << endl;
    return 0;
}