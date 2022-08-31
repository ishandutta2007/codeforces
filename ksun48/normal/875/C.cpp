#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> edges[110000];
int val[110000];
vector<int> ans;
void setval(int t){
    if(val[t] == 1) return;
    val[t] = 1;
    ans.push_back(t);
    for(int j = 0; j < edges[t].size(); j++){
        setval(edges[t][j]);
    }
}
int main(){
    for(int i = 0; i < 110000; i++){
        val[i] = 0;
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int> > words;
    for(int i = 0; i < n; i++){
        vector<int> ws;
        int k;
        cin >> k;
        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            ws.push_back(a);
        }
        words.push_back(ws);
    }
    int ok = 1;
    vector<int> a, b;
    for(int i = 0; i + 1 < words.size(); i++){
        int f = -1;
        for(int r = 0; r < words[i].size() && r < words[i+1].size(); r++){
            if(words[i][r] == words[i+1][r]) continue;
            f = r;
            break;
        }
        if(f == -1){
            if(words[i].size() > words[i+1].size()) ok = 0;
            continue;
        }
        a.push_back(words[i][f]);
        b.push_back(words[i+1][f]);
    }
    if(ok == 0){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < a.size(); i++){
        edges[b[i]].push_back(a[i]);
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] > b[i]){
            setval(a[i]);
        }
    }

    for(int i = 0; i < a.size(); i++){
        //cout << a[i] << " " << b[i] << endl;
        if(val[a[i]] < val[b[i]]) ok = 0;
        if(val[a[i]] == val[b[i]] && a[i] > b[i]) ok = 0;
    }
    if(ok){
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

}