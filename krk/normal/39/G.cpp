#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 15;
const int mod = Maxn;

int val;
string code;
int f[Maxn];
int pnt;

char Read() { return code[pnt++]; }

void Skip(int v) { pnt += v; }

int Evaluate(int n);

int Expr(int n, char &ch);

int Number(int n, char &ch)
{
    ch = Read();
    if (ch == 'n') {
        ch = Read();
        return n;
    }
    if (isdigit(ch)) {
        int res = ch - '0';
        while (true) {
            ch = Read();
            if (!isdigit(ch)) break;
            res = 10 * res + int(ch - '0');
        }
        return res;
    }
    Skip(1);
    int tmp = Expr(n, ch);
    ch = Read();
    return Evaluate(tmp);
}

int Term(int n, char &op)
{
    int cur = Number(n, op);
    while (op == '*' || op == '/')
        if (op == '*') {
            int nw = Number(n, op);
            cur = cur * nw % Maxn;
        } else {
            int nw = Number(n, op);
            cur /= nw;
        }
    return cur;
}

int Expr(int n, char &op)
{
    int cur = Term(n, op);
    while (op == '+' || op == '-')
        if (op == '+') {
            int nw = Term(n, op);
            cur = (cur + nw) % mod;
        } else {
            int nw = Term(n, op);
            cur = (cur - nw + mod) % mod;
        }
    return cur;
}

bool logicalExpr(int n, char &ch)
{
    char op;
    int val = Expr(n, op);
    if (op == '=') Skip(1);
    int val2 = Expr(n, ch);
    if (op == '>') return val > val2;
    if (op == '<') return val < val2;
    return val == val2;
}

int evalOperator(int n) 
{
    char ch = Read();
    char dum;
    if (ch == 'r') {
        Skip(5);
        return Expr(n, dum);
    } else {
        while (Read() != '(') ;
        if (logicalExpr(n, dum)) {
            Skip(6);
            return Expr(n, dum);
        }
        while (Read() != ';') ;
    }
    return -1;
}

int Evaluate(int n)
{
    if (f[n] != -1) return f[n];
    pnt = 0;
    while (Read() != '{') ;
    while (f[n] == -1)
        f[n] = evalOperator(n);
    return f[n];
}

int main()
{
    cin >> val;
    char ch;
    while (cin >> ch)
        code += ch;
    fill(f, f + Maxn, -1);
    int ans = -1;
    for (int i = 0; i < Maxn; i++)
        if (Evaluate(i) == val)
            ans = i;
    cout << ans << endl;
    return 0;
}