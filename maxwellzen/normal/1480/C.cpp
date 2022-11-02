#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int n, lo, hi, mid;
vi nums(100001, -1);

int get(int i) {
    if (i<0 || i>=n) return INT_MAX;
    if (nums[i]!=-1) return nums[i];
    cout << "? " << i+1 << endl;
    cin >> nums[i];
    return nums[i];
}

int main() {
    cin.tie(NULL);
    cin >> n;
    if (get(0)<get(1)) {
        cout << "! " << 1 << endl;
        return 0;
    }
    if (get(n-1) < get(n-2)) {
        cout << "! " << n << endl;
        return 0;
    }
    lo = 0;
    hi = n-2;
    while (hi > lo+1) {
        mid = (lo+hi)/2;
        if (get(mid)>get(mid+1)) lo=mid;
        else hi=mid;
    }
    cout << "! " << hi+1 << endl;
    return 0;
}