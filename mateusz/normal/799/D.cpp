#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, a, b, h, w;
int aa[N];
int divA, divB;
bool dp[N];

bool good(vector<int> &v) {
    for (int i = 1; i < divA; i++) {
        dp[i] = false;
    }
    dp[1] = true;
    unsigned long long bestValue = 1e18;
    for (int i = 0; i < v.size(); i++) {
        int value = v[i];
        for (int j = divA - 1; j >= 1; j--) {
            if (dp[j] == false) continue;
            unsigned long long newValue = (unsigned long long)j * value;
            if (newValue >= divA) {
                bestValue = min(bestValue, newValue);
            } else {
                dp[newValue] = true;
            }
        }
    }
    
    unsigned long long rest = 1;
    if (rest / bestValue >= divB) {
        return true;
    }
    for (int i = v.size() -1 ; i >= 0; i--) {
        rest *= v[i];
        cerr << rest << " " << bestValue << " " << divB << endl;
        if (rest / bestValue >= divB) {
            return true;
        }
    }
    
    return false;
}

int solve(int a, int b, int h, int w) {
        
    divA = (a + h - 1) / h;
    divB = (b + w - 1) / w;
    
    if (h >= a && w >= b) {
        return 0;
    }
    
    if (divA < divB) {
        swap(divA, divB);
    }
    
    int low = 0;
    int high = min(n, 34);
    int res = n + 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        cerr << mid << endl;
        vector<int> v;
        for (int i = 1; i <= mid; i++) {
            v.push_back(aa[i]);
        }
        if (good(v)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return res;
}


int main() {
  
    scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
    

    for (int i = 1; i <= n; i++) {
        scanf("%d", &aa[i]);
    }
    
    sort(aa + 1, aa + 1 + n);
    reverse(aa + 1, aa + 1 + n);
    
    
    int res = solve(a, b, h, w);
    
    res = min(res, solve(b, a, h, w));

    if (res == n + 1) {
        printf("-1\n");
    } else {
        printf("%d\n", res);
    }
    
    return 0;
}