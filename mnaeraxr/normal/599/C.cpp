#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define wait system("pause")

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    vector<int> w = v;
    
    sort(w.begin(), w.end());
    
    int ans = 0;
    multiset<int> V, W;
    for (int i = 0; i < n; ++i){
        int ev = v[i], ew = w[i];
        if (ev != ew){
           multiset<int>::iterator it = W.find(ev);
           if (it != W.end())
              W.erase(it);
           else
              V.insert(ev);
              
           it = V.find(ew);
           if (it != V.end())
              V.erase(it);
           else
              W.insert(ew);
        }
        if (V.empty() && W.empty())
           ++ans;
    }
    
    cout << ans << endl;
    
   // wait;
    
    return 0;
}