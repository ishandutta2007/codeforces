#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1001;

int n, m, has[Maxn];
vector <pair <int, int> > V;
int seq[Maxn];

bool Less(const pair <int, int> &a, const pair <int, int> &b)
{
     if (a.first != b.first) return a.first > b.first;
     if (has[a.second] != has[b.second]) return has[a.second] > has[b.second];
     return a.second < b.second;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> has[i];
        V.push_back(make_pair(has[i], i));
    }
    int i;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < V.size(); j++)
           if (V[j].first == 0) V.erase(V.begin()+j--);
        sort(V.begin(), V.end(), Less);
        int col = 0;
        while (col < V.size() && (i && seq[i-1] == V[col].second || i == n-1 && seq[0] == V[col].second))
           col++;
        if (col == V.size()) break;
        seq[i] = V[col].second; V[col].first--;
    }
    if (i < n) cout << "-1\n";
    else {
         for (int i = 0; i < n; i++) {
             if (i) cout << " ";
             cout << seq[i];
         }
         cout << endl;
    }
    return 0;
}