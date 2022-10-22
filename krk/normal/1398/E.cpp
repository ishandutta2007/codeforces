#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
set <int> amn, amx;
ll asum, acnt;
set <int> bmn, bmx;
ll bsum, bcnt;
ll sum;

ll Fix()
{
    if (bcnt == 0) return 0;
    if (acnt == 0) {
        while (bmx.size() < bcnt - 1) {
            bmx.insert(*bmn.rbegin());
            bsum += *bmn.rbegin();
            bmn.erase(*bmn.rbegin());
        }
        while (bmx.size() > bcnt - 1) {
            bmn.insert(*bmx.begin());
            bsum -= *bmx.begin();
            bmx.erase(*bmx.begin());
        }
        return bsum;
    }
    if (acnt > 0 && amx.empty()) {
        amx.insert(*amn.rbegin());
        asum += *amn.rbegin();
        amn.erase(*amn.rbegin());
    }
    while (amx.size() + bmx.size() > bcnt)
        if (amx.size() > 1 && (bmx.empty() || *amx.begin() < *bmx.begin())) {
            amn.insert(*amx.begin());
            asum -= *amx.begin();
            amx.erase(*amx.begin());
        } else {
            bmn.insert(*bmx.begin());
            bsum -= *bmx.begin();
            bmx.erase(*bmx.begin());
        }
    while (amx.size() + bmx.size() < bcnt)
        if (!amn.empty() && (bmn.empty() || *amn.rbegin() > *bmn.rbegin())) {
            amx.insert(*amn.rbegin());
            asum += *amn.rbegin();
            amn.erase(*amn.rbegin());
        } else {
            bmx.insert(*bmn.rbegin());
            bsum += *bmn.rbegin();
            bmn.erase(*bmn.rbegin());
        }
    while (amx.size() > 1 && bmn.size() > 0 && (*amx.begin() < *bmn.rbegin())) {
        amn.insert(*amx.begin());
        asum -= *amx.begin();
        amx.erase(*amx.begin());
        bmx.insert(*bmn.rbegin());
        bsum += *bmn.rbegin();
        bmn.erase(*bmn.rbegin());
    }
    while (amn.size() > 0 && bmx.size() > 0 && (*amn.rbegin() > *bmx.begin())) {
        bmn.insert(*bmx.begin());
        bsum -= *bmx.begin();
        bmx.erase(*bmx.begin());
        amx.insert(*amn.rbegin());
        asum += *amn.rbegin();
        amn.erase(*amn.rbegin());
    }
    return asum + bsum;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int typ, d; scanf("%d %d", &typ, &d);
        if (typ == 0)
            if (d > 0) {
                acnt++; sum += d;
                if (amn.empty()) { asum += d; amx.insert(d); }
                else if (d > *amn.rbegin()) { asum += d; amx.insert(d); }
                else amn.insert(d);
            } else {
                d = -d;
                acnt--; sum -= d;
                if (amn.count(d)) amn.erase(d);
                else { asum -= d; amx.erase(d); }
            }
        else if (d > 0) {
            bcnt++; sum += d;
            if (bmn.empty()) { bsum += d; bmx.insert(d); }
            else if (d > *bmn.rbegin()) { bsum += d; bmx.insert(d); }
            else bmn.insert(d);
        } else {
            d = -d;
            bcnt--; sum -= d;
            if (bmn.count(d)) bmn.erase(d);
            else { bsum -= d; bmx.erase(d); }
        }
        printf("%I64d\n", sum + Fix());
    }
    return 0;
}