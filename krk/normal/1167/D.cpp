#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector <int> S;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '(') {
            if (S.empty() || S.back() == 1) S.push_back(0);
            else S.push_back(1);
            printf("%d", S.back());
        } else {
            printf("%d", S.back());
            S.pop_back();
        }
    printf("\n");
    return 0;
}