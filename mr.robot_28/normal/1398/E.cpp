#include<bits/stdc++.h>
 
using namespace std;
#define int long long
struct node{
	node* left;
	node* right;
	int val, priority, sum, _sz;
	node(int val, int priority):
		priority(priority),
		val(val),
		sum(val),
		_sz(1),
		left(0),
		right(0){};
};
node* tree = NULL;
int allsz = 0;
void upd(node* &v)
{
	v -> sum = v -> val;
	v -> _sz = 1;
	if(!v -> left)
	{
		
	}
	else
	{
		v -> _sz += v -> left -> _sz;
		v -> sum += v -> left -> sum;
	}
	if(!v -> right)
	{
		
	}
	else
	{
		v -> _sz += v -> right -> _sz;
		v -> sum += v -> right -> sum;
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
void split(node* v, node* &l, node* &r, int kol)
{
	if(!v)
	{
		l = r = NULL;
		return;
	}
	int _sz1 = 0;
	if(!v -> right)
	{
		
	}
	else
	{
		_sz1 = v ->  right -> _sz;
	}
	if(_sz1 >= kol)
	{
		split(v -> right, v -> right, r, kol);
		l = v;
		upd(l);
	}
	else
	{
		split(v -> left, l, v -> left, kol - 1 - _sz1);
		r = v;
		upd(r);
	}
}
void split1(node* v, node* &l, node* &r, int val)
{
	if(!v)
	{
		l = r = NULL;
		return;
	}
	if(v -> val <= val)
	{
		split1(v -> right, v -> right, r, val);
		l = v;
		upd(l);
	}
	else
	{
		split1(v -> left, l, v -> left, val);
		r = v;
		upd(r);
	}
}
void add(node* &v, int val)
{
	if(allsz == 0)
	{
		v = new node(val, rand());
		return;
	}
	node* L;
	node* R;
	split1(v, L, R, val);
	L = merge(L, new node(val, rand()));
	v = merge(L, R);
}
void erase(node* &v, int val)
{
	node* L;
	node* R;
	split1(v, L, R, val);
	node* L1;
	node* R1;
	split(L, L1, R1, 1);
	v = merge(L1, R);
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int cnt1 = 0;
	int a = -1;
	multiset <int> vl;
	while(n--)
	{
		int t, v;
		cin >> t >> v;
		if(v > 0)
		{
			cnt1 += t;
			if(t == 0)
			{
				add(tree, v);
			}
			else if(a == -1)
			{
				a = v;
			}
			else if(v >= a)
			{
				vl.insert(v);
				add(tree, v);
			}
			else
			{
				vl.insert(a);
				add(tree, a);
				a = v;
			}
			allsz++;
		}
		else
		{
			v = -v;
			cnt1 -= t;
			if(t == 1 && cnt1 == 0)
			{
				a = -1;
			}
			else if(t == 1 && v == a)
			{
				a = *vl.begin();
				vl.erase(vl.begin());
				erase(tree, a);
			}
			else if(t == 1)
			{
				vl.erase(vl.lower_bound(v));
				erase(tree, v);
			}
			else{
				erase(tree, v);
			}
			allsz--;
		}
		if(allsz == 0)
		{
			cout << 0 << "\n";
		}
		else if(cnt1 == 0)
		{
			cout << tree -> sum << "\n";
		}
		else
		{
			node* L;
			node* R;
			split(tree, L, R, cnt1);
			int res = a;
			if(!L)
			{
				
			}
			else
			{
				res += L -> sum;
			}
			if(!R)
			{
				
			}
			else
			{
				res += R -> sum * 2;
			}
			cout << res << "\n";
			tree = merge(L, R);
		}
	}
	return 0;
}