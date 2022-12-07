#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
const int N = 2000 + 10;
int la[N], n, k;
string s[N];
vector<int> D(int l,int r)
{
    vector<int> res;
    if(r - l == 1)
    {
        res.pb(0);
        res.pb(0);
        return res;
    }
    int mid = min_element(la + l, la + r - 1) - la;
    vector<int>a = D(l, mid+1);
    vector<int>b = D(mid+1, r);
    res.resize(r - l + 1);
    for(int i = 0; i < (int)res.size(); i ++)
    for(int j = 0; j <= i && j < (int)a.size(); j ++)
    {
        if(i - j >= b.size()) continue;
        res[i] = max(res[i], a[j] + b[i - j] + j * (i - j) * la[mid]);
    }
    return res;
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i ++)
        cin >> s[i];
    sort(s, s + n);
    for(int i = 0; i < n - 1; i ++)
    {
        int cur = 0;
        while(cur < s[i].size() && cur < s[i+1].size() && s[i][cur] == s[i +1][cur]) cur++;
        la[i] = cur;
    }
    vector<int>ans = D(0, n);
    cout << ans[k] << endl;
}