#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n;
map <int, vector <int> > M;

int main()
{
    int a, b;
    vector <int> V(1);
    cin >> n;
    while (n--) {
          cin >> a >> b;
          if (M.find(a) == M.end()) {
                       V[0] = b;
                       M[a] = V; 
          } else M[a].push_back(b);
          if (M.find(b) == M.end()) {
                        V[0] = a;
                        M[b] = V;
          } else M[b].push_back(a);
    }
    int u, v;
    for (map <int, vector <int> >::iterator it = M.begin(); it != M.end(); it++)
       if (it->second.size() == 1) { v = it->first; break; }
    u = -1;
    do {
        cout << v;
        if (M[v][0] != u) { u = v; v = M[v][0]; cout << " "; }
        else if (M[v].size() > 1) { u = v; v = M[v][1]; cout << " "; }
        else break;
    } while (true);
    cout << endl;
    return 0;
}