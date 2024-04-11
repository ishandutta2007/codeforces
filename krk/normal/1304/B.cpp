#include <bits/stdc++.h>
using namespace std;

map <string, int> M;
int n, m;
string cent;
vector <string> A, B;
int res;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        string rs = s; reverse(rs.begin(), rs.end());
        auto it = M.find(rs);
        if (it != M.end()) {
            res += 2 * m;
            A.push_back(rs); B.push_back(s);
            if (--it->second == 0) M.erase(it);
        } else M[s]++;
    }
    for (auto it: M) {
        int l = 0, r = m - 1;
        while (l < r && it.first[l] == it.first[r]) l++, r--;
        if (l >= r) cent = it.first;
    }
    if (cent.size() > 0) res += m;
    printf("%d\n", res);
    for (int i = 0; i < A.size(); i++)
        printf("%s", A[i].c_str());
    printf("%s", cent.c_str());
    for (int i = int(B.size()) - 1; i >= 0; i--)
        printf("%s", B[i].c_str());
    printf("\n");
    return 0;
}