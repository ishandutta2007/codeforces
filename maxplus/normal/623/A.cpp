#define push_back pb
#include <iostream>
#include <cstdlib>
#include <vector>
#define add(a, b) nei[a - 1].pb(b - 1), cn[a - 1][b - 1] = cn[b - 1][a - 1] = 1

using namespace std;

const int N = 501;
vector<int> nei[N];
int cn[N][N];
int n, m, a, b;
char let[N];

void wrong()
{
    cout << "No";
    exit(0);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a >> b, add(a, b), add(b, a);
    for (int i = 0; i < n; ++i)
        if (nei[i].size() == n - 1)
            let[i] = 'b';
    for (int i = 0; i < n; ++i) if (!let[i])
    {
        let[i] = 'a';
        for (auto j: nei[i])
            if (!let[j])
                let[j] = 'a';
        break;
    }
    for (int i = 0; i < n; ++i) if (!let[i])
    {
        let[i] = 'c';
        for (auto j: nei[i])
            if (!let[j])
                let[j] = 'c';
        break;
    }
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j)
        if (!let[i])
            wrong();
        else if ((let[i] >= let[j] - 1 && let[i] <= let[j] + 1) ^ cn[i][j])
            wrong();
    cout << "Yes\n";
    for (int i = 0; i < n; ++i)
        cout << let[i];
    return 0;
}