#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int L[MAXN];
int le[MAXN], ri[MAXN];

struct Node{
    int v, p, t;
}ST[MAXN << 2];


void build(int p, int b, int e)
{
    if (b == e)
        ST[p] = (Node){L[b], b, 1};
    else
    {
        int mid = (b + e) >> 1;
        int left = p << 1;
        int right = left | 1;

        build(left, b, mid);
        build(right, mid + 1, e);

        if (ST[left].v == ST[right].v)
            ST[p] = (Node){ST[left].v, ST[left].p, ST[left].t + ST[right].t};
        else if (ST[left].v < ST[right].v)
            ST[p] = ST[left];
        else
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
            Node lef = query(left, b, mid, x, y);
            Node rig = query(right, mid + 1, e, x, y);
            Node ans;

            if (lef.v == rig.v)
                ans = (Node){lef.v, lef.p, lef.t + rig.t};
            else if (lef.v < rig.v)
                ans = lef;
            else
                ans = rig;
            return ans;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack<int> S;
    for (int i = 0; i < N; ++i)
    {
        cin >> L[i];
        le[i] = ri[i] = i;
        while (!S.empty() && L[i] % L[S.top()] != 0)
        {
            ri[S.top()] = i - 1;
            S.pop();
        }
        S.push(i);
    }
    while (!S.empty())
    {
        ri[S.top()] = N - 1;
        S.pop();
    }

    for (int i = N - 1; i >= 0; --i)
    {
        while (!S.empty() && L[i] % L[S.top()] != 0)
        {
            le[S.top()] = i + 1;
            S.pop();
        }
        S.push(i);
    }
    while (!S.empty())
    {
        le[S.top()] = 0;
        S.pop();
    }

    build(1, 0, N - 1);

    int Q;
    cin >> Q;
    while (Q--)
    {
        int a,b;
        cin >> a >> b;
        a--; b--;

        Node cur = query(1, 0, N - 1, a, b);
        //cout << cur.v << " " << cur.p << " " << cur.t << endl;
        if (le[cur.p] <= a && b <= ri[cur.p])
            cout << b - a + 1 - cur.t << endl;
        else
            cout << b - a + 1 << endl;
    }


    return 0;
}