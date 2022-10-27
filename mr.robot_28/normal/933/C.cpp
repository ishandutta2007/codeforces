#include <bits/stdc++.h>
using namespace std;
#define double long double
#define db long double
const double eps = 1e-12;
struct point{
	double x, y;
	point(){}
	point(double x, double y):
		x(x),
		y(y){};
	point operator+(const point &t) const
	{
		return point(x + t.x, y + t.y);
	}
	point operator-(const point &t) const
	{
		return point(x - t.x, y - t.y);
	}
	point operator*(const double &t) const
	{
		return point(x * t, y * t);
	}
	point operator/(const double &t) const
	{
		return point(x / t, y / t);
	}
	bool operator<(const point &t)const
	{
		return fabs(x - t.x) < eps ? y <  t.y : x < t.x;
	}
	bool operator==(const point &t)const
	{
		return fabs(x - t.x) < eps && fabs(y - t.y) < eps;
	}
	double len()const
	{
		return sqrt(x * x + y * y);
	}
	point rot90()const
	{
		return point(-y, x);
	}
};
struct circle
{
    point o;
    double r;
    circle(){}
    circle(point _o,double _r):o(_o),r(_r){}
    friend vector<point> operator & (const circle &c1,const circle &c2)
    {
        double d=(c1.o-c2.o).len();
        if(d>c1.r+c2.r+eps || d<fabs(c1.r-c2.r)-eps)
            return vector<point>();
        double dt=(c1.r*c1.r-c2.r*c2.r)/d,d1=(d+dt)/2;
        point dir=(c2.o-c1.o)/d,pcrs=c1.o+dir*d1;
        dt=sqrt(max(0.0L,c1.r*c1.r-d1*d1)),dir=dir.rot90();
        return vector<point>{pcrs+dir*dt,pcrs-dir*dt};
    }
}p[5];
struct dsu{
	int fa[5];
	void init(int n)
	{
		for(int i = 1; i <= n; i++)
		{
			fa[i] = i;
		}
	}
	int find(int x)
	{
		if(fa[x] == x)
		{
			return x;
		}
		else
		{
			return fa[x] = find(fa[x]);
		}
	}
	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);
		if(a != b)
		{
			fa[a] = b;
		}
	}
} dsu;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
    	cin >> p[i].o.x >> p[i].o.y >> p[i].r;
	}
	vector <point> all;
	dsu.init(n);
	int e = 0;
	for(int i = 1; i <= n; i++)
	{
		vector <point> pat;
		for(int j = 1; j <= n; j++)
		{
			if(i != j)
			{
				vector <point> tmp = p[i] & p[j];
				if(!tmp.empty())
				{
					dsu.merge(i, j);
				}
				for(int k = 0; k < tmp.size(); k++)
				{
					all.push_back(tmp[k]), pat.push_back(tmp[k]);
				}
			}
		}
		sort(pat.begin(), pat.end());
		e += unique(pat.begin(), pat.end()) - pat.begin();
	}
	sort(all.begin(), all.end());
	int v=  unique(all.begin(), all.end()) - all.begin(), c = 0;
	for(int i = 1; i <= n; i++)
	{
		c += (dsu.find(i) == i);
	}
	cout << e - v + 1 + c;
    return 0;
}