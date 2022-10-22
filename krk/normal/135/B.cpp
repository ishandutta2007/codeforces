#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 8;
const int Maxm = 4;

int x[Maxn], y[Maxn];
set <int> gen;
bool stop;

bool Square(vector <pair <int, int> > C)
{
     int ax = C[0].first - C[1].first, ay = C[0].second - C[1].second;
     int bx = C[2].first - C[0].first, by = C[2].second - C[0].second;
     int cx = C[3].first - C[1].first, cy = C[3].second - C[1].second;
     if (bx * bx + by * by == cx * cx + cy * cy && 
         ax * bx + ay * by == 0 && ax * cx + ay * cy == 0 &&
         ax * by - ay * bx != 0 &&
         ax * ax + ay * ay == bx * bx + by * by) return true;
     bx = C[3].first - C[0].first, by = C[3].second - C[0].second;
     cx = C[2].first - C[1].first, cy = C[2].second - C[1].second;
     return bx * bx + by * by == cx * cx + cy * cy && 
            ax * bx + ay * by == 0 && ax * cx + ay * cy == 0 &&
            ax * by - ay * bx != 0 &&
            ax * ax + ay * ay == bx * bx + by * by;
}

bool Rectangle(vector <pair <int, int> > C)
{
     int ax = C[0].first - C[1].first, ay = C[0].second - C[1].second;
     int bx = C[2].first - C[0].first, by = C[2].second - C[0].second;
     int cx = C[3].first - C[1].first, cy = C[3].second - C[1].second;
     if (bx * bx + by * by == cx * cx + cy * cy && 
         ax * bx + ay * by == 0 && ax * cx + ay * cy == 0 &&
         ax * by - ay * bx != 0) return true;
     bx = C[3].first - C[0].first, by = C[3].second - C[0].second;
     cx = C[2].first - C[1].first, cy = C[2].second - C[1].second;
     return bx * bx + by * by == cx * cx + cy * cy && 
            ax * bx + ay * by == 0 && ax * cx + ay * cy == 0 &&
            ax * by - ay * bx != 0;
}

bool Valid()
{
     vector <pair <int, int> > res1, res2;
     for (int i = 0; i < Maxn; i++)
         if (gen.find(i) != gen.end()) res1.push_back(make_pair(x[i], y[i]));
         else res2.push_back(make_pair(x[i], y[i]));
     sort(res1.begin(), res1.end()); sort(res2.begin(), res2.end());
     return Square(res1) && Rectangle(res2);
}

void Gen(int v, int lvl)
{
     if (lvl == Maxm) {
             if (Valid()) {
                          stop = true;
                          vector <int> res1, res2;
                          for (int i = 0; i < Maxn; i++)
                              if (gen.find(i) != gen.end()) res1.push_back(i + 1);
                              else res2.push_back(i + 1);
                          cout << "YES\n";
                          for (int i = 0; i < res1.size(); i++) {
                              cout << res1[i];
                              if (i + 1 < res1.size()) cout << " ";
                              else cout << endl;
                          }
                          for (int i = 0; i < res2.size(); i++) {
                              cout << res2[i];
                              if (i + 1 < res2.size()) cout << " ";
                              else cout << endl;
                          }
             }
     } else for (int i = v; i < Maxn && !stop; i++) {
                gen.insert(i);
                Gen(i + 1, lvl + 1);
                gen.erase(i);
     }
}

int main()
{
    for (int i = 0; i < Maxn; i++) cin >> x[i] >> y[i];
    Gen(0, 0);
    if (!stop) cout << "NO\n";
    return 0;
}