#include <algorithm>
#include <iostream>
#include <vector>
#define s first.first
#define r second.first.first
#define h first.second
#define c second.first.second
#define n second.second

using namespace std;

typedef pair<pair<int, int>, pair<pair<int, int>, int>> lti;
vector<lti> v;

int main()
{
    int am;
    cin >> am;
    v.resize(am);
    for (int i = 0; i < am; ++i)
        cin >> v[i].s >> v[i].r >> v[i].h >> v[i].c, v[i].n = i + 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    for (int j = i + 1; j < v.size(); ++j)
        if (v[i].s < v[j].s && v[i].r < v[j].r && v[i].h < v[j].h)
            {v.erase(v.begin() + i), --i; break;}
    cout << max_element(v.begin(), v.end(), [](lti a, lti b){return a.c > b.c;})->n;
    return 0;
}