#include<bits/stdc++.h>
using namespace std;
int n;
vector <long long> tr, tree, upd, a;
void update1(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tr[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		update1(v * 2, l, (r + l) / 2, al, ar, val);
		update1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
long long ans(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return tr[v];
	}
	if(ind <= (r + l) / 2)
	{
		return tr[v] + ans(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		return tr[v] + ans(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
struct node{
	node* left;
	node* right;
	int a, priority;
	node(int a, int priority):
		a(a),
		left(0),
		right(0),
		priority(priority){};
};
void split(node* v, node* &l, node* &r, int a)
{
	if(!v)
	{
		l = r = NULL;
		return;
	}
	if(v -> a <= a)
	{
		split(v -> right, v -> right, r, a);
		l = v;
	}
	else
	{
		split(v -> left, l, v -> left, a);
		r = v;
	}
}
node* merge(node* l, node* r)
{
	if(!l)
	{
		return r;
	}
	else if(!r)
	{
		return l;
	}
	if(l -> priority > r -> priority)
	{
		l -> right =merge(l -> right, r);
		return l;
	}
	else
	{
		r -> left = merge(l, r -> left);
		return r;
	}
}
void add(node* &root, int a)
{
	node* L;
	node* R;
	split(root, L, R, a);
	node* v = new node(a, rand());
	L = merge(L, v);
	root = merge(L, R);
}
void erase(node* &root, int a)
{
	node* L;
	node* R;
	split(root, L, R, a);
	node* L1;
	node* R1;
	split(L, L1, R1, a - 1);
	root = merge(L1, R);
}
int go_left(node* v, int a)
{
	if(!v)
	{
		return -1;
	}
	if(v -> a < a)
	{
		int val = go_left(v -> right, a);
		return val;
	}
	int val = go_left(v -> left, a);
	if(val == -1)
	{
		return v -> a;
	}
	return val;
}
int go_left(node* v)
{
	if(!v -> left)
	{
		return v -> a;
	}
	return go_left(v -> left);
}
int go_right(node* v)
{
	if(!v -> right)
	{
		return v -> a;
	}
	return go_right(v -> right);
}
int go_right(node* v, int a)
{
	if(!v)
	{
		return -1;
	}
	if(v -> a > a)
	{
		int val = go_right(v -> left, a);
		return val;
	}
	int val = go_right(v -> right, a);
	if(val == -1)
	{
		return v -> a;
	}
	return val;
}
node* s1;
node* s2;
void push(int v, int l, int r)
{
	tree[v * 2] += upd[v];
	tree[v * 2 + 1] += upd[v];
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0; 
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tree[v] += val;
		upd[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
}
int maxans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		return max(maxans(v * 2, l, (r + l) / 2, al, ar), maxans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	return 0;
}
void er(int ind, int d)
{
	if(ind == 0)
	{
		return;
	}
	long long val = ans(1, 0, n - 1, ind) + a[ind];
	long long val1 = ans(1, 0, n - 1, ind - 1) + a[ind - 1];
	if(val1 < val || val1 >= val + d)
	{
		return;
	}
	erase(s1, ind);
	int a = go_right(s1, ind);
	int b = go_left(s1, ind);
	if(a == -1 && b == -1)
	{
		update(1, 0, n - 1, ind, n - 1, ind);
	}
	else if(b == -1)
	{
		update(1, 0, n - 1, ind, n - 1, ind - a);
	}
	else if(a == -1)
	{
		update(1, 0, n - 1, ind, b - 1, ind);
	}
	else
	{
		update(1, 0, n - 1, ind, b - 1, ind - a);
	}
}
void er1(int ind, int d)
{
	if(ind == n - 1)
	{
		return;
	}
	
	long long val = a[ind] + ans(1, 0, n - 1, ind);
	long long val1 = a[ind + 1] + ans(1, 0, n - 1, ind + 1);
	if(val1 < val || val1 >= val + d)
	{
		return;
	}
	erase(s2, ind);
	int a = go_right(s2, ind);
	int b = go_left(s2, ind);
	if(a == -1 && b == -1)
	{
		update(1, 0, n - 1, 0, ind, -(ind + 1));
	}
	else if(b == -1)
	{
		update(1, 0, n - 1, a + 1, ind, -(ind + 1));
	}
	else if(a == -1)
	{
		update(1, 0, n - 1, 0, ind, b - ind);
	}
	else
	{
		update(1, 0, n - 1, a + 1, ind, b - ind);
	}
}
void ad(int ind, int d)
{
	if(ind == 0)
	{
		return;
	}
	long long val = ans(1, 0, n - 1, ind) + a[ind];
	long long val1 = ans(1, 0, n - 1, ind - 1) + a[ind - 1];
	if(val1 >= val || val1 + d < val)
	{
		return;
	}
   	int a = go_right(s1, ind);
   	int b = go_left(s1, ind);	
   	if(a == -1 && b == -1)
   	{
   		update(1, 0, n - 1, ind, n - 1, -ind);
   	}
   	else if(b == -1)
   	{
   		update(1, 0, n - 1, ind, n - 1, -ind + a);
   	}
   	else if(a == -1)
   	{
   		update(1, 0, n - 1, ind, b - 1, -ind);
   	}
   	else
   	{
   		update(1, 0, n - 1, ind, b - 1, -ind + a);
   	}
   	add(s1, ind);
}
void ad1(int ind, int d)
{
	if(ind == n - 1)
	{
		return;
	}
	long long val = a[ind] + ans(1, 0, n - 1, ind);
	long long val1 = a[ind + 1] + ans(1, 0, n - 1, ind + 1);
	if(val1 >= val || val1 + d < val)
	{
		return;
	}
   	int a = go_right(s2, ind);
   	int b = go_left(s2, ind);
	if(a == -1 && b == -1)
	{
		update(1, 0, n - 1, 0, ind, (ind + 1));
	}
	else if(b == -1)
	{
		update(1, 0, n - 1, a + 1, ind, (ind + 1));
	}
	else if(a == -1)
	{
		update(1, 0, n - 1, 0, ind, -b + ind);
	}
	else
	{
		update(1, 0, n - 1, a + 1, ind, -b + ind);
	}
	add(s2, ind);
}
signed main() {
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    a.resize(n);
    tree.resize(4 * n, 0);
    upd.resize(4 * n, 0);
    tr.resize(4 * n, 0);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    int m;
    cin >> m;
    if(n == 1)
    {
    	for(int i = 0; i < m; i++)
    	{
    		int l, r, d;
    		cin >> l >> r >> d;
    		cout << 1 << "\n";
    	}
    	return 0;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
    	if((i == n - 1 || a[i + 1] >= a[i]))
    	{
    		if(cnt == 0)
    		{
    			update(1, 0, n - 1, 0, i, i + 1);
    		}
    		else
    		{
    			update(1, 0, n - 1, go_right(s2) + 1, i, i + 1);
    		}
    		cnt++;
    		add(s2, i);
    	}
    }
    cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
    	if((i == 0 || a[i - 1] >= a[i]))
    	{
    		if(cnt == 0)
    		{
    			update(1, 0, n - 1, i, n - 1, -i);
    		}
    		else
    		{
    			update(1, 0, n - 1, i, go_left(s1) - 1, -i);
    		}
    		cnt++;
    		add(s1, i);
    	}
    }
    for(int i = 0; i < m; i++){
    	int l, r, d;
    	cin >> l >> r >> d;
    	l--;
    	r--;
		er(l, d);
    	er1(r, d);
		if(l - 1 >= 0)
    	{
    		ad1(l - 1, d);
    	}
    	if(r + 1 <= n - 1)
    	{
    		ad(r + 1, d);
    	}
    	update1(1, 0, n - 1, l, r, d); 
    	int ns = tree[1];
    	if(1 > ns)
    	{
    		ns = 1;
    	}
    	cout << ns << "\n";
    }
	return 0;
}