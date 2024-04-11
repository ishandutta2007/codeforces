#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

char tmp[Maxn];
int T;
int n;
string s;
int A[Maxn], B[Maxn];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

bool Check(const string &s)
{
    int st = 0;
    for (int i = 0; i < s.length(); i++) {
        st += s[i] == '('? 1: -1;
        if (st < 0) return false;
    }
    return true;
}

string Reverse(const string &s, int l, int r)
{
    string t = s;
    reverse(t.begin() + l, t.begin() + r + 1);
    return t;
}

string getNext1(const string &s, bool pr = false)
{
    A[0] = 0;
    int lef = Maxn, rig = -Maxn;
    for (int i = 0; i < s.length(); i++) {
        A[i + 1] = A[i] + (s[i] == '('? 1: -1);
        if (A[i + 1] < 0) {
            lef = min(lef, i + 1);
            rig = max(rig, i + 1);
        }
    }
    B[s.length() + 1] = 0;
    for (int i = int(s.length()) - 1; i >= 0; i--)
        B[i + 1] = B[i + 2] + (s[i] == '('? 1: -1);
    int L = 0, R = s.length() + 1;
    for (int i = 1; i < lef; i++)
        if (A[i] > A[L]) L = i;
    for (int i = rig + 1; i <= s.length(); i++)
        if (B[i] < B[R]) R = i;
    if (pr) printf("%d %d\n", L + 1, R - 1);
    return Reverse(s, L, R - 2);
}

string getNext2(const string &s, bool pr = false)
{
    A[0] = 0;
    for (int i = 0; i < s.length(); i++)
        A[i + 1] = A[i] + (s[i] == '('? 1: -1);
    int x = 1;
    for (int i = 2; i <= s.length(); i++)
        if (A[i] > A[x]) x = i;
    if (pr) printf("1 %d\n", x);
    return Reverse(s, 0, x - 1);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        Read(s);
        if (Check(s)) {
            printf("0\n");
            continue;
        }
        if (Check(getNext1(s))) {
            printf("1\n");
            getNext1(s, true);
            continue;
        }
        printf("2\n");
        auto nx1 = getNext2(s, true);
        getNext1(nx1, true);
    }
    return 0;
}