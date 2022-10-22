#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map <string, int> M;
vector <int> V;

int n;

int main()
{
    cin >> n;
    while (n--) {
        string nam;
        int p;
        cin >> nam >> p;
        M[nam] = max(M[nam], p);
    }
    for (map <string, int>::iterator it = M.begin(); it != M.end(); it++) V.push_back(it->second);
    sort(V.begin(), V.end());
    printf("%d\n", M.size());
    for (map <string, int>::iterator it = M.begin(); it != M.end(); it++) {
        printf("%s ", it->first.c_str());
        int am = upper_bound(V.begin(), V.end(), it->second) - V.begin();
        if (2 * (V.size() - am) > V.size()) printf("noob\n");
        else if (2 * am >= V.size() && 5 * (V.size() - am) > V.size()) printf("random\n");
        else if (5 * am >= 4 * V.size() && 10 * (V.size() - am) > V.size()) printf("average\n");
        else if (10 * am >= 9 * V.size() && 100 * (V.size() - am) > V.size()) printf("hardcore\n");
        else printf("pro\n");
    }
    return 0;
}