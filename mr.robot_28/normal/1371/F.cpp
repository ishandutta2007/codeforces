#include<bits/stdc++.h>
 
using namespace std;
struct node{
	node* left;
	node* right;
	int a, priority;
	int val, val1;
	node(int a, int priority, int val):
		val(val),
		val1(val),
		a(a),
		priority(priority),
		left(0),
		right(0){};
};
void upd(node* &v)
{
	v -> val1 = v -> val;
	if(!v -> left)
	{
		
	}
	else
	{
		v -> val1 = max(v -> val1, v -> left -> val1);
	}
	if(!v -> right)
	{
		
	}
	else
	{
		v -> val1 = max(v -> val1, v -> right -> val1);
	}
}
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
		upd(l);
	}
	else
	{
		split(v -> left, l, v -> left, a);
		r = v;
		upd(r);
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
		l -> right = merge(l -> right, r);
		upd(l);
		return l;
	}
	else
	{
		r -> left = merge(l, r -> left);
		upd(r);
		return r;
	}
}
void add(node* &root, int a, int val)
{
	node* L;
	node* R;
	split(root, L, R, a);
	node* v = new node(a, rand(), val);
	L = merge(L, v);
	root = merge(L, R);
}
void erase(node* &root, int a)
{
	node* L;
	node* R;
	node* L1;
	node* R1;
	split(root, L, R, a);
	split(L, L1, R1, a - 1);
	root = merge(L1, R);
}
pair <int, int> go_left(node* v)
{
	if(!v -> left)
	{
		return {v -> a, v -> val};
	}
	return go_left(v -> left);
}
pair <int, int> go_right(node* v)
{
	if(!v -> right)
	{
		return {v -> a, v -> val};
	}
	return go_right(v -> right);
}
void go_right(node* &v, int val)
{
	if(!v)
	{
		return;
	}
	if(!v -> right)
	{
		v ->val = val - v -> a;
		upd(v);
		return;
	}
	go_right(v -> right, val);
	upd(v);
}
int maxans(node* v)
{
	int ns = 0;
	if(!v -> left)
	{
	}
	else
	{
		ns = max(ns, v -> left -> val1);
	}
	if(!v -> right)
	{
		return ns;
	}
	else
	{
		ns = max(ns, v -> val);
	}
	return max(ns, maxans(v -> right));
}
vector <int> tree;
void update(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		tree[v] ^= 1;
	}
	else if(l <= ar && r >= al)
	{
		update(v * 2, l, (r + l) / 2, al, ar);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
}
int ans(int v, int l, int r, int ind)
{
	if(l == r){
		return tree[v];
	}
	if(ind <= (r + l) / 2)
	{
		return tree[v] ^ ans(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		return tree[v] ^ ans(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
void dfs(node* v)
{
	if(!v)
	{
		return;
	}
	dfs(v -> left);
	cout << v -> a << " ";
	dfs(v -> right); 
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	node* root;
	node* root1;
	tree.resize(4 * n, 0);
	root = root1 = NULL;
	set <int> st ,st1;
	int _sz = 0, _sz1 = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '>' || i == 0)
		{
			if(i != 0 && s[i - 1] == s[i])
			{
				continue;
			}
			if(st.size() != 0)
			{
				add(root, *st.rbegin(), i - *st.rbegin());
			}
			st.insert(i);
		}
		if(s[i] == '<' || i == 0)
		{
			if(i != 0 && s[i - 1] == s[i])
			{
				continue;
			}
			if(st1.size() != 0)
			{
				add(root1, *st1.rbegin(), i - *st1.rbegin());
			}
			st1.insert(i);
		}
	}
	if(st.size() != 0)
	{
		add(root, *st.rbegin(), n - *st.rbegin());
	}
	if(st1.size() != 0)
	{
		add(root1, *st1.rbegin(), n - *st1.rbegin());
	}
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		node* L;
		node* R;
		node* L1;
		node* R1;
		node* L2;
		node* R2;
		node* L3;
		node* R3;
		L = R = L1 = R1 = L2 = R2 = L3 = R3 = NULL;
		split(root, L, R, r);
		split(L, L1, R1, l - 1);
		split(root1, L2, R2, r);
		split(L2, L3, R3, l - 1);
		update(1, 0, n - 1, l, r);
		if(r != n - 1 && (s[r] == s[r + 1]) ^ (ans(1, 0, n - 1, r) ^ ans(1, 0, n - 1, r + 1)) == 1)
		{
			if((s[r] == '>') ^ ans(1, 0, n - 1, r))
			{
				erase(R, r + 1);
			}
			else
			{
				erase(R2, r + 1);
			}
		}
		else if(r != n - 1)
		{
			if((s[r] == '>') ^ ans(1, 0, n - 1, r))
			{
				if(!R2)
				{
					add(R2, r + 1, n - r - 1);
				}
				else
				{
					add(R2, r + 1, go_left(R2).first - r - 1);
				}
			}
			else
			{
				if(!R)
				{
					add(R, r + 1, n - r - 1);
				}
				else
				{
					add(R, r + 1, go_left(R).first - r - 1);
				}
			}
		}
		int l1 = n;
		int l2 = n;
		if(!R)
		{
		}
		else
		{
			l1 = go_left(R).first;
		}
		if(!R2){	
		}
		else
		{
			l2 = go_left(R2).first;
		}
		go_right(R3, l1);
		go_right(R1, l2);
		R1 = merge(R1, R2);
		R3 = merge(R3, R);
		if(l != 0 && (s[l] == s[l - 1]) ^ (ans(1, 0, n - 1, l) ^ ans(1, 0, n - 1, l - 1)) == 1)
		{
			if((s[l - 1] == '>') ^ ans(1, 0, n - 1, l - 1))
			{
				erase(R3, l);
			}
			else
			{
				erase(R1, l);
			}
		}
		else if(l != 0)
		{
			if((s[l - 1] == '>') ^ ans(1, 0, n - 1, l - 1))
			{
				if(!R1)
				{
					add(R1, l, n - l);
				}
				else
				{
					add(R1, l, go_left(R1).first - l);
				}
			}
			else
			{
				if(!R3)
				{
					add(R3, l, n - l);
				}
				else
				{
					add(R3, l, go_left(R3).first - l);
				}
			}
		}
		l1 = n;
		l2 = n;
		if(!R1){
		}
		else
		{
			l1 = go_left(R1).first;
		}
		if(!R3){	
		}
		else
		{
			l2 = go_left(R3).first;
		}
		go_right(L1, l2);
		root = merge(L1, R3);
		go_right(L3, l1);
		root1 = merge(L3, R1);
		split(root, L, R, r);
		split(L, L1, R1, l - 1);
		int res = 0;
		if(!R1)
		{
			res = r - l + 1;
		}
		else
		{
			res = maxans(R1);
			pair <int, int> v1;
			pair <int, int> v2;
			v1 = go_left(R1);
			v2 = go_right(R1);
			res = max(res, v1.first - l);
			res = max(res, r - v2.first + 1);
		}
		cout << res << "\n";
		L = merge(L1, R1);
		root = merge(L, R);
	}
    return 0;
}