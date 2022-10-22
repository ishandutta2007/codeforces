#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;

bool Ask(const vector <int> &V)
{
    printf("? %d", int(V.size()));
    for (int i = 0; i < V.size(); i++)
        printf(" %d", V[i]);
    printf("\n"); fflush(stdout);
    string s; cin >> s;
    return s == "YES";
}

bool Answer(int x)
{
    printf("! %d\n", x); fflush(stdout);
    string s; cin >> s;
    return s == ":)";
}

vector <int> Cut(const vector <int> &V, int a, int siz)
{
    vector <int> res;
    for (int i = 0; i < siz; i++)
        res.push_back(V[a + i]);
    return res;
}

vector <int> Merge(const vector <int> &A, const vector <int> &B)
{
    vector <int> res;
    for (int i = 0; i < A.size(); i++)
        res.push_back(A[i]);
    for (int i = 0; i < B.size(); i++)
        res.push_back(B[i]);
    return res;
}

int main()
{
    scanf("%d", &n);
    vector <int> seq;
    for (int i = 1; i <= n; i++)
        seq.push_back(i);
    while (seq.size() > 2) {
        int a = seq.size() / 3;
        vector <int> fir = Cut(seq, 0, a);
        if (Ask(fir)) {
            int hm = (int(seq.size()) - a) / 2;
            vector <int> sec = Cut(seq, a, hm);
            if (Ask(sec)) seq = Merge(fir, sec);
            else {
                int hm2 = int(seq.size()) - a - hm;
                seq = Merge(fir, Cut(seq, a + hm, hm2));
            }
        } else if (Ask(fir)) {
            int hm = (int(seq.size()) - a) / 2;
            vector <int> sec = Cut(seq, a, hm);
            if (Ask(sec)) seq = Merge(fir, sec);
            else {
                int hm2 = int(seq.size()) - a - hm;
                seq = Merge(fir, Cut(seq, a + hm, hm2));
            }
        } else seq = Cut(seq, a, int(seq.size()) - a);
    }
    for (int i = 0; i < seq.size(); i++)
        if (Answer(seq[i])) break;
    return 0;
}