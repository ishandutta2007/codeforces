#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string mn;
map <string, int> pnts;
vector <pair <string, int> > V;

bool Less(const pair <string, int> &a, const pair <string, int> &b)
{
     if (a.second != b.second) return a.second > b.second;
     return a.first < b.first;
}

int main()
{
    string s, a, b, act;
    cin >> mn >> n;
    while (n--) {
          cin >> a >> act;
          if (act != "likes") cin >> s;
          cin >> b; b.erase(b.length()-2, 2);
          cin >> s;
          if (a != mn && pnts.find(a) == pnts.end()) pnts[a] = 0;
          if (b != mn && pnts.find(b) == pnts.end()) pnts[b] = 0;
          if (b == mn) swap(a, b);
          if (a == mn)
             if (act == "posted") pnts[b] += 15;
             else if (act == "commented") pnts[b] += 10;
             else if (act == "likes") pnts[b] += 5;
    }
    for (map <string, int>::iterator it = pnts.begin(); it != pnts.end(); it++)
       V.push_back(make_pair(it->first, it->second));
    sort(V.begin(), V.end(), Less);
    for (int i = 0; i < V.size(); i++)
       cout << V[i].first << endl;
    return 0;
}