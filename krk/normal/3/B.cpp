#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, v, car;
int cancar[Maxn];
deque <int> take[2], lft;

bool Less(const int &a, const int &b)
{
     return cancar[a] < cancar[b];
}

int main()
{
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) lft.push_back(i);
        else take[1].push_back(i);
        cancar[i] = b;
    }
    sort(take[1].begin(), take[1].end(), Less);
    sort(lft.begin(), lft.end(), Less);
    while (2 * take[1].size() > v) take[1].pop_front();
    while (2 * take[1].size() + take[0].size() < v && !lft.empty()) {
          take[0].push_back(lft.back()); lft.pop_back();
    }
    while (lft.size() >= 2 && !take[1].empty() &&
           cancar[lft[lft.size()-2]] + cancar[lft[lft.size()-1]] > cancar[take[1].front()]) {
                                     take[1].pop_front();
                                     take[0].push_back(lft.back()); lft.pop_back();
                                     take[0].push_back(lft.back()); lft.pop_back();
    }
    if (lft.size() == 1 && !take[1].empty() && cancar[lft.back()] > cancar[take[1].front()]) {
                   take[1].pop_front();
                   take[0].push_back(lft.back()); lft.pop_back();
    }
    for (int i = 0; i < 2; i++)
       for (int j = 0; j < take[i].size(); j++)
          car += cancar[take[i][j]];
    cout << car << endl;
    bool printed = false;
    for (int i = 0; i < 2; i++)
       for (int j = 0; j < take[i].size(); j++) {
           if (printed) cout << " ";
           printed = true;
           cout << take[i][j] + 1;
       }
    if (printed) cout << endl;
    return 0;
}