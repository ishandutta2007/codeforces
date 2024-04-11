#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 1e5 + 10;

int n;
long long a[N];
long long prefval[N], suffval[N];
long long prefsum[N], suffsum[N];

int main() {
//    ifstream cin( "input.txt" );
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long val = a[1] - 1;
    long long sum = 0;
    for(int i = 1; i <= n; ++i) {
         val = max(val + 1, a[i]);
         sum += val - a[i];
         prefval[i] = val;
         prefsum[i] = sum;
    }
    val = a[n] - 1;
    sum = 0;
    for(int i = n; i >= 1; --i) {
        val = max(val + 1, a[i]);
        sum += val - a[i];
        suffval[i] = val;
        suffsum[i] = sum;
    }
    long long result = (ll)1e18 + 10;
    for(int i = 1; i <= n; ++i) {
        long long value = max(a[i], max(prefval[i-1],suffval[i+1])+1);
        result = min(result, prefsum[i-1]+suffsum[i+1]+value-a[i]);
    }
    cout<<result<<endl;
}