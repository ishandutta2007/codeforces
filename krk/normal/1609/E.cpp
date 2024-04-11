#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxm = 524288;

struct node {
    int a, b, c;
    int ab, bc;
    int abc;
    node(): a(0), b(0), c(0), ab(0), bc(0), abc(0) {}
};

int n, q;
char str[Maxn];
node st[Maxm];

node Union(node A, node B)
{
    node C;
    int tk = min(A.a, B.bc);
    C.abc += tk; A.a -= tk; B.bc -= tk;
    tk = min(A.ab, B.c);
    C.abc += tk; A.ab -= tk; B.c -= tk;
    C.abc += A.abc + B.abc;
    tk = min(A.ab, B.bc);
    C.abc += tk; A.ab -= tk; B.bc -= tk; C.b += tk;
    tk = min(A.a, B.b);
    C.ab += tk; A.a -= tk; B.b -= tk;
    C.ab += A.ab + B.ab;
    tk = min(A.b, B.c);
    C.bc += tk; A.b -= tk; B.c -= tk;
    C.bc += A.bc + B.bc;
    C.a += A.a + B.a;
    C.b += A.b + B.b;
    C.c += A.c + B.c;
    return C;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].a = st[v].b = st[v].c = 0;
        if (str[l] == 'a') st[v].a = 1;
        else if (str[l] == 'b') st[v].b = 1;
        else if (str[l] == 'c') st[v].c = 1;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) {
        st[v].a = st[v].b = st[v].c = 0;
        if (str[l] == 'a') st[v].a = 1;
        else if (str[l] == 'b') st[v].b = 1;
        else if (str[l] == 'c') st[v].c = 1;
    } else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    Create(1, 1, n);
    while (q--) {
        int ind; char ch; scanf("%d %c", &ind, &ch);
        str[ind] = ch;
        Update(1, 1, n, ind);
        printf("%d\n", st[1].abc);
    }
    return 0;
}