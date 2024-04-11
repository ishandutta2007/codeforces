#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int Maxn = 1000;

int n, best;
map <string, int> res, res2;
pair <string, int> Info[Maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Info[i].first >> Info[i].second;
        if (res.find(Info[i].first) == res.end()) res[Info[i].first] = Info[i].second;
        else res[Info[i].first] += Info[i].second;
    }
    for (map <string, int>::iterator it = res.begin(); it != res.end(); it++)
       if (it->second > best) best = it->second;
    for (int i = 0; i < n; i++) {
        if (res2.find(Info[i].first) == res2.end()) res2[Info[i].first] = Info[i].second;
        else res2[Info[i].first] += Info[i].second;
        if (res2[Info[i].first] >= best && res[Info[i].first] == best) {
                               cout << Info[i].first << endl; break;
        }
    }
    return 0;
}