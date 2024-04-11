#include <iostream>
#include <string>
#include <map>
using namespace std;

const short Maxn = 50;
const short Maxb = 10;

short bon[Maxb] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

struct racer {
       short points;
       short was[Maxn];
};

int t, n;
map <string, racer> R;

bool Better1(const racer &r1, const racer &r2)
{
     if (r1.points != r2.points) return r1.points > r2.points;
     for (int i = 0; i < Maxn; i++)
         if (r1.was[i] != r2.was[i]) return r1.was[i] > r2.was[i];
     return false;
}

bool Better2(const racer &r1, const racer &r2)
{
     if (r1.was[0] != r2.was[0]) return r1.was[0] > r2.was[0];
     return Better1(r1, r2);
}

int main()
{
    cin >> t;
    while (t--) {
          cin >> n;
          for (int i = 0; i < n; i++) {
              string s; cin >> s;
              short pnt = 0;
              if (i < Maxb) pnt = bon[i];
              R[s].points += pnt; R[s].was[i]++;
          }
    }
    string w1 = R.begin()->first, w2 = R.begin()->first;
    for (map <string, racer>::iterator it = R.begin(); it != R.end(); it++) {
        if (Better1(it->second, R[w1])) w1 = it->first;
        if (Better2(it->second, R[w2])) w2 = it->first;
    }
    cout << w1 << endl << w2 << endl;
    return 0;
}