#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    vector<int> deg(n+1, 0);
    vector<int> p(n+1, 0);
    vector<int> lc(n+1, 0);
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        deg[i]++;
        deg[p[i]]++;
    }
    int ok = 1;
    for(int i = 2; i <= n; i++){
        if(deg[i] == 1){
            lc[p[i]]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(deg[i] == 1) continue;
        if(lc[i] < 3) ok = 0;
    }
    if(ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}