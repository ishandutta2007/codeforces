
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n;
int d;
vector<pair<int, int> > v;
vector<pair<int, int> > edges;
int len;
int arr[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> d;
        v.push_back({d, i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        arr[i] = 2 * v[n - i - 1].second - 1;
    }
    len = n;
    for(int i = 0; i < n; i++) {
        d = v[n - i - 1].first;
        int idx = v[n - i - 1].second;
        if(i + d < len) {
            edges.push_back({arr[i + d - 1], 2 * idx});
        }else {
            arr[len++] = 2 * idx;
        }
    }
    for(int i = 1; i < len; i++) {
        cout << arr[i - 1] << " " << arr[i] << endl;
    }
    for(pair<int, int> p : edges) {
        cout << p.first << " " << p.second << endl;
    }
}