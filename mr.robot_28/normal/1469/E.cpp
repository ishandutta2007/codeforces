#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
string s;
struct node{
    node* left;
    node* right;
    int _sz;
    node():
        left(0),
        right(0),
        _sz(1){};
};
node* tree;
void go_to(node* &v, int i, int j)
{
    if(i == j)
    {
        return;
    }
    if(s[i] == '1')
    {
        if(!v -> right)
        {
            v -> right = new node();
        }
        go_to(v -> right, i + 1, j);
    }
    else
    {
        if(!v -> left)
        {
            v -> left = new node();
        }
        go_to(v -> left, i + 1, j);
    }
    v -> _sz = 0;
    if(!v -> left)
    {

    }
    else
    {
        v -> _sz += v -> left -> _sz;
    }
    if(!v -> right)
    {

    }
    else
    {
        v -> _sz += v -> right -> _sz;
    }
}
string ans = "";
void go_to1(node *v, int i, int j)
{
    if(i == j)
    {
        return;
    }
    if(!v -> right || v -> right -> _sz < pow(2, j - i - 1))
    {
        if(!v -> right)
        {
            v -> right = new node();
        }
        ans += "0";
        go_to1(v -> right, i + 1, j);
    }
    else
    {
        if(!v -> left)
        {
            v -> left = new node();
        }
        ans += "1";
        go_to1(v -> left, i + 1, j);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        cin >> s;
        ans = "";
        tree = new node();
        vector <int> dp(n);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                dp[i] = 0;
            }
            else if(i == 0)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
        int p = min(k, (int)log2(n - k + 1) + 1);
        int p1 = k - p;
        bool fl = 1;
        if(p1 == 0)
        {
            for(int i = 0; i < n - k + 1; i++)
            {
                go_to(tree, i, i + k);
            }
            if(tree -> _sz == pow(2, k))
            {
                fl = 0;
            }
        }
        else
        {
            for(int i = k - p; i < n - p + 1; i++)
            {
                if(dp[i - 1] < p1)
                {
                    continue;
                }
                go_to(tree, i, i + p);
            }
        }
        if(!fl)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < p1; i++)
        {
            ans += "0";
        }
        go_to1(tree, p1, k);
        cout << ans << "\n";
    }
    return 0;
}