#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 10005;

int n;
int x[Maxn], r[Maxn];
int id[Maxn];
int m;
int f[Maxn];
int res;

bool Less(const int &a, const int &b)
{
     return x[a] < x[b];
}

void Search(int lw, int up, int tx, int ty, int ind)
{
     if (lw > up) return;
     int mid = (lw + up) / 2;
     if ((tx - x[id[mid]]) * (tx - x[id[mid]]) + ty * ty <= r[id[mid]] * r[id[mid]] && f[id[mid]] == -1) {
             res++;
             f[id[mid]] = ind;
     }
     if (tx < x[id[mid]]) Search(lw, mid - 1, tx, ty, ind);
     if (tx > x[id[mid]]) Search(mid + 1, up, tx, ty, ind);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> r[i];
        id[i] = i;
    }
    sort(id, id + n, Less);
    fill(f, f + n, -1);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int tx, ty; cin >> tx >> ty;
        Search(0, n - 1, tx, ty, i);  
    }
    cout << res << endl;
    for (int i = 0; i < n; i++) {
        cout << f[i];
        if (i + 1 < n) cout << " ";
        else cout << endl;
    }
    return 0;
}