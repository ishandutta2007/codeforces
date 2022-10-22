#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

char str[Maxn];
int slen;
vector <vector <int> > paths;
vector <int> LL, LR, RL, RR;
vector <int> res;

void Add(int ind)
{
    for (int i = 0; i < paths[ind].size(); i++)
        res.push_back(paths[ind][i]);
}

int main()
{
    scanf("%s", str + 1); slen = strlen(str + 1);
    for (int i = 1; i <= slen; i++)
        if (str[i] == 'L') {
            int ind;
            if (!LL.empty()) {
                ind = LL.back();
                LL.pop_back();
                LR.push_back(ind);
            } else if (!RL.empty()) {
                ind = RL.back();
                RL.pop_back();
                RR.push_back(ind);
            } else {
                ind = paths.size();
                paths.push_back(vector <int>());
                LR.push_back(ind);
            }
            paths[ind].push_back(i);
        } else {
            int ind;
            if (!RR.empty()) {
                ind = RR.back();
                RR.pop_back();
                RL.push_back(ind);
            } else if (!LR.empty()) {
                ind = LR.back();
                LR.pop_back();
                LL.push_back(ind);
            } else {
                ind = paths.size();
                paths.push_back(vector <int>());
                RL.push_back(ind);
            }
            paths[ind].push_back(i);
        }
    printf("%d\n", int(paths.size()) - 1);
    if (LR.size() < RL.size() || LR.size() == RL.size() && LL.size() < RR.size()) {
        swap(LL, RR);
        swap(LR, RL);
    }
    assert(abs(int(LR.size()) - int(RL.size())) <= 1 && LR.size() >= RL.size());
    while (true) {
        while (!LL.empty()) {
            Add(LL.back());
            LL.pop_back();
        }
        if (LR.empty()) break;
        Add(LR.back());
        LR.pop_back();
        while (!RR.empty()) {
            Add(RR.back());
            RR.pop_back();
        }
        if (RL.empty()) break;
        Add(RL.back());
        RL.pop_back();
    }
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}