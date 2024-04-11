#include<bits/stdc++.h>
using namespace std;
#define double long double
struct node{
	node* left;
	node* right;
	double a;
	int priority;
	int sz;
	double sum;
	node(double a, int priority):
		sz(1),
		a(a),
		priority(priority),
		sum(a),
		left(0),
		right(0){};
};
void upd(node* &v)
{
	v -> sz = 1;
	v -> sum = v -> a;
	if(!v -> left)
	{
		
	}
	else
	{
		v -> sz += v -> left -> sz;
		v -> sum += v -> left -> sum;
	}
	if(!v -> right)
	{
		
	}
	else
	{
		v -> sz += v -> right -> sz;
		v -> sum += v -> right -> sum;
	}
}
void split(node* v, node* &l, node* &r, double a)
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
void split1(node* v, node* &l, node* &r, int sz)
{
	if(!v)
	{
		l = r = NULL;
		return;
	}
	int sz1 = 0;
	if(!v -> right)
	{
		
	}
	else
	{
		sz1 += v -> right -> sz;
	}
	if(sz1 + 1 <= sz)
	{
		split1(v -> left, l, v -> left, sz - (sz1 + 1));
		r = v;
		upd(r);
	}
	else
	{
		split1(v -> right, v -> right, r, sz);
		l = v;
		upd(l);
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
void add(node* &root, double val)
{
	node* L;
	node* R;
	split(root, L, R, val);
	node* v = new node(val, rand());
	L = merge(L, v);
	root = merge(L, R);
}
void erase(node* &root, double val)
{
	node* L;
	node* R;
	split(root, L, R, val);
	node* L1;
	node* R1;
	split1(L, L1, R1, 1);
	root = merge(L1, R);
}
signed main() {
  //  ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    vector <double> p(n), u(n);
    vector <pair <double, int> > mass;
    for(int i = 0; i < n; i++)
    {
    	cin >> p[i];
    }
    for(int i = 0; i < n; i++)
    {
    	cin >> u[i];
    	mass.push_back({u[i], i});
    }
    if(b == 0)
    {
    	sort(p.begin(), p.end());
    	double ans = 0;
    	for(int i = n - 1; i >= n - a; i--)
    	{
    		ans += p[i];
    	}
    	cout << fixed << setprecision(6) << ans;
    	return 0;
    }
    else if(a == 0)
    {
    	sort(u.begin(), u.end());
    	double ans = 0;
    	for(int i = n - 1; i >= n - b; i--)
    	{
    		ans += u[i];
    	}
    	cout << fixed << setprecision(6) << ans;
    	return 0;
    }
    sort(mass.begin(), mass.end());
    reverse(mass.begin(), mass.end());
    double ans = 0;
    node* tree;
    node* tree1;
    vector <double> pref1(n + 1);
    vector <double> pref(n + 1);
    for(int i = 0; i < n; i++)
    {
    	pref[i + 1] += pref[i];
    	pref1[i + 1] += pref1[i];
    	pref[i + 1] += p[mass[i].second]; 
    	pref1[i + 1] += u[mass[i].second];
    }
    for(int i = 0; i < n; i++)
    {
    	if(b > i + 1)
    	{
    		continue;
    	}
    	tree1 = NULL;
    	tree = NULL;
    	vector <pair <double, int> > mass1;
    	for(int j = 0; j <= i; j++)
    	{
    		add(tree1, u[mass[j].second] - p[mass[j].second]);
    		mass1.push_back({(1 - p[mass[j].second]) * u[mass[j].second], mass[j].second});
    	}
    	for(int j = i + 1; j < n; j++)
    	{
    		add(tree, p[mass[j].second]);
    	}
    	sort(mass1.begin(), mass1.end());
    	reverse(mass1.begin(), mass1.end());
    	double sum = 0;
    	for(int j = 0; j < mass1.size(); j++)
    	{
    		pref[j + 1] = pref1[j + 1] = 0;
    		pref[j + 1] += pref[j];
    	pref1[j + 1] += pref1[j];
    	pref[j + 1] += p[mass1[j].second]; 
    	pref1[j + 1] += u[mass1[j].second];
    	}
    	if(a + b >= i + 1 && a - ((i + 1) - b) <= n - (i + 1))
    	{
    		node* L;
    		node* R;
    		split1(tree1, L, R, b);
    		sum += R -> sum;
    		sum += pref[i + 1];
    		tree1 = merge(L, R);
    		node* L1;
    		node* R1;
    		split1(tree, L1, R1, a - ((i + 1) - b));
    		if(!R1)
    		{
    		}
    		else
    		{
    		sum += R1 -> sum;
    		}tree = merge(L1, R1);
    		ans = max(ans, sum);
    	}
    	for(int j = 0; j < mass1.size(); j++)
    	{
    		if(b < j + 1)
    		{
    			continue;
    		}
    		sum = 0;
    		add(tree, p[mass1[j].second] * (1 - u[mass1[j].second]));
    		erase(tree1, u[mass1[j].second] - p[mass1[j].second]);
    		int b2 = b - (j + 1);
    		int len = (i + 1) - (j + 1);
    		if(b2 > len)
    		{
    			continue;
    		}
    		int a2 = len - b2;
    		if(a2 > a)
    		{
    			continue;
    		}
    		sum += pref[i + 1];
    		sum -= pref[j + 1];
    		sum += pref1[j + 1];
    		node* L;
    		node* R;
    		node* L1;
    		node* R1;
    		split1(tree1, L, R, b2);
    		if(!R)
    		{
    		}
    		else
    		{
    		sum += R -> sum;
    		}
			tree1 = merge(L, R);
    		split1(tree, L1, R1, a - a2);
    		if(!R1)
    		{
    		}
    		else
    		{
    			sum += R1 -> sum;
    		}
    		tree = merge(L1, R1);
    		ans = max(ans, sum);
    	}
    }
    cout << fixed << setprecision(10) << ans;
	return 0;
}