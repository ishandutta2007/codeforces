#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	node* left;
	node* right;
	int a, priority;
	int val, val1;
	int upd;
	node(int a, int priority, int val):
		left(0),
		right(0),
		a(a),
		upd(0),
		priority(priority),
		val(val), 
		val1(val){};
};
void updf(node* &v)
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
	v -> val1 += v -> upd;
}
void push(node* &v)
{
	if(!v -> left)
	{
		
	}
	else
	{
		v -> left -> val1 += v -> upd;
		v -> left -> upd += v -> upd;
	}
	if(!v -> right){
		
	}
	else
	{
		v -> right -> val1 += v -> upd;
		v -> right -> upd += v -> upd;
	}
	v -> val += v -> upd;
	v -> upd = 0;
}
void split(node* v, node* &l, node* &r, int a)
{
	if(!v)
	{
		l = r = NULL;
		return;
	}
	push(v);
	if(v -> a <= a)
	{
		split(v -> right, v -> right, r, a);
		l = v;
		updf(l);
	}
	else
	{
		split(v -> left, l, v -> left, a);
		r = v;
		updf(r);
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
	push(l);
	push(r);
	if(l -> priority > r -> priority)
	{
		l -> right = merge(l -> right, r);
		updf(l);
		return l;
	}
	else
	{
		r -> left = merge(l, r -> left);
		updf(r);
		return r;
	}
}
void add(node* &root, node* v)
{
	node* L;
	node* R;
	split(root, L, R, v -> a);
	L = merge(L, v);
	root = merge(L, R);
}
void add1(node* &root, int l)
{
	node* L;
	node* R;
	split(root, L, R, l - 1);
	if(!R)
	{
		
	}
	else
	{
		R -> upd++;
		R -> val1++;
	}
	root = merge(L, R);
}
int answer(node* root, int l)
{
	node* L;
	node* R;
	split(root, L, R, l);
	int ans1 = 0;
	if(!L)
	{
		
	}
	else
	{
		ans1 = L -> val1;
	}
	root = merge(L, R);
	return ans1;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> dp(n, 0);
	vector <pair <pair <int, int>, int> > mass;
	for(int i = 0; i < n; i++)
	{
		int l, r, t;
		cin >> l >> r >> t;
		mass.push_back({{l, r}, t});
	}
	sort(mass.begin(), mass.end());
	node* root1;
	node* root2;
	root1 = NULL;
	root2 = NULL;
	for(int i = 0; i < mass.size(); i++)
	{
		int l = mass[i].first.first;
		int r = mass[i].first.second;
		int type = mass[i].second;
		int ans = 1;
		if(type == 1)
		{
			add1(root1, r);
		}
		else
		{
			add1(root2, r);
		}
		int ns1 = answer(root1, l - 1);
		int ns2 = answer(root2, l - 1);
		int ns3 = answer(root1, r - 1);
		int ns4 = answer(root2, r - 1);
		if(type == 1)
		{
			ans = max(ans, ns2 + 1);
			ans = max(ans, ns3 + 1);
			add(root1, new node(r, rand(), ans));
		}
		else
		{
			ans = max(ans, ns1 + 1);
			ans = max(ans, ns4 + 1);
			add(root2, new node(r, rand(), ans));
		}
	}
	int maxans = 0;
	if(!root1)
	{
		
	}
	else
	{
		maxans =max(maxans, root1 -> val1);
	}
	if(!root2)
	{
		
	}
	else
	{
		maxans = max(maxans, root2 -> val1);
	}
	cout << maxans;
  	return 0;
}