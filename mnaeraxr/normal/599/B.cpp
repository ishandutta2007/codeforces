#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int,int> M;
    
    for (int i = 1; i <= n; ++i){
        int v; cin >> v;
        if (M.count(v)) M[v] = -1;
        else M[v] = i;
    }
    
    vector<int> ans(m);
    
    bool amb = false;
    
    for (int i = 0; i < m; ++i){
        int v; cin >> v;
        if (!M.count(v)){
           cout << "Impossible" << endl;
           exit(0);
        }
        
        if (M[v] == -1){
           amb = true;
        }
        if (amb) continue;
        
        ans[i] = M[v];                
    }
    
    if (amb){             
           cout << "Ambiguity" << endl;
           exit(0);
    }

    cout << "Possible" << endl;    
    for (int i = 0; i < m; ++i)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}