#include<bits/stdc++.h>
using namespace std;
struct node{
	int a, priority;
	long long sum;
	node* left;
	node* right;
	int val;
	node(int a, int val, int priority):
		priority(priority),
		left(0),
		right(0),
		a(a),
		val(val),
		sum(val){};
};
vector <int> left1, right1;
void upd(node* &v)
{
	v -> sum = v -> val;
	if(!v -> left)
	{
		
	}
	else
	{
		v -> sum += v -> left -> sum;
	}
	if(!v -> right)
	{
		
	}
	else
	{
		v -> sum += v -> right -> sum;
	}
}
vector <node*> tree1;
long long sumleft(node* v, int a)
{
	if(!v){
		return 0;
	}
	int leftsum = 0;
	if(!v -> left)
	{
		
	}
	else{
		leftsum += v -> left -> sum;
	}
	leftsum += v -> val;
	if(v -> a < a)
	{
		return leftsum + sumleft(v -> right, a);
	}
	return sumleft(v -> left, a);
}
long long sumright(node* v, int a)
{
	if(!v)
	{
		return 0;
	}
	int rightsum = 0;
	if(!v -> right)
	{
		
	}
	else
	{
		rightsum = v -> right -> sum;
	}
	rightsum += v -> val;
	if(v -> a > a)
	{
		return rightsum + sumright(v -> left, a);
	}
	return sumright(v -> right, a);
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
void erase(node* &v, int a)
{
	node* L;
	node* R;
	split(v, L, R, a);
	node* L1;
	node* R1;
	split(L, L1, R1 ,a - 1);
	v = merge(L1, R);
}
void add(node* &v, int a, int val)
{
	node* L;
	node* R;
	split(v, L, R, a);
	node* v1 = new node(a, val, rand());
	L = merge(L, v1);
	v = merge(L, R);
}
void errupdate1(int v, int l, int r, int ind)
{
	erase(tree1[v], left1[ind]);
	if(l == r)
	{
		return;
	}
	if(ind <= (r + l) / 2)
	{
		errupdate1(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		errupdate1(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
void addupdate1(int v, int l, int r, int ind, int val, int val1)
{
	add(tree1[v], val, val1);
	if(l == r)
	{
		left1[ind] = val;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		addupdate1(v * 2, l, (r + l) / 2, ind, val, val1);
	}
	else
	{
		addupdate1(v * 2 + 1, (r + l) / 2 + 1, r, ind, val, val1);
	}
}
long long sum1(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return sumright(tree1[v], al - 1);
	}
	else if(l <= ar && r >= al)
	{
		return sum1(v * 2, l, (r + l) / 2, al, ar) +  sum1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	return 0;
}
void update3(int v, int l, int r, int ind, int val, int val1)
{
	add(tree1[v], val, val1);
	if(l == r)
	{
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update3(v * 2, l, (r + l) / 2, ind, val, val1);
	}
	else
	{
		update3(v * 2 + 1, (r + l) / 2 + 1, r, ind, val, val1);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	tree1.resize(4 * n);
	left1.resize(n);
	right1.resize(n);
	vector <set<int> > sets1(n);
	vector <set <int> > sets2(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		sets1[a[i]].insert(i);
		sets2[a[i]].insert(-i);
	}
	for(int i = 0; i < n; i++)
	{
		set <int> :: iterator it;
		it = sets2[a[i]].upper_bound(-i);
		if(it == sets2[a[i]].end())
		{
			left1[i] = -1 - a[i];
		}
		else
		{
			left1[i] = -*it;
		}
		it = sets1[a[i]].upper_bound(i);
		if(it == sets1[a[i]].end())
		{
			right1[i] = n + a[i];
		}
		else
		{
			right1[i] = *it;
		}
	}
	for(int i = 0; i < n; i++){
		update3(1, 0, n - 1, i, left1[i], i - left1[i]);
	}
	while(m--)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			int p, x;
			cin >> p >> x;
			p--;
			x--;
			if(a[p] == x)
			{
				continue;
			}
			set <int> :: iterator it;
			it = sets1[a[p]].upper_bound(p);
			set <int> :: iterator it1;
			it1 = sets2[a[p]].upper_bound(-p);
			int st = a[p];
			int  l = -a[p] - 1, r = n + a[p];
			if(sets1[a[p]].size() != 0 && it != sets1[a[p]].end())
			{
				r = *it;
			}
			if(sets2[a[p]].size() != 0 && it1 != sets2[a[p]].end())
			{
				l = -*it1;
			}
			if(sets1[a[p]].size() != 0 && it != sets1[a[p]].end())
			{
				errupdate1(1, 0, n - 1, *it);
			}
			it = sets1[x].upper_bound(p);
			it1 = sets2[x].upper_bound(-p);
			sets1[a[p]].erase(p);
			sets2[a[p]].erase(-p);
			a[p] = x;
			l = -a[p] - 1, r = n + a[p];
			if(sets1[a[p]].size() != 0 && it != sets1[a[p]].end())
			{
				r = *it;
				errupdate1(1, 0, n - 1, *it);
			}
			if(sets2[a[p]].size() != 0 && it1 != sets2[a[p]].end())
			{
				l = -*it1;
			}
			errupdate1(1, 0, n - 1, p);
			addupdate1(1, 0, n - 1, p, l, p - l);
			if(sets1[a[p]].size() != 0 && it != sets1[a[p]].end())
			{
				r = *it;
				addupdate1(1, 0, n - 1, *it, p, *it - p);
			}
			if(sets2[a[p]].size() != 0 && it1 != sets2[a[p]].end())
			{
				l = -*it1;
			}
			it = sets1[st].upper_bound(p);
			it1 = sets2[st].upper_bound(-p);
			l = -st - 1, r = n + st;
			if(sets1[st].size() != 0 && it != sets1[st].end())
			{
				r = *it;
			}
			if(sets2[st].size() != 0 && it1 != sets2[st].end())
			{
				l = -*it1;
			}
			if(sets1[st].size() != 0 && it != sets1[st].end())
			{
				addupdate1(1, 0, n - 1, *it, l, *it - l);
			}
			sets1[x].insert(p);
			sets2[x].insert(-p);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << sum1(1, 0, n - 1, l, r) << "\n";
		}
	}
    return 0;
}