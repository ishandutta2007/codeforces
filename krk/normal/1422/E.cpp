#include <bits/stdc++.h>
using namespace std;

typedef pair <char, char> cc;

const int Maxn = 100005;

char str[Maxn];
int slen;
vector <cc> V;
int res[Maxn];
string ans[Maxn];

string Construct()
{
    string res;
    if (V.size() <= 10)
        for (int i = int(V.size()) - 1; i >= 0; i--)
            res += V[i].first;
    else {
        for (int i = 1; i <= 5; i++)
            res += V[int(V.size()) - i].first;
        res += "...";
        res += V[1].first;
        res += V[0].first;
    }
    return res;
}

int main()
{
    bool forb = false;
    scanf("%s", str);
    slen = strlen(str);
    for (int i = slen - 1; i >= 0; i--) {
        if (V.empty()) { V.push_back(cc(str[i], 'a' - 1)); forb = false; }
        else {
            char lst = V.back().first == str[i]? V.back().second: V.back().first;
            V.push_back(cc(str[i], lst));
            if (V.size() >= 2 && V[int(V.size()) - 2].first == V.back().first &&
                V.back().first > V.back().second && !forb) {
                V.pop_back();
                V.pop_back();
                forb = true;
            } else if (forb) forb = false;
        }
        res[i] = V.size();
        ans[i] = Construct();
    }
    for (int i = 0; i < slen; i++)
        printf("%d %s\n", res[i], ans[i].c_str());
    return 0;
}