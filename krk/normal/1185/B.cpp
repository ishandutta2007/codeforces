#include <bits/stdc++.h>
using namespace std;

typedef pair <char, int> ci;

const int Maxl = 1000005;

char tmp[Maxl];
int t;

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

vector <ci> Get(const string &s)
{
    vector <ci> res;
    for (int i = 0, j; i < s.length(); i = j) {
        j = i;
        while (j < s.length() && s[i] == s[j]) j++;
        res.push_back(ci(s[i], j - i));
    }
    return res;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        string a, b; Read(a); Read(b);
        auto A = Get(a);
        auto B = Get(b);
        bool ok = A.size() == B.size();
        for (int i = 0; i < A.size() && ok; i++)
            ok = A[i].first == B[i].first && A[i].second <= B[i].second;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}