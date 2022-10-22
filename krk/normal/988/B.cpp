#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
string S[Maxn];

bool Less(const string &a, const string &b)
{
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> S[i];
    sort(S, S + n, Less);
    for (int i = 1; i < n; i++)
        if (S[i].find(S[i - 1]) == string::npos) { printf("NO\n"); return 0; }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        cout << S[i] << endl;
    return 0;
}