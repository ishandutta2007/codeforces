#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

const int Maxk = 101;
const int Maxa = 50;

int k, n, m, q;
int B[Maxk][Maxa], C[Maxk][Maxa], need[Maxa][Maxa];
map <string, int> ids;
string arr[2*Maxa];
vector <pair <string, int> > V;

bool getNum(string &s, int &x)
{
     bool g = s[s.length()-1] == ',';
     if (g) s.erase(s.length()-1);
     stringstream ss(s);
     ss >> x;
     return g;
}

void Validate(int x)
{
     int i, j;
     for (i = 0; i < m; i++) {
         for (j = 0; j < n; j++) if (need[i][j] > B[x][j]) break;
         if (j == n) {
               C[x][i]++;
               for (j = 0; j < n; j++) B[x][j] -= need[i][j];
         }
     }
}

int main()
{
    string s;
    cin >> k >> n >> m >> q;
    for (int i = 0; i < n; i++) { cin >> s; ids[s] = i; arr[i] = s; }
    for (int i = 0; i < m; i++) {
        cin >> s; s.erase(s.length()-1, 1); ids[s] = n + i; arr[n+i] = s;
        bool q = false;
        int id, x;
        while (!q) {
              cin >> s; id = ids[s];
              cin >> s; q = !getNum(s, x);
              need[i][id] = x;
        }
    }
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x >> s;
        B[x][ids[s]]++;
        Validate(x);
    }
    for (int i = 1; i <= k; i++) {
        V.clear();
        for (int j = 0; j < n; j++) if (B[i][j]) V.push_back(make_pair(arr[j], B[i][j]));
        for (int j = 0; j < m; j++) if (C[i][j]) V.push_back(make_pair(arr[n+j], C[i][j]));
        sort(V.begin(), V.end());
        cout << V.size() << endl;
        for (int i = 0; i < V.size(); i++)
           cout << V[i].first << " " << V[i].second << endl;
    }
    return 0;
}