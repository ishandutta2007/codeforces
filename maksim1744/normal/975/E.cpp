#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

typedef long double ld;

struct point
{
    ld x, y;
    point(): x(0), y(0) {}
    point(int x, int y): x(x), y(y) {}
    point(ld x, ld y): x(x), y(y) {}
    point operator+(point b)
    {
        return point(x + b.x, y + b.y);
    }
    point operator-(point b)
    {
        return point(x - b.x, y - b.y);
    }
    point operator*(ld k)
    {
        return point(x * k, y * k);
    }
    point operator/(ld k)
    {
        return point(x / k, y / k);
    }
};

ld cross_product(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

ld dot_product(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

ld mabs(ld u)
{
    if (u < 0) {
        return -u;
    }
    return u;
}

point triangle_center(point a, point b, point c)
{
    return (a + b + c) / 3;
}

ld triangle_area(point a, point b, point c)
{
    return mabs(cross_product(b - a, c - a));
}

ld dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld dist(point a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t = 2;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n, q;
        cin >> n >> q;
        vector< point > pt(n);
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            pt[i] = point(x, y);
        }
        point mass(0, 0);
        ld all_area = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            ld s = triangle_area(pt[0], pt[i], pt[i + 1]);
            all_area += s;
            mass = mass + triangle_center(pt[0], pt[i], pt[i + 1]) * s;
        }
        mass = mass / all_area;
        int v1 = 0, v2 = 1;
        point p1 = pt[0], p2 = pt[1];
        int vup;
        point pup;
        bool change = false;
        for (int i = 0; i < q; ++i)
        {
            int que_type;
            cin >> que_type;
            if (que_type == 1) {
                int u, v;
                cin >> u >> v;
                u--; v--;
                change = true;
                if (u == v1) {
                    v1 = v;
                    vup = v2;
                    pup = p2;
                    ld d = dist(pt[vup], mass);
                    ld d1 = dist(mass, pt[v]);
                    ld sin = cross_product(pt[vup] - mass, pt[v] - mass);
                    p1.x = d1 * sin / dist(pt[vup] - mass) / dist(pt[v] - mass);
                    ld cos = dot_product(pt[vup] - mass, pt[v] - mass);
                    p1.y = d1 * cos / dist(pt[vup] - mass) / dist(pt[v] - mass);
                    if (sin * cross_product(point(0.0, d), p1) < 0) {
                        p1.x = -p1.x;
                    }
                    p1 = p1 + pup;
                    p1.y -= d;
                }
                else {
                    v2 = v;
                    vup = v1;
                    pup = p1;
                    ld d = dist(pt[vup], mass);
                    ld d1 = dist(mass, pt[v]);
                    ld sin = cross_product(pt[vup] - mass, pt[v] - mass);
                    p2.x = d1 * sin / dist(pt[vup] - mass) / dist(pt[v] - mass);
                    ld cos = dot_product(pt[vup] - mass, pt[v] - mass);
                    p2.y = d1 * cos / dist(pt[vup] - mass) / dist(pt[v] - mass);
                    if (sin * cross_product(point(0.0, d), p2) < 0) {
                        p2.x = -p2.x;
                    }
                    p2 = p2 + pup;
                    p2.y -= d;
                }
            }
            else {
                int v;
                cin >> v;
                v--;
                if (!change) {
                    cout << pt[v].x << ' ' << pt[v].y << '\n';
                }
                else {
                    point p0;
                    ld d = dist(pt[vup], mass);
                    ld d1 = dist(mass, pt[v]);
                    ld sin = cross_product(pt[vup] - mass, pt[v] - mass);
                    p0.x = d1 * sin / dist(pt[vup] - mass) / dist(pt[v] - mass);
                    ld cos = dot_product(pt[vup] - mass, pt[v] - mass);
                    p0.y = d1 * cos / dist(pt[vup] - mass) / dist(pt[v] - mass);
                    if (sin * cross_product(point(0.0, d), p0) < 0) {
                        p0.x = -p0.x;
                    }
                    p0 = p0 + pup;
                    p0.y -= d;
                    cout << p0.x << ' ' << p0.y << '\n';
                }
            }
        }
    }
    fclose(stdout);
    return 0;
}