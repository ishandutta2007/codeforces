#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define wait system("pause")

using namespace std;

typedef long long int64;
typedef pair<int64, int64> pii;

int main()
{
    int64 k; cin >> k;
    k *= 6;
    
    vector<pii> S;
    
    for (int64 b = 1; ; ++b){
        int64 total = b * (b + 1) * (2 * b + 1);
        if (total > k) break;
        
        if (k % (b * (b + 1))) continue;
        int64 t = k / (b * (b + 1));
        if ((t + b - 1) % 3) continue;
        int64 a = (t + b - 1) / 3;
        if (a < b) break;
        S.push_back(pii(b, a));
        
        if (a != b){
              S.push_back(pii(a, b));
        }        
    }
    
    sort(S.begin(), S.end());
    int n = S.size();
    cout << n << endl;
    for (int i = 0; i < n; ++i)
        cout << S[i].first << " " << S[i].second << endl;
    
    
    
    //wait;
    
    return 0;
}