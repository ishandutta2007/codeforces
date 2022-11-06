#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ll long long
#define pnode node*
struct node
{
    int sum;
    node *l, *r;
    node(int _sum)
    {
        sum = _sum;
        l = r = NULL;
    }
    node(node *L, node *R)
    {
        l = L;
        r = R;
        sum = L->sum + R->sum;
    }
};
int n, m, y, cur, l, r, z, x, c, a[300005];
bool fl;
pnode roots[300005];

inline pnode build( int tl, int tr ) {
    if ( tl == tr )
        return new node( 0 );
    int mid = ( tl + tr ) >> 1;
    return new node( build( tl, mid ), build( mid + 1, tr ) );
}

int pos1;

inline pnode update( pnode T, int tl, int tr) {
    if ( tl == tr )
        return new node( T -> sum + 1 );
    int mid = ( tl + tr ) >> 1;
    if ( pos1 <= mid )
        return new node( update( T -> l, tl, mid), T -> r );
    return new node( T -> l, update( T -> r, mid + 1, tr) );
}

int Mid, Cnt;

inline int kth( pnode T1, pnode T2, int tl, int tr, int k ) {

    while (tl != tr) {
        Mid = (tl + tr) >> 1;
        Cnt = T1 -> l -> sum - T2 -> l -> sum;
        if (Cnt >= k) {
            T1 = T1 -> l;
            T2 = T2 -> l;
            tr = Mid;
        } else {
            T1 = T1 -> r;
            T2 = T2 -> r;
            tl = Mid + 1;
            k -= Cnt;
        }
    }
    return tl;

    // if ( tl == tr )
    //     return tl;
    // int mid = ( tl + tr ) >> 1;
    // int cnt = T1 -> l -> sum - T2 -> l -> sum;
    // if ( cnt >= k )
    //     return kth( T1 -> l, T2 -> l, tl, mid, k );
    // return kth( T1 -> r, T2 -> r, mid + 1, tr, k - cnt );
}
inline int kolvo(pnode T, int tl, int tr, int num)
{
    while (tl != tr) {
        Mid = (tl + tr) >> 1;
        if (num <= Mid) {
            T = T -> l;
            tr = Mid;
        } else {
            T = T -> r;
            tl = Mid + 1;
        }
    }
    return T -> sum;
    // if(tl == tr) return T->sum;
    // int mid = (tl + tr) >> 1;
    // if(num <= mid)
    //     return kolvo(T->l, tl, mid, num);
    // return kolvo(T->r, mid + 1, tr, num);
}

inline int ReadInt() {
    ll x = 0;
    bool negative = false;
    char cur = 10;
    while (cur == 32 || cur == 10 || cur == 13 || cur == 9)
        cur = getchar();
    if (cur == '-') {
        negative = true;
        cur = getchar();
    }
    int it = 0;
    while (cur >= '0' && cur <= '9') {
        ++it;
        x *= 10;
        x += cur - '0';
        cur = getchar();
    }
    // if (!it)
    //     BadInput();
    // if (it > 10)
    //     BadInput();
    x *= negative ? -1 : 1;
    // if (x > INT_MAX || x < INT_MIN)
    //     BadInput();
    return x;
}

template <typename TValue>
void Read(TValue &x) {
    if (typeid(x) == typeid(int)) {
        x = ReadInt();
        return;
    }
    exit(228);
}

int main()
{
    // ios_base::sync_with_stdio( false );
    // cin.tie( 0 );
    // cin >> n >> m;
    Read(n);
    Read(m);
    for(int i = 1; i <= n; i++)
    {
        // cin >> a[i];
        Read(a[i]);
    }
    roots[0] = build(1, n);
    for(int i = 1; i <= n; i++)
    {
        pos1 = a[i];
        roots[i] = update(roots[i - 1], 1, n);
    }
    for(int i = 1; i <= m; i++)
    {
        // cin >> l >> r >> x;
        Read(l);
        Read(r);
        Read(x);
        y = (r - l + 1) / x;
        if(y == 0)
        {
            printf("%d\n", kth(roots[r], roots[l - 1], 1, n, 1));
            continue;
        }
        cur = y;
        fl = false;
        while(cur <= r - l + 1)
        {
            z = kth(roots[r], roots[l - 1], 1, n, cur);
            if(kolvo(roots[r], 1, n, z) - kolvo(roots[l - 1], 1, n, z) > y)
            {
                fl = true;
                printf("%d\n", z);
                // cout << z << "\n";
                break;
            }
            cur += y;
        }
        if(!fl)
        {
            // cout << -1 << "\n";
            // puts("-1");
            printf("-1\n");
        }
    }
    return 0;
}