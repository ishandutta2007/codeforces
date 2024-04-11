#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"

const int N = 1e6;

vector <pair <int, int>> updates[1 + 4 * N];
int q[1 + N];
int ans[1 + N];

void addUpdate (int node, int lb, int rb, int ql, int qr, pair <int, int> edge) {
    if (ql <= lb && rb <= qr) {
        updates[node].pb (edge);
        return;
    }
    int mid = (lb + rb) / 2;
    if (ql <= mid)
        addUpdate (node * 2, lb, mid, ql, qr, edge);
    if (mid < qr)
        addUpdate (node * 2 + 1, mid + 1, rb, ql, qr, edge);
}

struct Op {
    int node;
    int x;
    int y;
    int szX;
    int szY;
};
stack <Op> undoStack;
int f[1 + N];
int sz[1 + N];
int ft (int x) {
    return (f[x] == x) ? x : ft (f[x]);
}

void addEdge (int node, int x, int y) {
    x = ft (x);
    y = ft (y);
    if (x != y) {
        if (sz[x] < sz[y])
            swap (x, y);
        undoStack.push ({node, x, y, sz[x], sz[y]});
        sz[x] += sz[y];
        f[y] = x;
    }
}

void removeEdge () {
    Op op = undoStack.top ();
    undoStack.pop ();
    int x = op.x, y = op.y;
    sz[x] = op.szX;
    sz[y] = op.szY;
    f[x] = x; f[y] = y;
}


void go (int node, int lb, int rb) {
    for (pair <int, int> edge : updates[node])
        addEdge (node, edge.first, edge.second);
    if (lb == rb) {
        /// here is the query for lb day
        ans[lb] = sz[ft (f[q[lb]])];
    }
    else {
        int mid = (lb + rb) / 2;
        go (node * 2, lb, mid);
        go (node * 2 + 1, mid + 1, rb);
    }
    while (undoStack.size () && undoStack.top ().node == node)
        removeEdge ();
}
int x[1 + N], y[1 + N], z[1 + N], type[1 + N];
int endDay[1 + 2 * N];
int curDay[1 + N];

void solveTest () {
    int n, Q, k;
    cin >> n >> Q >> k;

    /// we should call addUpdate to add an update in the aint
    /// we should add in q[i] to add a query on day i
    int day = 1;
    for (int i = 1; i <= Q; i++) {
        cin >> type[i];
        if (type[i] == 1) {
            cin >> x[i] >> y[i];
        }
        if (type[i] == 2) {
            cin >> z[i];
        }
        if (type[i] == 3) {
            endDay[day] = i;
            day++;
        }
        curDay[i] = day;
    }
    for (int i = day; i <= day + k; i++)
        endDay[i] = Q;
    for (int i = 1; i <= Q; i++) {
        if (type[i] == 1) {
            addUpdate (1, 1, Q, i, endDay[curDay[i] + k - 1], {x[i], y[i]});
           // cout << x[i] << " " << y[i] << " " << i << " " << endDay[curDay[i] + k - 1] << "\n";
        }
        if (type[i] == 2) {
            q[i] = z[i];
        }
    }
    for (int i = 1; i <= Q; i++) {
        sz[i] = 1;
        f[i] = i;
    }
    go (1, 1, Q);
    for (int i = 1; i <= Q; i++)
        if (type[i] == 2)
            cout << ans[i] << "\n";
}

int main () {

    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    solveTest ();
    return 0;
}