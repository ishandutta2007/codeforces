#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
vector<int> v;
vector<long long> pref;

double find() {
    if (v.size() == 1) {
        return 0.0;
    }
    int low = 0;
    int high = v.size() - 2;
    int res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long sum = (mid == 0 ? 0 : pref[mid - 1]) + v.back();
        if (sum > (long long)v[mid] * (mid + 1)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    if (res == -1) return 0.0;
    
    return (double)v.back() - (double)(pref[res] + v.back()) / (res + 2);
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int type;
        int x;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            v.push_back(x);
            pref.push_back((pref.empty() ? 0 : pref.back()) + x);
        } else {
            double ans = find();
            printf("%.10lf\n", ans);
        }
    }
    
    return 0;
}