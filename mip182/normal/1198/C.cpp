#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
 
// choose edges at random to be part of the "matching".
// if we find n edges, we're good. Otherwise, we've used
// no more than 2n vertices and there are at least
// n remaining vertices that form an independent set.
// Therefore, it is never impossible.
 
// Implementation:
// Store graph as edge list
// Mark vertices as visited
// Iterate through edges in order
// If an edge's endpoints are not visited, add the edge
// to the potential mapping. Mark endpoints as visited.
 
const int MAX_N = 1e5 + 5;
 
int T, n, m, u, v;
 
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for(int j = 0; j < T; j++) {
        cin >> n >> m;
        vector <bool> visited(3*n);
        vector <int> edgeList;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            if( !visited[u] && !visited[v]) {
                edgeList.push_back(i+1);
                visited[u] = true;
                visited[v] = true;
            }
        }
        if(edgeList.size() >= n) {
            cout << "Matching" << endl;
            for(int i = 0; i < n; i++) {
                cout << edgeList[i] << " ";
            }
            cout << endl;
        }else {
            cout << "IndSet" << endl;
            int num = 0;
            for(int i = 0; i < n; i++) {
                while (visited[num]) num++;
                cout<<num+1<<" ";
                num++;
                
            }
            cout << endl;
        }
    }
}