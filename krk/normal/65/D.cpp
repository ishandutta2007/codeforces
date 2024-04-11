#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct info {
       int p[4];
       bool operator <(const info &inf) const {
            for (int i = 0; i < 4; i++)
               if (p[i] != inf.p[i]) return p[i] < inf.p[i];
            return false;
       }
};

int n;
set <info> S;
bool canGet[4];

int main()
{
    info tmp;
    char ch;
    cin >> n;
    tmp.p[0] = tmp.p[1] = tmp.p[2] = tmp.p[3] = 0; S.insert(tmp);
    for (int i = 0; i < n; i++) {
        cin >> ch;
        set <info> nS;
        for (set <info>::iterator it = S.begin(); it != S.end(); it++) {
            tmp = *it;
            if (ch == 'G') {
                   tmp.p[0]++; nS.insert(tmp);
            } else if (ch == 'R') {
                   tmp.p[1]++; nS.insert(tmp);
            } else if (ch == 'H') {
                   tmp.p[2]++; nS.insert(tmp);
            } else if (ch == 'S') {
                   tmp.p[3]++; nS.insert(tmp);
            } else {
                   int seek = min(min(tmp.p[0], tmp.p[1]), min(tmp.p[2], tmp.p[3]));
                   for (int i = 0; i < 4; i++)
                      if (tmp.p[i] == seek) {
                                    tmp.p[i]++; nS.insert(tmp);
                                    tmp.p[i]--;
                      }
            }
        }
        S = nS;
    }
    for (set <info>::iterator it = S.begin(); it != S.end(); it++) {
        int seek = min(min(it->p[0], it->p[1]), min(it->p[2], it->p[3]));
        for (int i = 0; i < 4; i++)
           canGet[i] = canGet[i] || it->p[i] == seek;
    }
    if (canGet[0]) cout << "Gryffindor\n";
    if (canGet[2]) cout << "Hufflepuff\n";
    if (canGet[1]) cout << "Ravenclaw\n";
    if (canGet[3]) cout << "Slytherin\n";
    return 0;
}