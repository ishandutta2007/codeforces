#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
typedef long long ll;
const int MAXN = 1e6;
int p[MAXN];
struct Point{
    ll x,y,i,j; double ang;
    Point(){ x=y=0; }
    Point(ll a,ll b){ x=a,y=b; }
    Point(ll a,ll b,double c){ i=a,j=b,ang=c; }
    Point operator -(const Point &n)const{ return Point(x-n.x,y-n.y); }
    bool operator <(const Point&n)const{ return x==n.x? y<n.y: x<n.x; }
    double polar(){ return atan2(y,x); }
    void output(){ cout<<x<<' '<<y<<endl; }
}point[2010],vec[4*MAXN];

int crossproduct(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}
int dotproduct(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}
int funct(int i, int j, int k)
{
    return abs(crossproduct(point[j] - point[i], point[k] - point[i]));
}
bool cmp(Point a, Point b)
{
    return a.ang < b.ang;
}
int32_t main() {
//    ios::sync_with_stdio(0);
  //  cin.tie(0);
    int n;
    long long s;
    cin >> n >> s;
    s *= 2;
    for(int i = 0; i < n; i++)
    {
        cin >> point[i].x >> point[i].y;
        p[i] = i;
    }
    int cnt = 0;
    sort(point, point + n);
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            vec[cnt++] = Point(i, j, (point[j] - point[i]).polar());
        }
    }
    sort(vec, vec + cnt, cmp);
    for(int i = 0; i < cnt; i++)
    {
        int &a = p[vec[i].i], &b = p[vec[i].j];
        int l =0 , r = a - 1;
        int ans = -1;
        while(l <= r)
        {
            int midd = (r + l) / 2;
            long long s1 = funct(a, b, midd);
            if(s1 == s)
            {
                ans = midd;
                break;
            }
            else if(s1 > s)
            {
                l = midd + 1;
            }
            else
            {
                r = midd - 1;
            }
        }
        if(ans != -1)
        {
            cout << "Yes\n";
            cout << point[a].x << " " << point[a].y << "\n";
            cout << point[b].x << " " << point[b].y << "\n";
            cout << point[ans].x << " " << point[ans].y;
            return 0;
        }
        swap(a, b);
        swap(point[a], point[b]);
    }
    cout << "No";
    return 0;
}