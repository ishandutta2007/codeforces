#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxl = 5001;

int n;
pair <pair <int, int>, int> les[Maxl];
vector <int> ans;

bool canOmit(int x)
{
     int ended = 1;
     for (int i = 0; i < n; i++) if (i != x)
        if (ended > les[i].first.first) return false;
        else ended = les[i].first.second;
     return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> les[i].first.first >> les[i].first.second;
        les[i].second = i + 1;
    }
    sort(les, les + n);
    for (int i = 0; i < n; i++) 
       if (canOmit(i)) ans.push_back(les[i].second);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size()-1) cout << " ";
        else cout << endl;
    }
    return 0;
}