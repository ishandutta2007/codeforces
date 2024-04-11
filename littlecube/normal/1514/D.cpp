/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, arr[300005];

struct segTree1
{
    int L, R;
    pii val;
    segTree1 *left, *right;
    segTree1(int L, int R, pii val, segTree1 *l, segTree1 *r) : L(L), R(R), val(val), left(l), right(r){};
};

segTree1 *build1(int L, int R)
{
    pii val = {0, 0};
    for (int i = L; i <= R; i++)
        if (val.S == 0)
            val = {arr[i], 1};
        else if (val.F == arr[i])
            val.S++;
        else
            val.S--;
    if (L == R)
        return new segTree1(L, R, val, nullptr, nullptr);
    else
    {
        int mid = (L + R) / 2;
        return new segTree1(L, R, val, build1(L, mid), build1(mid + 1, R));
    }
}

pii query1(segTree1 *root, int L, int R)
{
    if (L <= root->L && root->R <= R)
        return root->val;
    else if (R < root->L || root->R < L)
        return pii{1, 0};
    else
    {
        pii resl = query1(root->left, L, R), resr = query1(root->right, L, R);
        if (resl.F == resr.F)
            return pii{resl.F, resl.S + resr.S};
        return (resl.S > resr.S ? pii{resl.F, resl.S - resr.S} : pii{resr.F, resr.S - resl.S});
    }
}

struct segTree2
{
    int L, R;
    int val;
    segTree2 *left, *right;
    segTree2(int L, int R, segTree2 *l, segTree2 *r) : L(L), R(R), val(0), left(l), right(r){};
};

void modify2(segTree2 *root, int pos)
{
    if (root->L == pos && root->R == pos)
        root->val++;
    else
    {
        int mid = (root->L + root->R) / 2;
        if (pos <= mid)
        {
            if (root->left == nullptr)
                root->left = new segTree2(root->L, mid, nullptr, nullptr);
            modify2(root->left, pos);
        }
        else
        {
            if (root->right == nullptr)
                root->right = new segTree2(mid + 1, root->R, nullptr, nullptr);
            modify2(root->right, pos);
        }
        root->val = (root->left == nullptr ? 0 : root->left->val) + (root->right == nullptr ? 0 : root->right->val);
    }
}
int query2(segTree2 *root, int L, int R)
{
    if (L <= root->L && root->R <= R)
        return root->val;
    else if (R < root->L || root->R < L)
        return 0;
    else
        return (root->left == nullptr ? 0 : query2(root->left, L, R)) + (root->right == nullptr ? 0 : query2(root->right, L, R));
}

segTree1 *battle;
segTree2 *number[300005];
signed main()
{
    fast;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        number[i] = new segTree2(1, n, nullptr, nullptr);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        modify2(number[arr[i]], i);
    }
    battle = build1(1, n);
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        pii ans;
        cin >> l >> r;
        ans = query1(battle, l, r);
        //cout << "cnt is " << query2(number[ans.F], l, r) << '\n';
        cout << max(1LL, 2 * query2(number[ans.F], l, r) - (r - l + 1)) << '\n';
    }
}
// cnt -> len - len * 2 + cnt * 2