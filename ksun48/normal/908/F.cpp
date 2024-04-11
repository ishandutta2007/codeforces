#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n;
    cin >> n;
    vector<LL> v;
    vector<int> gloc;
    vector<int> col;
    for(int i = 0; i < n; i++){
        LL a;
        string b;
        cin >> a >> b;
        v.push_back(a);
        col.push_back(b[0]);
        if(col[i] == 'G') gloc.push_back(i);
    }
    LL minr = 2e9;
    LL maxr = -1;
    LL minb = 2e9;
    LL maxb = -1;
    for(int i = 0; i < n; i++){
        if(col[i] == 'R'){
            minr = min(minr, v[i]);
            maxr = max(maxr, v[i]);
        }
        if(col[i] == 'B'){
            minb = min(minb, v[i]);
            maxb = max(maxb, v[i]);
        }
    }
    if(gloc.size() == 0){
        if(maxr == -1){
            cout << maxb - minb << endl;
            return 0;
        }
        if(maxb == -1){
            cout << maxr - minr << endl;
            return 0;
        }
        cout << maxr - minr + maxb - minb << endl;
        return 0;
    }
    LL ans = 0;
    ans += max(v[gloc[0]] - minr, 0LL);
    ans += max(v[gloc[0]] - minb, 0LL);
    ans += max(maxr - v[gloc[gloc.size()-1]], 0LL);
    ans += max(maxb - v[gloc[gloc.size()-1]], 0LL);
    for(int i = 0; i + 1 < gloc.size(); i++){
        LL test = v[gloc[i+1]] - v[gloc[i]];
        LL best1 = test * 2;
        LL best2 = test * 3;
        vector<LL> reds;
        vector<LL> blues;
        for(int j = gloc[i]; j <= gloc[i+1]; j++){
            if(col[j] != 'R') blues.push_back(v[j]);
            if(col[j] != 'B') reds.push_back(v[j]);
        }
        LL maxred = 0;
        LL maxblue = 0;
        for(int j = 0; j + 1 < reds.size(); j++){
            maxred = max(maxred, reds[j+1] - reds[j]);
        }
        for(int j = 0; j + 1 < blues.size(); j++){
            maxblue = max(maxblue, blues[j+1] - blues[j]);
        }
        best2 -= maxred + maxblue;
        ans += min(best2, best1);
    }
    cout << ans << endl;
}