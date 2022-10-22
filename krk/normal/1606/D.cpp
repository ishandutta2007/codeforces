#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000006;

int T;
int n, m;
vector <int> B[Maxn];
vector <ii> seq;
map <int, int> red[Maxn], blue[Maxn];
char res[Maxn];

void Insert(map <int, int> &M, int val)
{
    auto it = M.find(val);
    if (it == M.end()) M.insert(make_pair(val, 1));
    else it->second++;
}

void Remove(map <int, int> &M, int val)
{
    auto it = M.find(val);
    if (--it->second == 0) M.erase(it);
}

void changeBlue(int row)
{
    for (int j = 0; j < m; j++) {
        Remove(red[j], B[row][j]);
        Insert(blue[j], B[row][j]);
    }
}

int getLine()
{
    int mxblue = 0, mnred = Maxn;
    int b = 0;
    for (int j = 0; j + 1 < m; j++) {
        mxblue = max(mxblue, blue[j].rbegin()->first);
        mnred = min(mnred, red[j].begin()->first);
        if (mxblue < mnred) b = j + 1;
    }
    if (!b) return -1;
    int mxred = 0, mnblue = Maxn;
    for (int j = b; j < m; j++) {
        mxred = max(mxred, red[j].rbegin()->first);
        mnblue = min(mnblue, blue[j].begin()->first);
        if (mxred >= mnblue) return -1;
    }
    return b;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        seq.clear();
        for (int j = 0; j < m; j++) {
            red[j].clear();
            blue[j].clear();
        }
        for (int i = 0; i < n; i++) {
            B[i].resize(m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[i][j]);
                Insert(red[j], B[i][j]);
            }
            seq.push_back(ii(B[i][0], i));
        }
        sort(seq.begin(), seq.end());
        bool found = false;
        for (int i = 0, j; i < seq.size() && !found; i = j) {
            j = i;
            while (j < seq.size() && seq[i].first == seq[j].first)
                j++;
            if (j >= seq.size()) break;
            for (int l = i; l < j; l++)
                changeBlue(seq[l].second);
            int got = getLine();
            if (got != -1) {
                fill(res, res + n, 'R');
                for (int l = 0; l < j; l++)
                    res[seq[l].second] = 'B';
                printf("YES\n");
                res[n] = '\0';
                printf("%s %d\n", res, got);
                found = true;
            }
        }
        if (!found)
            printf("NO\n");
    }
    return 0;
}