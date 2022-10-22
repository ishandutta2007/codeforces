#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 2000000007;
const int Maxn = 100005;

vector <int> un;
int n, m;
int B[Maxn];
int mylin[Maxn];
ii lin[Maxn];
int A[Maxn];
int Y[Maxn], X[Maxn];
vector <ii> seq1;
vector <ii> seq2;
vector <int> st[Maxn];
vector <int> BIT[Maxn];
int res[Maxn];

void insertIner(vector <int> &BIT, int ind, int val)
{
    ind++;
    for (int i = ind; i > 0; i -= i & -i)
        BIT[i] += val;
}

int getIner(const vector <int> &BIT, int ind)
{
    ind++;
    int res = 0;
    for (int i = ind; i < BIT.size(); i += i & -i)
        res += BIT[i];
    return res;
}

void attachOuter(int ind, int val)
{
    ind++;
    for (int i = ind; i <= un.size(); i += i & -i)
        if (st[i].empty() || st[i].back() != val)
            st[i].push_back(val);
}

void createOuter()
{
    for (int i = 1; i <= un.size(); i++)
        BIT[i].resize(st[i].size() + 1, 0);
}

void addOuter(int ind, int y, int val)
{
    ind++;
    for (int i = ind; i <= un.size(); i += i & -i) {
        int ind = lower_bound(st[i].begin(), st[i].end(), y) - st[i].begin();
        insertIner(BIT[i], ind, val);
    }
}

int getOuter(int ind, int y)
{
    ind++;
    int res = 0;
    for (int i = ind; i > 0; i -= i & -i) {
        int ind = lower_bound(st[i].begin(), st[i].end(), y) - st[i].begin();
        res += getIner(BIT[i], ind);
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &lin[i].first);
        lin[i].second = i;
        mylin[i] = lin[i].first;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        un.push_back(B[i] - A[i]);
        seq1.push_back(ii(A[i] + B[i], i));
    }
    sort(seq1.begin(), seq1.end());
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    sort(lin, lin + n);
    for (int i = 0; i < n; i++) {
        int ind = lin[i].second;
        int bitind = lower_bound(un.begin(), un.end(), B[ind] - A[ind]) - un.begin();
        attachOuter(bitind, lin[i].first);
    }
    createOuter();
    for (int i = 0; i < m; i++)
        scanf("%d", &Y[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d", &X[i]);
        seq2.push_back(ii(X[i] + Y[i], i));
    }
    sort(seq2.begin(), seq2.end());
    int pnt = 0;
    for (int i = 0; i < seq2.size(); i++) {
        while (pnt < seq1.size() && seq1[pnt].first <= seq2[i].first) {
            int ind = seq1[pnt].second;
            int bitind = lower_bound(un.begin(), un.end(), B[ind] - A[ind]) - un.begin();
            addOuter(bitind, mylin[ind], 1);
            pnt++;
        }
        int ind = seq2[i].second;
        int bitind = upper_bound(un.begin(), un.end(), Y[ind] - X[ind]) - un.begin() - 1;
        res[ind] = getOuter(bitind, Y[ind]);
    }
    for (int i = 0; i < m; i++)
        printf("%d%c", res[i], i + 1 < m? ' ': '\n');
    return 0;
}