#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>

using namespace std;


class Main
{
public:
    void solve(std::istream &in, std::ostream &out)
    {
        int n;
        in >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            in >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            in >> b[i];
        }
        for (int pos = 0; pos < n; pos++)
        {
            vector<int> p(n);
            set<int> s;
            for (int i = 0; i < n; i++)
            {
                if (i != pos)
                {
                    p[i] = a[i];
                    s.insert(a[i]);
                }
            }
            if (s.size() != n - 1)
            {
                continue;
            }
            int x = 0;
            for (int i = 1; i <= n; i++)
            {
                if (!s.count(i))
                {
                    x = i;
                }
            }
            p[pos] = x;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (p[i] != b[i])
                {
                    ans++;
                }
            }
            if (ans == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    out << p[i] << ' ';
                }
                out << '\n';
                return;
            }
        }
    }
};


int main()
{
    ios::sync_with_stdio(0);
    Main solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}