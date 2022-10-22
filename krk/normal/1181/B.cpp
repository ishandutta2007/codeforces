#include <bits/stdc++.h>
using namespace std;

string s;
vector <char> A, B;
vector <char> cand;
vector <char> res;

bool Less()
{
    if (res.empty()) return true;
    if (res.size() != cand.size()) return cand.size() < res.size();
    for (int i = int(res.size()) - 1; i >= 0; i--)
        if (res[i] != cand[i]) return cand[i] < res[i];
    return false;
}

void Check(int pnt)
{
    if (s[pnt] == '0') return;
    if (!res.empty() && max(pnt, int(s.length()) - pnt) > res.size()) return;
    A.clear(); B.clear();
    for (int i = pnt - 1; i >= 0; i--)
        A.push_back(s[i]);
    for (int i = int(s.length()) - 1; i >= pnt; i--)
        B.push_back(s[i]);
    cand.clear();
    int cur = 0;
    for (int i = 0; i < A.size() || i < B.size() || cur; i++) {
        if (i < A.size()) cur += A[i] - '0';
        if (i < B.size()) cur += B[i] - '0';
        cand.push_back(cur % 10 + '0');
        cur /= 10;
    }
    if (Less()) res = cand;
}

int main()
{
    int n; cin >> n;
    cin >> s;
    int m = n / 2;
    for (int i = 0; i <= n; i++) {
        if (m - i > 0) Check(m - i);
        if (m + i < n) Check(m + i);
    }
    for (int i = int(res.size()) - 1; i >= 0; i--)
        printf("%c", res[i]);
    printf("\n");
    return 0;
}