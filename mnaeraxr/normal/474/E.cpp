#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 1LL << 60;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int64 R[MAXN], O[MAXN];
int FROM[MAXN];

struct Node{
    int v, p;
    Node()
    {
        v = 0, p = -1;
    }
    Node(int V, int P)
    {
        v = V, p = P;
    }
} ST[MAXN << 2];

int len;

int bigt(int64 v)
{
    return lower_bound(O, O + len, v) - O;
}

int lowt(int64 v)
{
    return upper_bound(O, O + len, v) - O - 1;
}

void update(int p, int b, int e, int x, int v, int f)
{
    if (b == e)
        ST[p] = Node(v, f);
    else
    {
        int mid = (b + e) >> 1;
        int left = p << 1;
        int right = left | 1;

        if (x <= mid)
            update(left, b, mid, x, v, f);
        else
            update(right, mid + 1, e, x, v, f);

        if (ST[left].v > ST[p].v)
            ST[p] = ST[left];
        if (ST[right].v > ST[p].v)
            ST[p] = ST[right];
    }
}

Node query(int p, int b, int e, int x, int y)
{
    if (x <= b && e <= y)
        return ST[p];
    else
    {
        int mid = (b + e) >> 1;
        int left = p << 1;
        int right = left | 1;

        if (y <= mid)
            return query(left, b, mid, x, y);
        else if (mid + 1 <= x)
            return query(right, mid + 1, e, x, y);
        else
        {
            Node n1 = query(left, b, mid, x, y);
            Node n2 = query(right, mid + 1, e, x, y);
            return (n1.v > n2.v) ? n1 : n2;
        }
    }
}

vi ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 N, D;
    cin >> N >> D;
    for (int i = 0; i < N; ++i)
    {
        cin >> R[i];
        O[i] = R[i];
    }

    sort(O, O + N);
    int64 *last = unique(O, O + N);
    len = last - O;
    O[len++] = oo;

    Node best = Node();

    for (int i = 0; i < N; ++i)
    {
        int cu = lowt(R[i]);
        int lo = lowt(R[i] - D);
        int hi = bigt(R[i] + D);

        Node left = Node(), right = Node();
        Node cbest = Node();

        if (lo >= 0)
            left = query(1, 0, len - 1, 0, lo);

        if (hi < len - 1)
            right = query(1, 0, len - 1, hi, len - 1);

        if (left.v > cbest.v)
            cbest = left;
        if (right.v > cbest.v)
            cbest = right;

        cbest.v++;
        FROM[i] = cbest.p;

        update(1, 0, len - 1, cu, cbest.v, i);

        if (cbest.v > best.v)
        {
            best = cbest;
            best.p = i;
        }
    }
    FROM[0] = -1;
    int p = best.p;
    while (p != -1)
    {
        ans.push_back(p);
        p = FROM[p];
    }

    cout << best.v << endl;

    for (int i = (int)ans.size() - 1; i >= 0; --i)
        cout << ans[i] + 1 << " ";
    cout << endl;

    return 0;
}