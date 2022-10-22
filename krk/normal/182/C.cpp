#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

struct nums {
    multiset <int> S;
    ll sum;
    nums() { S.clear(); sum = 0; }
    bool Check(int x) { return S.find(x) != S.end(); }
    int Max() { return *S.rbegin(); }
    int Min() { return *S.begin(); }
    int Insert(int x) { S.insert(x); sum += x; }
    void Erase(int x) { S.erase(S.find(x)); sum -= x; }
    int Size() { return S.size(); }
};

int n, len;
int a[Maxn];
int k;
nums negk, posk, oth;
ll res;

void Add(int x)
{
    if (x > 0)
        if (posk.Size() < k) posk.Insert(x);
        else if (posk.Size() && x > posk.Min()) { oth.Insert(posk.Min()); posk.Erase(posk.Min()); posk.Insert(x); }
        else oth.Insert(x);
    else if (x < 0)
        if (negk.Size() < k) negk.Insert(x);
        else if (negk.Size() && x < negk.Max()) { oth.Insert(negk.Max()); negk.Erase(negk.Max()); negk.Insert(x); }
        else oth.Insert(x);
    else oth.Insert(x);
}

void Remove(int x)
{
    if (oth.Check(x)) oth.Erase(x);
    else if (negk.Check(x)) {
            negk.Erase(x);
            if (oth.Size() > 0 && oth.Min() < 0) {
                negk.Insert(oth.Min()); oth.Erase(oth.Min());
            }
         } else if (posk.Check(x)) {
             posk.Erase(x);
             if (oth.Size() > 0 && oth.Max() > 0) {
                 posk.Insert(oth.Max()); oth.Erase(oth.Max());
             }
         }
}

ll Result()
{
    return max(abs(-negk.sum + oth.sum + posk.sum), abs(negk.sum + oth.sum - posk.sum));
}

int main()
{
    scanf("%d %d", &n, &len);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &k);
    for (int i = 0; i < len; i++) Add(a[i]);
    res = Result();
    for (int i = 0; i + len < n; i++) {
        Remove(a[i]); Add(a[i + len]);
        res = max(res, Result());
    }
    printf("%I64d\n", res);
    return 0;
}