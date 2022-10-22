#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, b, f, n;
vector <pair <pair <int, int>, int > > parked;

int newPlace(int l, int id)
{
    int i, ans = -1;
    for (i = 0; i < parked.size()-1; i++)
       if (parked[i].first.second + b + l + f <= parked[i+1].first.first) {
                                  ans = parked[i].first.second + b;
                                  parked.push_back(make_pair(make_pair(ans, ans+l), id));
                                  break;
       }
    sort(parked.begin(), parked.end());
    return ans;
}

void Delet(int l)
{
     for (int i = 0; i < parked.size(); i++)
        if (parked[i].second == l) {
                             parked.erase(parked.begin()+i);
                             return;
        }
}

int main()
{
    int i, st, l;
    cin >> l >> b >> f;
    cin >> n;
    parked.push_back(make_pair(make_pair(-b, -b), -2));
    parked.push_back(make_pair(make_pair(l+f, l+f), -1));
    for (i = 1; i <= n; i++) {
        cin >> st >> l;
        if (st == 1) cout << newPlace(l, i) << endl;
        else Delet(l);
    }
    return 0;
}