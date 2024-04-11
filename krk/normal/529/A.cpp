#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <ll, int> lli;

const int Maxl = 1000005;

char s[Maxl];
int id[Maxl];
lli srt[Maxl];
int slen;
int st;
int my[Maxl];
int mnlen = Maxl, mxop, bind, cp;
set <ii> S;
int nil;
int op;

void Print(int bind)
{
    for (int i = bind; i < slen; i++)
        printf("%c", s[i] == '('? '0': '1');
    for (int i = 0; i < bind; i++)
        printf("%c", s[i] == '('? '0': '1');
    printf("\n");
}

int main()
{
    scanf("%s", s); slen = strlen(s);

    for (int i = 0; i < slen; i++)
        id[i] = s[i] == '('? 0: 1;
    for (int h = 1; h <= slen; h <<= 1) {
        for (int i = 0; i < slen; i++)
            srt[i] = lli(ll(id[i]) * Maxl + id[(i + h) % slen], i);
        sort(srt, srt + slen);
        int cur = -1;
        ll lst = -1;
        for (int i = 0; i < slen; i++) {
            if (srt[i].first != lst) { cur++; lst = srt[i].first; }
            id[srt[i].second] = cur;
        }
    }

    bool cnt = true;
    for (int i = 0; i < slen; i++) {
        my[i] = st;
        S.insert(ii(st, i));
        if (s[i] == '(') {
            st++;
            if (cnt) op++;
        } else {
            st--;
            cnt = false;
        }
    }
    for (int i = slen - 1; i >= 0; i--) {
        int nlen = max(0, -st);
        if (S.begin()->first - nil < 0) nlen = max(nlen, nil - S.begin()->first);
        int mcp = (i + 1 + op) % slen;
        if (nlen < mnlen || nlen == mnlen && op > mxop ||
            nlen == mnlen && op == mxop && id[mcp] < id[cp]) { mnlen = nlen; mxop = op; bind = i + 1; cp = mcp; }
        S.erase(ii(my[i], i));
        if (s[i] == '(') { nil--; op++; S.insert(ii(nil, i)); }
        else { nil++; op = 0; S.insert(ii(nil, i)); }
    }
    for (int i = 0; i < mnlen; i++)
        printf("(");
    for (int i = bind; i < slen; i++)
        printf("%c", s[i]);
    for (int i = 0; i < bind; i++)
        printf("%c", s[i]);
    int nd = st + mnlen;
    for (int i = 0; i < nd; i++)
        printf(")");
    printf("\n");
    return 0;
}