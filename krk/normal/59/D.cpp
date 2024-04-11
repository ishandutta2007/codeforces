#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 100000;

int n, v, pl[3*Maxn+1], T[Maxn][3];
set <int> S1, S2;
bool was;

bool Less(const int &a, const int &b)
{
     return pl[a] < pl[b];
}

int main()
{
    string tmp;
    int num;
    cin >> n;
    for (int i = 1; i <= 3*n; i++) {
        cin >> num;
        pl[num] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> T[i][0] >> T[i][1] >> T[i][2];
        sort(T[i], T[i]+3, Less);
    }
    cin >> v;
    int mx = -1;
    for (int i = 0; i < n; i++)
       if (T[i][0] == v) {
                S1.insert(T[i][1]); S1.insert(T[i][2]); mx = max(T[i][1], T[i][2]); break;
       } else if (T[i][1] == v || T[i][2] == v) break;
       else { S1.insert(T[i][0]); S1.insert(T[i][1]); S1.insert(T[i][2]); }
    if (mx == -1) {
       for (int i = 1; i <= 3*n; i++) if (i != v) {
           if (was) cout << " ";
           else was = true;
           cout << i;
       }
    } else {
         set <int>::iterator it;
         for (it = S1.begin(); it != S1.end(); it++) {
             if (was) cout << " ";
             else was = true;
             cout << *it;
             if (*it == mx) break;
         }
         for (it++; it != S1.end(); it++) S2.insert(*it);
         for (int i = 1; i <= 3*n; i++) if (S1.find(i) == S1.end() && i != v) S2.insert(i);
         for (it = S2.begin(); it != S2.end(); it++) {
             if (was) cout << " ";
             else was = true;
             cout << *it;
         }
    }
    cout << endl;
    return 0;
}