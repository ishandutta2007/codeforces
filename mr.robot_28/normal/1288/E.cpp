#include<bits/stdc++.h>
using namespace std;
const int CONST = 1e9 + 7;
vector <int> tree, tree1;
void update(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree[v] += val;
		return;
	}
	else if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (l + r)/ 2, ind, val);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(al <= l && ar >=r)
	{
		return tree[v];
	}
	else if(al <= r && l <= ar)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	else
	{
		return 0;
	}
}
void update1(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree1[v] += val;
		return;
	}
	else if(ind <= (r + l) / 2)
	{
		update1(v * 2, l, (l + r)/ 2, ind, val);
		tree1[v] = tree1[v * 2] + tree1[v * 2 + 1];
	}
	else
	{
		update1(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
		tree1[v] = tree1[v * 2] + tree1[v * 2 + 1];
	}
}
int ans1(int v, int l, int r, int al, int ar)
{
	if(al <= l && ar >= r)
	{
		return tree1[v];
	}
	else if(al <= r && l <= ar)
	{
		return ans1(v * 2, l, (r + l) / 2, al, ar) + ans1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	else
	{
		return 0;
	}
}
signed main()
{
    int n, m;
    cin >> n >> m;
    tree.resize(m * 4);
    vector <int> A(n);
    vector <int> ansmax(n);
    for(int i = 0; i < n; i++)
    {
    	A[i] = i;
    	ansmax[i] =i;
    }
    vector <bool> used(n, false);
    vector <int> B(m);
    for(int i = 0; i < m; i++)
    {
    	int a;
    	cin >> a;
    	a--;
    	used[a] = true;
    	B[i] = a;
    }
    vector <int> ind(n, -1), pred(m, -1), next(m, -1);
    for(int i = m - 1; i >= 0; i--)
    {
    	if(ind[B[i]] != -1)
    	{
    		next[i] = ind[B[i]];
    		pred[ind[B[i]]] = i;
    	}
    	ind[B[i]] = i;
    }
    for(int i = m - 1; i >= 0; i--)
    {
    	if(next[i] != -1)
    	{
    		update(1, 0, m - 1, next[i], -1);
    		if(next[i] > i + 1)
    		{
    			int r = ans(1, 0, m - 1, i + 1, next[i] - 1);
    			ansmax[B[i]] = max(r, ansmax[B[i]]);
    		}
    	}
    	else if(i != m - 1)
    	{
    		int r = ans(1, 0, m - 1, i + 1, m - 1);
    		ansmax[B[i]] = max(r, ansmax[B[i]]);
    	}
    	update(1, 0, m - 1, i, 1);
    }
    tree1.resize(4 * n);
    for(int i = 0; i < m; i++)
    {
    	if(pred[i] == -1)
    	{
    			ansmax[B[i]] = max(ansmax[B[i]], B[i] + ans1(1, 0, n - 1, B[i], n - 1));
    			update1(1, 0, n - 1, B[i], 1);
    	}
    }
    for(int i = 0; i < 4 * n; i++)
    {
    	tree1[i] = 0;
    }
    for(int i = m - 1; i >= 0; i--)
    {
    	if(next[i] == -1)
    	{
    		ansmax[B[i]] = max(tree1[1], ansmax[B[i]]);
    		update1(1, 0, n - 1, B[i], 1);
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	if(ans1(1, 0, n - 1, i, i) == 0)
    	{
    		ansmax[i] = i + ans1(1, 0, n - 1, i, n - 1);
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	if(used[i])
    	{
    		cout << 1 << " ";
    	}
    	else
    	{
    		cout << i + 1 << " ";
    	}
    	cout << ansmax[i] + 1 << "\n";
    }
    return 0;
}