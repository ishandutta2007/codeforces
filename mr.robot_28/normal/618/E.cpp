#include<bits/stdc++.h>

using namespace std;
#define double long double
const double pi = acos(-1);
int n, m;
vector <vector <vector <double> > > Tree2;
vector <pair <double, double> > Tree1;
vector <vector <double> > upd(2, vector <double> (2));
vector <vector <double> > upd1(2, vector <double> (2));
void push(int v)
{
	double x = Tree1[v * 2].first;
	double y = Tree1[v * 2].second;
	double x1 = x * Tree2[v][0][0] + y * Tree2[v][0][1];
	double y1 = x * Tree2[v][1][0] + y * Tree2[v][1][1];
	upd[0][0] = Tree2[v][0][0] * Tree2[v  *2][0][0] + Tree2[v][0][1] * Tree2[v * 2][1][0];
	upd[0][1] = Tree2[v][0][0] * Tree2[v * 2][0][1] + Tree2[v][0][1] * Tree2[v * 2][1][1];
	upd[1][0] = Tree2[v][1][0] * Tree2[v * 2][0][0] + Tree2[v][1][1] * Tree2[v * 2][1][0];
	upd[1][1] = Tree2[v][1][0] * Tree2[v * 2][0][1] + Tree2[v][1][1] * Tree2[v * 2][1][1];
	Tree2[v * 2] = upd;
	Tree1[v * 2] = {x1 + Tree1[v].first, y1 + Tree1[v].second};
	x = Tree1[v * 2 + 1].first;
	y = Tree1[v * 2 + 1].second;
	x1 = x * Tree2[v][0][0] + y * Tree2[v][0][1];
	y1 = x * Tree2[v][1][0] + y * Tree2[v][1][1];
	upd[0][0] = Tree2[v][0][0] * Tree2[v * 2 + 1][0][0] + Tree2[v][0][1] * Tree2[v * 2 + 1][1][0];
	upd[0][1] = Tree2[v][0][0] * Tree2[v * 2 + 1][0][1] + Tree2[v][0][1] * Tree2[v * 2 + 1][1][1];
	upd[1][0] = Tree2[v][1][0] * Tree2[v * 2 + 1][0][0] + Tree2[v][1][1] * Tree2[v * 2 + 1][1][0];
	upd[1][1] = Tree2[v][1][0] * Tree2[v * 2 + 1][0][1] + Tree2[v][1][1] * Tree2[v * 2 + 1][1][1];
	Tree2[v * 2 + 1] = upd;
	Tree1[v * 2 + 1] = {x1 + Tree1[v].first, y1 + Tree1[v].second};
	Tree1[v] = {0, 0};
	Tree2[v][0][0] = 1;
	Tree2[v][1][1] = 1;
	Tree2[v][0][1] = 0;
	Tree2[v][1][0] = 0;
}
void update(int v, int l, int r, int al, int ar, double f)
{
	if(l >= al && r <= ar)
	{
		double x = Tree1[v].first;
		double y = Tree1[v].second;
		double x1 = x * cos(f) - y * sin(f);
		double y1 = x * sin(f) + y * cos(f);
		upd1[0][0] = cos(f);
		upd1[0][1] = -sin(f);
		upd1[1][0] = sin(f);
		upd1[1][1] = cos(f);
		upd[0][0] = Tree2[v][0][0] * upd1[0][0] + Tree2[v][0][1] * upd1[1][0];
		upd[0][1] = Tree2[v][0][0] * upd1[0][1] + Tree2[v][0][1] * upd1[1][1];
		upd[1][0] = Tree2[v][1][0] * upd1[0][0] + Tree2[v][1][1] * upd1[1][0];
		upd[1][1] = Tree2[v][1][0] * upd1[0][1] + Tree2[v][1][1] * upd1[1][1];
		Tree2[v] = upd;
		Tree1[v] = {x1, y1};
	}
	else if(l <= ar && r >= al)
	{
		push(v);
		update(v * 2, l, (r + l) / 2, al, ar, f);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, f);
	}
}
void update1(int v, int l, int r, int al, int ar, double x, double y)
{
	if(l >= al && r <= ar)
	{
		Tree1[v].first += x;
		Tree1[v].second += y;
	}
	else if(l <= ar && r >= al)
	{
		push(v);
		update1(v * 2, l, (r + l) / 2, al, ar, x, y);
		update1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x, y);
	}
}
void ans(int v, int l, int r, int ind, double &x, double &y)
{
	if(l == r)
	{
		x = Tree1[v].first;
		y = Tree1[v].second;
	}
	else 
	{
		push(v);
		if(ind <= (r + l) / 2)
		{
			ans(v * 2, l, (r + l) / 2, ind, x, y);
		}
		else
		{
			ans(v * 2 + 1, (r + l) / 2 + 1, r, ind,  x, y);
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	Tree2.resize(4 * n, vector <vector <double> > (2, vector <double> (2)));
	Tree1.resize(n * 4);
	for(int i = 0; i < n * 4; i++){
		Tree2[i][0][0] = 1;
		Tree2[i][0][1] = 0;
		Tree2[i][1][0] = 0;
		Tree2[i][1][1] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		update1(1, 0, n - 1, i, i, i + 1, 0);
	}
	for(int i = 0; i < m; i++)
	{
		int type;
		cin >> type;
		int x;
		double z;
		cin >> x >> z;
		if(type == 1)
		{
			double x1, y1, x2, y2;
			if(x == 1)
			{
				x1 = 0;
				y1 = 0;
			}
			else
			{
				ans(1, 0, n - 1, x - 2, x1, y1);
			}
			ans(1, 0, n - 1, x - 1, x2, y2);
			double dx, dy;
			double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			dx = (x2 - x1) * (z) / dist; 
			dy = (y2 - y1) * z / dist;
			update1(1, 0, n - 1, x - 1, n - 1, dx, dy);
		}
		else
		{
			double x1, y1;
			if(x == 1)
			{
				x1 = 0;
				y1 = 0;
			}
			else
			{
				ans(1, 0, n - 1, x - 2, x1, y1);
			}
			z = - z / 360 * 2 * pi;
			update1(1, 0, n - 1, x - 1, n - 1, -x1, -y1);
			update(1, 0, n - 1, x - 1, n - 1, z);
			update1(1, 0, n - 1, x - 1, n - 1, x1, y1);
		}
		double x1, y1;
		ans(1, 0, n - 1, n - 1, x1, y1);
		cout << fixed << setprecision(8) << x1 << " " << y1 <<"\n";
	}
	return 0;
}