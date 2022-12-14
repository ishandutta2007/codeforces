#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
template<class T> void _W(const T &x) { cout << x; }
template<class T> void _W(T &x) { cout << x; }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.first); putchar(' '); _W(x.second);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) cout<<' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout<<", "; W(tail...); }
#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define all(a) a.begin(),a.end()
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define toset(a) (sort(all(a)), a.erase(unique(all(a)), a.end()), a.size())
using pii = pair<int,int>;
const int N = 1e6+10;
#define x first
#define y second
#define PDD pdd
#define Point pdd
typedef pair<double, double> PDD;
const double eps = 1e-12, INF = 1e20;
const double PI = acos(-1);

int n;
PDD q[N];
PDD ans[N];
double min_area = INF;
int stk[N], top;
bool used[N];

int sign(double x)
{
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

int dcmp(double x, double y)
{
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

PDD operator+ (PDD a, PDD b)
{
    return {a.x + b.x, a.y + b.y};
}

PDD operator- (PDD a, PDD b)
{
    return {a.x - b.x, a.y - b.y};
}

PDD operator* (PDD a, double t)
{
    return {a.x * t, a.y * t};
}

PDD operator/ (PDD a, double t)
{
    return {a.x / t, a.y / t};
}

double operator* (PDD a, PDD b)
{
    return a.x * b.y - a.y * b.x;
}

double operator& (PDD a, PDD b)
{
    return a.x * b.x + a.y * b.y;
}

double area(PDD a, PDD b, PDD c)
{
    return (b - a) * (c - a);
}

double get_len(PDD a)
{
    return sqrt(a & a);
}

double project(PDD a, PDD b, PDD c)
{
    return ((b - a) & (c - a)) / get_len(b - a);
}

PDD norm(PDD a)
{
    return a / get_len(a);
}

PDD rotate(PDD a, double b)
{
    return {a.x * cos(b) + a.y * sin(b), -a.x * sin(b) + a.y * cos(b)};
}

double cross(pdd a,pdd b){
    return a * b;
}

void get_convex()
{
    sort(q, q + n);
    for (int i = 0; i < n; i ++ )
    {
        while (top >= 2 && sign(area(q[stk[top - 2]], q[stk[top - 1]], q[i])) >= 0)
            used[stk[ -- top]] = false;
        stk[top ++ ] = i;
        used[i] = true;
    }
    used[0] = false;
    for (int i = n - 1; i >= 0; i -- )
    {
        if (used[i]) continue;
        while (top >= 2 && sign(area(q[stk[top - 2]], q[stk[top - 1]], q[i])) >= 0)
            top -- ;
        stk[top ++ ] = i;
    }
    reverse(stk, stk + top);
    top -- ;
}

bool line_segment_intersection(pdd a, pdd b, pdd c, pdd d)
{
    //
    if(cross(a-c,b-c)*cross(a-d,b-d) < eps)return true;
    return false;
}

Point get_line_intersection(Point p, pdd v, Point q, pdd w)
{
    pdd u = p - q;
    double t = cross(w, u) / cross(v, w);
    return p + v * t;
}

pdd pp, yuan;

void solve()
{
	yuan.x = yuan.y = 0;
    cin>>n>>pp.x>>pp.y;
    double ans = 1e18;
    for(int i=0;i<n;i++)cin>>q[i].x>>q[i].y;
    if(n==1) //  
    {
		printf("%.15f",max(pp.x/q[0].x,pp.y/q[0].y));
		return;
	}
	
    get_convex();  
    
    if(top<3) //  
    { 
    	pdd d = {q[0].first,q[0].second};
    	pdd e = {q[n-1].first,q[n-1].second};  //  
    	if(line_segment_intersection(pp, yuan, d, e))
		{
            pdd o = get_line_intersection(yuan, pp - yuan, d, e - d);
            ans = min(ans, pp.x / o.x);
        }
	    for(int i=0;i<n;i++) ans = min(ans,max(pp.x/q[i].x,pp.y/q[i].y));
	    printf("%.15f\n", ans);
	    return;
	}
	
	//  
	for(int i=0;i<top;i++)
	{
        auto d = q[stk[i]], e = q[stk[i + 1]];
        if(line_segment_intersection(pp, yuan, d, e)){
            pdd o = get_line_intersection(yuan, pp - yuan, d, e - d);
            ans = min(ans, pp.x / o.x);
        }
    }
    for(int i=0;i<n;i++) ans = min(ans,max(pp.x/q[i].x,pp.y/q[i].y));
    printf("%.12f\n", ans);
    
}

signed main()
{
	int tt = 1;
//	cin>>tt;
	while(tt--)
	{
		solve();
	}
}