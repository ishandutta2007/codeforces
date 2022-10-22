#include <bits/stdc++.h>
using namespace std;

const int Maxn = 6005;

char tmp[Maxn];
int n;
string A[Maxn];
string B[Maxn];
int L[Maxn], R[Maxn];
string res1, res2;
char S[Maxn];
int slen;
int Z[Maxn];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

string getStart(const string &a, const string &b)
{
    int pnt = 0;
    while (pnt < a.length() && pnt < b.length() && a[pnt] == b[pnt]) pnt++;
    if (pnt == 0) return "";
    return a.substr(0, pnt);
}

string getEnd(const string &a, const string &b)
{
    int pnt = 0;
    while (pnt < a.length() && pnt < b.length() &&
           a[int(a.length()) - 1 - pnt] == b[int(b.length()) - 1 - pnt]) pnt++;
    if (pnt == 0) return "";
    return a.substr(int(a.length()) - pnt);
}

int Get(int ind)
{
    slen = 0;
    for (int i = 0; i < res1.length(); i++)
        S[slen++] = res1[i];
    S[slen++] = '#';
    for (int i = 0; i < A[ind].length(); i++)
        S[slen++] = A[ind][i];
    fill(Z, Z + Maxn, 0);
    int L = -1, R = -1;
    for (int i = 1; i < slen; i++) {
        if (i <= R) Z[i] = min(Z[i - L], R - i);
        while (i + Z[i] < slen && S[Z[i]] == S[i + Z[i]]) Z[i]++;
        if (Z[i] >= res1.length()) return i - int(res1.length()) - 1;
        if (i + Z[i] - 1 > R) {
            R = i + Z[i] - 1; L = i;
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        Read(A[i]);
    string sam1, sam2, st, en;
    for (int i = 0; i < n; i++) {
        Read(B[i]);
        while (L[i] < A[i].length() && A[i][L[i]] == B[i][L[i]]) L[i]++;
        if (L[i] == A[i].length()) L[i] = R[i] = -1;
        else {
            R[i] = int(A[i].length()) - 1;
            while (A[i][R[i]] == B[i][R[i]]) R[i]--;
            string tmp1 = A[i].substr(L[i], R[i] - L[i] + 1);
            string tmp2 = B[i].substr(L[i], R[i] - L[i] + 1);
            if (sam1.length() == 0) {
                sam1 = tmp1; sam2 = tmp2;
                st = A[i].substr(0, L[i]), en = A[i].substr(R[i] + 1);
            } else if (sam1 != tmp1 || sam2 != tmp2) { printf("NO\n"); return 0; }
            else {
                st = getEnd(st, A[i].substr(0, L[i]));
                en = getStart(en, A[i].substr(R[i] + 1));
            }
        }
    }
    res1 = st + sam1 + en;
    res2 = st + sam2 + en;
    for (int i = 0; i < n; i++)
        if (L[i] == -1) {
            if (Get(i) != -1) { printf("NO\n"); return 0; }
        } else {
            int got = Get(i);
            if (got == -1 || got + int(st.length()) != L[i]) {
                printf("NO\n"); return 0;
            }
        }
    printf("YES\n");
    printf("%s\n", res1.c_str());
    printf("%s\n", res2.c_str());
    return 0;
}