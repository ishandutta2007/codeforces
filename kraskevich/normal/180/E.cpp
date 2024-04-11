#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cube
{
       int val, num;
};

bool cmp(cube a, cube b)
{
     return a.val < b.val || a.val == b.val && a.num < b.num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m, k;
    
    cin >> n >> m >> k;
    
    int a[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    cube b[n];
    for(int i = 0; i < n; ++i)
    {
            b[i].val = a[i];
            b[i].num = i;
    }
    
    sort(b, b + n, cmp);
    
    vector<vector<int> > gr;
    
    vector<int> cur;
    
    for(int i = 0; i < n; ++i)
    {
            cur.push_back(b[i].num);
            if(i == n - 1 || b[i].val != b[i + 1].val)
                 gr.push_back(cur), cur.clear();
    }
    
    int ans = 0;
    
    for(int g = 0; g < gr.size(); ++g)
    {
            vector<int> cur = gr[g];
            int sz = cur.size();
            int sum[sz];
            sum[0] = 0;
            for(int i = 1; i < sz; ++i)
                    sum[i] = sum[i - 1] + cur[i] - cur[i - 1] - 1;
            for(int l = 0, r = 0; l < sz && r < sz; ++l)
            {
                    while(r < sz && sum[r] - sum[l] <= k)
                                 ++r;
                    --r;
                    ans = max(ans, cur[r] - cur[l] + 1 - sum[r] + sum[l] );
            }
                    
    }
    
    cout << ans;
    
    cin >> n;
    
    return 0;
}