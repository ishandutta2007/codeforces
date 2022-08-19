#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int maxval = 0;
    
    vector<int> ans;
    ans.push_back(1);
    for(int i = 0; i < n; i++){
        maxval = max(maxval, a[n-1-i]);

        ans.push_back(1 + (maxval) - (i+1));
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}