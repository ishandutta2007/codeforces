#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> a[N];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i ++) a[i].resize(m + 1);
        vector<int> vis(n + 10);
        for(int i = 1; i <= n; i ++) 
            for(int j = 1; j <= m; j ++) 
                cin >> a[i][j];
        int sum = 0, flag = 0, ans1 = 0, ans2 = 0;
        for(int i = 1; i <= n; i ++) 
        {
            vector<int> v;
            for(int j = 1; j <= m; j ++) v.push_back(a[i][j]);
            sort(v.begin(), v.end());
            int num = 0;
            for(int j = 1; j <= m; j ++)
                if(v[j - 1] != a[i][j]) num ++;
            if(num > 2) {flag = 1; break;}
            else if(num == 0) continue;
            else 
            {
                for(int j = 1; j <= m; j ++)
                    if(v[j - 1] != a[i][j]) 
                    {
                        if(ans1) ans2 = j;
                        else ans1 = j;
                    }
                break;
            }
        }
        if(flag) {cout << "-1" << "\n"; goto L1;}
        else if(ans1) 
        {
            for(int i = 1; i <= n; i ++) swap(a[i][ans1], a[i][ans2]);
            for(int i = 1; i <= n; i ++) 
            {
                vector<int> v;
                for(int j = 1; j <= m; j ++) v.push_back(a[i][j]);
                sort(v.begin(), v.end());
                for(int j = 1; j <= m; j ++) if(v[j - 1] != a[i][j]) {cout << "-1\n"; goto L1;}
            }
            if(flag) {cout << "-1" << "\n"; goto L1;}
            else {cout << ans1 << " " << ans2 << "\n"; goto L1;}
        } 
        cout << "1 1" << "\n";
        L1:;
    }
}