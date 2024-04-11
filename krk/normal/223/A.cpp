#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

const int Maxn = 100005;

string s;
int sum[Maxn];
int nil = 0;
stack <int> S;
int best = -1;
int l, r;

void Test(int cl, int cr)
{
    if (cl > cr) return;
    if (sum[cr + 1] - sum[cl] > best) {
        best = sum[cr + 1] - sum[cl];
        l = cl; r = cr;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    getline(cin, s);
    sum[0] = 0;
    for (int i = 1; i <= s.length(); i++) sum[i] = sum[i - 1] + (s[i - 1] == '[');
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')')
            if (S.empty() || s[S.top()] != '(') {
                Test(S.empty()? nil: S.top() + 1, i - 1);
                while (!S.empty()) S.pop();
                nil = i + 1;
            } else S.pop();
        else if (s[i] == ']')
            if (S.empty() || s[S.top()] != '[') {
                Test(S.empty()? nil: S.top() + 1, i - 1);
                while (!S.empty()) S.pop();
                nil = i + 1;
            } else S.pop();
        else S.push(i);
        Test(S.empty()? nil: S.top() + 1, i);
    }
    if (best == -1) cout << "0\n";
    else cout << best << endl << s.substr(l, r - l + 1) << endl;
    return 0;
}