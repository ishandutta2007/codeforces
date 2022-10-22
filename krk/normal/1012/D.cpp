#include <bits/stdc++.h>
using namespace std;
 
typedef pair <char, int> ci;
typedef pair <int, int> ii;
 
const int Maxn = 200005;
 
char S[Maxn];
int slen;
char T[Maxn];
int tlen;
deque <ci> A, B;
deque <ii> res;

deque <ii> simpleSolve(deque <ci> A, deque <ci> B)
{
    deque <ii> res;
    if (A.front().first == B.front().first)
        if (A.size() < B.size()) {
            A.front().second += B.front().second;
            res.push_back(ii(0, B.front().second));
            B.pop_front();
        } else {
            B.front().second += A.front().second;
            res.push_back(ii(A.front().second, 0));
            A.pop_front();
        }
    while (A.size() > 1 || B.size() > 1)
        if (A.empty()) {
            res.push_back(ii(0, B[0].second));
            A.push_front(B[0]);
            B.pop_front();
        } else if (B.empty()) {
            res.push_back(ii(0, A[0].second));
            B.push_front(A[0]);
            A.pop_front();
        } else {
            res.push_back(ii(A[0].second, B[0].second));
            swap(A[0], B[0]);
            if (A.size() >= 2) { A[1].second += A[0].second; A.pop_front(); }
            if (B.size() >= 2) { B[1].second += B[0].second; B.pop_front(); }
        }
    return res;
}

void addSafeFront(deque <ci> &D, ci val)
{
    if (D.empty() || D.front().first != val.first) D.push_front(val);
    else D.front().second += val.second;
}
 
deque <ii> Solve(deque <ci> A, deque <ci> B)
{
    if (A.size() > B.size()) {
        auto res = Solve(B, A);
        for (int i = 0; i < res.size(); i++)
            swap(res[i].first, res[i].second);
        return res;
    }
    int best = max(A.size(), B.size()) - 1 + (A.size() == B.size() && A[0].first == B[0].first);
    int ind = -1;
    for (int i = 0; i < B.size(); i++) {
        int asiz = i + 1 + int(A.size()) - 1 - int(A.size() > 1 && A[1].first == B[i].first);
        int bsiz = 1 + int(B.size()) - 1 - i - int(B.size() > i + 1 && A[0].first == B[i + 1].first);
        int cand = max(asiz, bsiz) - 1 + (asiz == bsiz && A[0].first == B[0].first);
        if (cand + 1 < best) { best = cand + 1; ind = i; }
        asiz = i + 1 + int(A.size()) - (A[0].first == B[i].first);
        bsiz = int(B.size()) - 1 - i;
        cand = max(asiz, bsiz) - 1 + (asiz == bsiz && B[0].first == B[i + 1].first);
        if (cand + 1 < best) { best = cand + 1; ind = int(B.size()) + i; }
    }
    if (ind == -1) return simpleSolve(A, B);
    int sum1 = ind < B.size()? A[0].second: 0;
    ii sav;
    if (ind < B.size()) {
        sav = A.front();
        A.pop_front();
    } else ind -= B.size();
    int sum2 = 0;
    for (int i = ind; i >= 0; i--) {
        sum2 += B[i].second;
        addSafeFront(A, B[i]);
    }
    for (int i = 0; i <= ind; i++)
        B.pop_front();
    if (sum1 > 0) addSafeFront(B, sav);
    auto res = simpleSolve(A, B);
    res.push_front(ii(sum1, sum2));
    return res;
}
 
int main()
{
    scanf("%s", S + 1);
    slen = strlen(S + 1);
    scanf("%s", T + 1);
    tlen = strlen(T + 1);
    int cnt = 0;
    for (int i = 1; i <= slen; i++) {
        cnt++;
        if (i == slen || S[i] != S[i + 1]) {
            A.push_back(ci(S[i], cnt));
            cnt = 0;
        }
    }
    for (int i = 1; i <= tlen; i++) {
        cnt++;
        if (i == tlen || T[i] != T[i + 1]) {
            B.push_back(ci(T[i], cnt));
            cnt = 0;
        }
    }
    auto res = Solve(A, B);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}