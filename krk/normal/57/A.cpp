#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair <pair <int, int>, int> p[2];

void Side(pair <pair <int, int>, int> &p)
{
    if (p.first.first == 0) p.second = 0;
    else if (p.first.first == n) p.second = 2;
    else if (p.first.second == 0) p.second = 3;
    else p.second = 1;
}

int main()
{
    cin >> n >> 
           p[0].first.first >> p[0].first.second >>
           p[1].first.first >> p[1].first.second;
    Side(p[0]); Side(p[1]);
    if (p[0].second > p[1].second) swap(p[0], p[1]);
    if (p[0].second == 0)
       if (p[1].second == 0) 
          cout << abs(p[0].first.second - p[1].first.second) << endl;
       else if (p[1].second == 1)
          cout << n - p[0].first.second + p[1].first.first << endl;
       else if (p[1].second == 2)
          cout << min(n - p[0].first.second + n - p[1].first.second,
                      p[0].first.second + p[1].first.second) + n << endl;
       else cout << p[0].first.second + p[1].first.first << endl;
    else if (p[0].second == 1)
            if (p[1].second == 1) cout << abs(p[0].first.first - p[1].first.first) << endl;
            else if (p[1].second == 2) cout << n - p[0].first.first + n - p[1].first.second << endl;
            else cout << min(p[0].first.first + p[1].first.first,
                             n - p[0].first.first + n - p[1].first.first) + n << endl;
    else if (p[0].second == 2)
            if (p[1].second == 2) cout << abs(p[0].first.second - p[1].first.second) << endl;
            else cout << p[0].first.second + n - p[1].first.first << endl;
    else cout << abs(p[0].first.first - p[1].first.first) << endl;
    return 0;
}