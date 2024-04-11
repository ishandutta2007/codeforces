# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

vector<int> in, out;
int main() {
    int n, m, a[210], ans = -0x3fffffff;
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int l = 1; l<=n; ++l)
        for(int r = l; r<=n; ++r) {
            in.clear(); out.clear(); int sum = 0;
            for(int k=1; k<l; ++k) out.push_back(a[k]);
            for(int k=l; k<=r; ++k) in.push_back(a[k]);
            for(int k=l; k<=r; ++k) sum += a[k];
            for(int k=r+1; k<=n; ++k) out.push_back(a[k]);
            sort(in.begin(), in.end());
            sort(out.begin(), out.end());
            reverse(out.begin(), out.end());

            for(size_t i=0; i<m; ++i) {
                if(i == in.size() || i == out.size()) break;
                if(out[i] <= in[i]) break;
                sum += out[i] - in[i];
            }
            ans = max(ans, sum);
        }
    cout << ans << endl;
    return 0;
}