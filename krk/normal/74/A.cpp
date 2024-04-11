#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector <pair <int, string> > V;

int main()
{
    string s;
    int tmp, pnts;
    cin >> n;
    while (n--) {
          cin >> s; pnts = 0;
          cin >> tmp; pnts += tmp * 100;
          cin >> tmp; pnts -= tmp * 50;
          for (int i = 0; i < 5; i++) {
              cin >> tmp; pnts += tmp;
          }
          V.push_back(make_pair(pnts, s));
    }
    sort(V.begin(), V.end());
    cout << V.back().second << endl;
    return 0;
}