#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector <int> treeright, treeleft;
void update(int v, int l, int r, int ind, int val)
{
    if(l == r)
    {
        if(val == 0)
        {
            treeright[v] = -1;
            treeleft[v] = 1e9;
        }
        else
        {
            treeright[v] = treeleft[v] = l;
        }
        return ;
    }
    if(ind <= (r + l) / 2)
    {
        update(v * 2, l, (r + l) / 2, ind, val);
    }
    else
    {
        update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
    }
    treeright[v] = max(treeright[v * 2], treeright[v * 2 + 1]);
    treeleft[v] = min(treeleft[v * 2], treeleft[v * 2 + 1]);
}
int ans1(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return treeright[v];
    }
    else if(l <= ar && r >= al)
    {
        return max(ans1(v * 2, l, (r + l) / 2, al, ar), ans1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
    }
    return -1;
}
int ans2(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return treeleft[v];
    }
    else if(l <= ar && r >= al)
    {
        return min(ans2(v * 2, l, (r + l) / 2, al, ar), ans2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
    }
    return 1e9;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
    {
        int n, k;
        cin >> n >> k;
        treeright.resize(4 * n);
        treeleft.resize(4 * n);
        vector <int> a(n);
        vector <int> b(k);
            vector <int> ind(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
            ind[a[i]] = i;
        }
        set <int> s;
        set <int> s1;
        for(int i = 0; i < k; i++)
        {
            cin >> b[i];
            b[i]--;
            b[i] = ind[b[i]];
            s.insert(b[i]);
        }
        for(int i = 0; i < n; i++)
        {
            update(1, 0, n - 1, i, 1);
        }
        for(int i = 0; i < n; i++)
        {
            if(s.find(i) == s.end()){
                s1.insert(i);
            }
        }
        int ans = 1;
        for(int i = 0; i < k; i++)
        {
            int cnt = 0;
            if(b[i] != 0)
            {
                int t = ans1(1, 0, n - 1, 0, b[i] - 1);
                if(t != -1 && s.find(t) == s.end())
                {
                    cnt++;
                    update(1, 0, n - 1, t, 0);
                }
            }
            if(b[i] != n - 1)
            {
                int t = ans2(1, 0, n - 1, b[i] + 1, n - 1);
                if(t != 1e9 && s.find(t) == s.end())
                {
                    if(cnt == 0)
                    {
                        update(1, 0, n - 1, t, 0);
                    }
                    cnt++;
                }
            }
            ans = 1LL * ans * cnt % mod;
            s.erase(b[i]);
        }
        cout << ans << "\n";
    }
  	return 0;
}