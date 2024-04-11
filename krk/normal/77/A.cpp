#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 7;

int n, a, b, c;
map <string, int> ind;
vector <pair <int, int> > likes;
int ingroup[Maxn], bestexp = -1, bestlik;
string s, ss;

void Gen(int lvl)
{
     if (lvl == Maxn) {
             int was[3] = {};
             for (int i = 0; i < Maxn; i++) was[ingroup[i]]++;
             if (!was[0] || !was[1] || !was[2]) return;
             int gets[3];
             gets[0] = a / was[0]; gets[1] = b / was[1]; gets[2] = c / was[2];
             int curexp = max(max(gets[0], gets[1]), gets[2]) - min(min(gets[0], gets[1]), gets[2]);
             int curlik = 0;
             for (int i = 0; i < likes.size(); i++)
                if (ingroup[likes[i].first] == ingroup[likes[i].second]) curlik++;
             if (bestexp == -1 || curexp < bestexp || curexp == bestexp && curlik > bestlik) {
                         bestexp = curexp;
                         bestlik = curlik;
             }
     } else for (int i = 0; i < 3; i++) {
               ingroup[lvl] = i;
               Gen(lvl+1);
            }
}

int main()
{
    ind["Anka"] = 0;
    ind["Chapay"] = 1;
    ind["Cleo"] = 2;
    ind["Troll"] = 3;
    ind["Dracul"] = 4;
    ind["Snowy"] = 5;
    ind["Hexadecimal"] = 6;
    cin >> n;
    while (n--) {
          cin >> s >> ss >> ss;
          likes.push_back(make_pair(ind[s], ind[ss]));
    }
    cin >> a >> b >> c;
    Gen(0);
    cout << bestexp << " " << bestlik << endl;
    return 0;
}