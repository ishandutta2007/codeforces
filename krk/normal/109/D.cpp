#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

struct Num {
       int goesto;
       bool lucky;
};

int n;
Num given[Maxn];
pair <int, int> ordered[Maxn];
int helper;
vector <pair <int, int> > res;

bool Lucky(int x)
{
     for (; x % 10 == 4 || x % 10 == 7; x /= 10) ;
     return !x;
}

void Add(int a, int b)
{
     if (a != b) res.push_back(make_pair(a + 1, b + 1));
}

void Swap(int a, int b)
{
     Add(a, b);
     swap(given[a], given[b]); swap(a, b);
     ordered[given[a].goesto].second = a;
     ordered[given[b].goesto].second = b;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        given[i].lucky = Lucky(val);
        ordered[i] = make_pair(val, i);
    }
    sort(ordered, ordered + n);
    bool sorted = true;
    helper = -1;
    for (int i = 0; i < n; i++) {
        given[ordered[i].second].goesto = i;
        if (ordered[i].second != i) sorted = false;
        if (given[ordered[i].second].lucky) helper = ordered[i].second;
    }
    if (sorted) cout << "0\n";
    else if (helper == -1) cout << "-1\n";
    else {
         for (int i = 0; i < n; i++) {
             int j = ordered[i].second;
             if (!given[j].lucky && given[j].goesto != j) {
                                 Swap(helper, given[j].goesto);
                                 Swap(given[j].goesto, j);
                                 helper = j;
             }
         }
         for (int i = 0; i < n; i++) {
             int j = ordered[i].second;
             if (given[j].goesto != j) Swap(given[j].goesto, j);
         }
         cout << res.size() << endl;
         for (int i = 0; i < res.size(); i++)
             cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}