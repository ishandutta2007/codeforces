#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int dv[25][3];
int n;
map<pair<int,int>, pair<string,int> > m;
pair<string,int> res("",-1e9);

char st[] = "LMW";

char s[25];

void gen1(int i, int e, int v[3]) {
    if (i == e) {
        int d1 = v[1]-v[0];
        int d2 = v[2]-v[1];
        //printf("%s\n", s);
        auto p = make_pair(d1,d2);
        if (!m.count(p) || m[p].second < v[0]) {
            m[p] = make_pair(string(s),v[0]);
        }
    } else {
        FO(j,0,3) v[j] += dv[i][j];
        FO(j,0,3) {
            v[j] -= dv[i][j];
            s[i] = st[j];
            gen1(i+1, e, v);
            v[j] += dv[i][j];
        }
        FO(j,0,3) v[j] -= dv[i][j];
    }
}

int tv[3];

void gen2(int i, int e, int v[3]) {
    if (i == e) {
        int d1 = v[1]-v[0];
        int d2 = v[2]-v[1];
        if (m.count(make_pair(-d1,-d2))) {
            auto pt = m[make_pair(-d1,-d2)];
            string t = pt.first;
            int v0 = v[0] + pt.second;
            FO(j,0,sz(t)) s[j] = t[j];
            if (v0 > res.second) res = make_pair(s,v0);
        }
    } else {
        FO(j,0,3) v[j] += dv[i][j];
        FO(j,0,3) {
            v[j] -= dv[i][j];
            s[i] = st[j];
            gen2(i+1, e, v);
            v[j] += dv[i][j];
        }
        FO(j,0,3) v[j] -= dv[i][j];
    }
}

int v[3];

int main() {
    scanf("%d", &n);
    FO(i,0,n) FO(j,0,3) scanf("%d", &dv[i][j]);
    gen1(0,n/2,v);
    memset(v,0,sizeof v);
    gen2(n/2,n,v);
    if (sz(res.first)) {
        FO(j,0,n) s[j] = res.first[j];
        FO(j,0,n) {
            FO(k,0,3) if (st[k] != s[j]) {
                printf("%c", st[k]);
                tv[k] += dv[j][k];
            }
            printf("\n");
            //printf("%d %d %d\n", tv[0], tv[1], tv[2]);
        }
        assert(tv[0] == tv[1] && tv[1] == tv[2]);
        exit(0);
    }
    printf("Impossible\n");
}