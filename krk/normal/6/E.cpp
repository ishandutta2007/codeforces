#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, k;
int h[Maxn];
int l, r;
map <int, int> is;
int best;
vector <pair <int, int> > res;

void Add(int x) { is[x]++; }

void Remove(int x) 
{
     if (--is[x] == 0) is.erase(x);
}

int getLast() { return is.rbegin()->first; }
int getFirst() { return is.begin()->first; }

void Check(int l, int r)
{
     int cnt = r - l + 1;
     if (cnt > best) {
             best = cnt;
             res.clear();
     }
     if (cnt >= best) res.push_back(make_pair(l + 1, r + 1));
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i];
    l = 0; r = 0; Add(h[0]);
    while (r < n)
          if (getLast() - getFirst() > k) Remove(h[l++]);
          else {
               Check(l, r);
               ++r;
               if (r < n) Add(h[r]);
          }
    cout << best << " " << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << endl;
    return 0;
}