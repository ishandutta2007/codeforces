#include <iostream>
using namespace std;

const int Maxn = 1000;

bool visit[Maxn], wasfirst[Maxn];

int main()
{
    int n, nw;
    cin >> n;
    visit[0] = true; nw = 0;
    do {
        wasfirst[nw] = true;
        for (int i = 1; i < n; i++) {
            nw = (nw + i) % n;
            visit[nw] = true;
        }
    } while (!wasfirst[nw]);
    int i;
    for (i = 0; i < n; i++)
       if (!visit[i]) break;
    if (i == n) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}