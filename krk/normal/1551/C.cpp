#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

char tmp[Maxn];
int T;
int n;
string S[Maxn];
int res;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            Read(S[i]);
        res = 0;
        for (char ch = 'a'; ch <= 'e'; ch++) {
            vector <int> seq;
            int cnt = 0, st = 0;
            for (int i = 0; i < n; i++) {
                int cand = 0;
                for (int j = 0; j < S[i].size(); j++)
                    cand += S[i][j] == ch? 1: -1;
                if (cand > 0) { cnt++; st += cand; }
                else seq.push_back(-cand);
            }
            sort(seq.begin(), seq.end());
            for (int i = 0; i < seq.size(); i++)
                if (seq[i] < st) { st -= seq[i]; cnt++; }
            res = max(res, cnt);
        }
        printf("%d\n", res);
    }
    return 0;
}