#include <bits/stdc++.h>
using namespace std;

#define double long double
const double eps = 1e-9;
const double eps1 = 1e-9;
vector <vector <double> > a;
vector <pair <double, double> > coor1, coor2;
bool cmp(int i, int j)
{
	return coor1[i].first < coor1[j].first;
}
bool cmp1(int i, int j)
{
	return coor2[i].first < coor2[j].first;
}
struct node{
	node* left;
	node* right;
	int priority;
	int ind;
	int leftind,rightind;
	node(int ind, int priority):
		ind(ind),
		priority(priority),
		leftind(ind),
		rightind(ind),
		left(0),
		right(0){};
};
bool flag;
bool check(pair <double, double> x1, pair <double, double> x2, pair <double, double> x3, pair <double, double> x4)
{
	double A1 = x2.second - x1.second;
	double B1 = x1.first - x2.first;
	double C1 = -x1.first * A1 - x1.second * B1;
	double A2 = x4.second - x3.second;
	double B2 = x3.first - x4.first;
	double C2 = -x3.first * A2 - x3.second * B2;
	if(fabs(A1 * B2 - A2 * B1) <= 1e-6)
	{
		if(fabs(A1 * C2 - A2 * C1) > 1e-6 || fabs(B1 * C2 - B2 * C1) > 1e-6)
		{
			return false;
		}
		if(x1.first >= x3.first && x1.second >= min(x3.second, x4.second) && x1.first <= x4.first && x1.second <= max(x3.second, x4.second))
		{
			return true;
		}
		if(x2.first >= x3.first && x2.second >= min(x4.second, x3.second) && x2.first <= x4.first && x2.second <= max(x4.second, x3.second))
		{
			return true;
		}
		if(x3.first >= x1.first && x3.second >= min(x2.second, x1.second) && x3.first <= x2.first && x3.second <= max(x1.second, x2.second))
		{
			return true;
		}
		if(x4.first >= x1.first && x4.second >= min(x2.second, x1.second) && x4.first <= x2.first && x4.second <= max(x1.second, x2.second))
		{
			return true;
		}
		return false;
	}
	
	double f1 = A1 * B2 - A2 * B1;
	double f2 = B1 * C2 - B2 * C1;
	double f3 = A1 * C2 - A2 * C1;
	double y = -f3 / f1;
	double x = f2 / f1;
	if(x + eps < min(x1.first, x2.first) || x - eps > max(x1.first, x2.first))
	{
		return 0;
	}
	if(y + eps < min(x1.second, x2.second) || y - eps > max(x1.second, x2.second))
	{
		return 0;
	}
	if(x + eps < min(x3.first, x4.first) || x - eps > max(x3.first, x4.first)){
		return 0;
	}
	if(y + eps < min(x3.second, x4.second) || y - eps > max(x3.second, x4.second)){
		return 0;
	}
	return 1;
}
void upd(node* &v)
{
	v -> leftind = v -> ind;
	v -> rightind = v -> ind;
	if(!v -> left)
	{
		
	}
	else
	{
		v -> leftind = v -> left -> leftind;
	}
	if(!v -> right){
		
	}
	else
	{
		v -> rightind = v -> right -> rightind;
	}
}
bool fl = false;
void split(node* v, node* &l, node* &r, double x, double y)
{
	if(!v)
	{
		l = r = NULL;
		return;
	}
	double y1 = coor1[v -> ind].second + (x - coor1[v -> ind].first) / (coor2[v -> ind].first - coor1[v -> ind].first) * (coor2[v -> ind].second - coor1[v -> ind].second);
	if(fabs(y - y1) <= eps1)
	{fl = true;
		l = v -> left;
		r = v -> right;
	}
	else if(y1 < y)
	{
		split(v -> right, v -> right, r, x, y);
		l = v;
		upd(l);
	}
	else
	{
		split(v -> left, l, v -> left, x, y);
		r = v;
		upd(r);
	}
}
void merge(node* &v, node* l, node* r){
	if(!l && !r){
		v = NULL;
		return;
	}
	if(!l)
	{
		v = r;
		upd(v);
		return;
	}
	else if(!r)
	{
		v = l;
		upd(v);
		return;
	}
	if(l -> priority > r -> priority)
	{
		merge(l -> right, l -> right, r);
		v = l;
	}
	else
	{
		merge(r -> left, l, r -> left);
		v = r;
	}
	upd(v);
}
void add(node* &tree, int ind){
	double x = coor1[ind].first;
	double y = coor1[ind].second;
	node* L;
	node* R;
	fl = false;
	split(tree, L, R, x, y);
	if(fl){
		flag = true;
	}
	if(!L)
	{
		
	}
	else
	{
		int ind1 = L -> rightind;
		if(check(coor1[ind1], coor2[ind1], coor1[ind], coor2[ind]))
		{
			flag = true;
		}
	}
	if(!R)
	{
		
	}
	else
	{
		int ind1 = R -> leftind;
		if(check(coor1[ind], coor2[ind], coor1[ind1], coor2[ind1]))
		{
			flag = true;
		}
	}
	merge(L, L, new node(ind, rand()));
	merge(tree, L, R);
}
void del(node* &tree, int ind)
{
	double x = coor2[ind].first;
	double y = coor2[ind].second;
	node* L;
	node* R;
	split(tree, L, R, x, y);
	if(!L || !R)
	{
		
	}
	else
	{
		int ind1 = L -> rightind;
		int ind2 = R -> leftind;
		if(check(coor1[ind1], coor2[ind1], coor1[ind2], coor2[ind2]))
		{
			flag = true;
		}
	}
	merge(tree, L, R);
}
signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	a.resize(n, vector <double> (5));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cin >> a[i][j];
		}
		double t = sqrt(a[i][2] * a[i][2] + a[i][3] * a[i][3]);
		a[i][2] = a[i][2] * a[i][4] / t;
		a[i][3] = a[i][3] * a[i][4] / t;
	}
	coor1.resize(n);
	coor2.resize(n);
	double l = 0, r = 1e11;
	while(r - l > eps)
	{
		double midd = (r + l) / 2;
		flag = false;
		for(int i = 0; i < n; i++)
		{
			double x, y, x1, y1;
			x = a[i][0];
			y = a[i][1];
			x1 = x + a[i][2] * midd;
			y1 = y + a[i][3] * midd;
			
			if(x1 < x)
			{
				swap(x, x1);
				swap(y, y1);
			}
			if(x == x1 && y > y1)
			{
				swap(y, y1);
			}
			coor1[i] = {x, y};
			coor2[i] = {x1, y1};
		}
		vector <int> p(n), p1(n);
		for(int i = 0; i < n; i++)
		{
			p[i] = i;
			p1[i] = i;
		}
		node* tree;
		tree = NULL;
		sort(p.begin(), p.end(), cmp);
		sort(p1.begin(), p1.end(), cmp1);
		int j = 0;
		for(int i = 0; i < p.size(); i++)
		{
			while(j < p.size() && coor2[p1[j]].first <= coor1[p[i]].first)
			{
				del(tree, p1[j]);
				j++;
			}
			add(tree, p[i]);
		}
		while(j < p.size()){
			del(tree, p1[j]);
			j++;
		}
		if(flag)
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	if(r == 1e11)
	{
		cout << "No show :(";
	}
	else
	{
		cout << fixed << setprecision(10) << r;
	}
    return 0;
}