#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e5 + 100;
const int mod = 1e9 + 7;
const double eps = 1e-9;

double x1, y1, x2, y2;
int n;
vector <vector <int> > vec;
double funct(int t)
{
    double A = y2 - y1;
    double B = x1 - x2;
    double C = - x1 * A - y1 * B;
    double x0 = (x1 + x2) / 2;
    double y0 = (y1 + y2) / 2;
    double d1 =sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 2; 
    vector <pair <double, int> > events1;
    double dt = sqrt(A * A + B * B);
    A /= dt;
    B /= dt;
    C /= dt;
    for(int i = 0; i < n; i++)
    {
        double a = vec[i][0];
        double b = vec[i][1];
        double c = vec[i][2];
        double l = d1;
        double r = 1e11;
        bool fl = 0;
        if(t * (a * A + b * B + C) > 0)
        {
            if(d1 >= sqrt((a - x0) * (a - x0) + (b - y0) * (b - y0)) + c)
            {
                fl = 1;
            }
        }
        else if(d1 <= sqrt((a - x0) * (a - x0) + (b - y0) * (b - y0)) - c)
        {
            fl = 1;
        }
        if(fl)
        {
            continue;
        }
        int iter = 100;
        while(iter--)
        {
            double midd = (r + l) / 2;
            double dx = A * sqrt(midd * midd - d1 * d1);
            double dy = B * sqrt(midd * midd - d1 * d1);
            double x_next = dx * t + x0;
            double y_next = dy * t + y0;
            if(t * (a * A + b * B + C) > 0)
            {
                if(sqrt((x_next - a) * (x_next - a) + (y_next -b ) * (y_next - b)) >= (c + midd))
                {
                    l = midd;
                }
                else
                {
                    r = midd;
                }
            }
            else
            {
                if(sqrt((x_next - a) * (x_next - a) + (y_next - b) * (y_next - b)) + c <= midd)
                {
                    l = midd;
                }
                else
                {
                    r = midd;
                }
            }
        }
        double l1 = d1;
        double r1 = 1e11;
        iter = 100;
        while(iter--)
        {
            double midd = (r1 + l1) / 2;
            double dx = A * sqrt(midd * midd - d1 * d1);
            double dy = B * sqrt(midd * midd - d1 * d1);
            double x_next = dx * t + x0;
            double y_next = dy * t + y0;
            if(t * (a * A + b * B + C) > 0)
            {
                if(sqrt((x_next - a) * (x_next - a) + (y_next - b) * (y_next - b)) + c <= midd)
                {
                    r1 = midd;
                }
                else
                {
                    l1 = midd;
                }
            }
            else
            {
                if(sqrt((x_next - a) * (x_next - a) + (y_next - b) * (y_next - b)) <= (midd + c))
                {
                    l1 = midd;
                }
                else
                {
                    r1 = midd;
                }
            }
        }
       /* if(t == 1)
        {
            cout << d1 << " ";
            cout <<  t * (a * A + b * B + C) << "\n";
            cout << i << " " << l << " " << l1 << "\n";
        }*/
        events1.push_back({l, 1});
        events1.push_back({l1, -1});
    }
    sort(events1.begin(), events1.end());
    if(sz(events1) == 0)
    {
        return d1;
    }
    int cnt = 0;
    if(abs(events1[0].X - d1) > eps)
    {
        return d1;
    }

    for(auto p : events1)
    {
        cnt += p.Y;
        if(cnt == 0)
        {
            return p.X;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({a, b, c});
    }
    cout << fixed << setprecision(10) << min(funct(1), funct(-1));
    return 0;
}