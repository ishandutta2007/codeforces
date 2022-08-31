#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    string str[n];
    int ok = 1;
    int reach[26][26];
    int has[26];
    for(int i = 0; i < 26; i++){
        has[i] = 0;
        for(int j = 0; j < 26; j++){
            reach[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> str[i];
        if(str[i].size() > 26){
            ok = 0;
            break;
        }
        for(int j = 0; j < str[i].size(); j++){
            has[str[i][j]-'a'] = 1;
        }
        for(int j = 0; j + 1 < str[i].size(); j++){
            reach[str[i][j]-'a'][str[i][j+1]-'a'] = 1;
        }
    }
    for(int i = 0; i < 26; i++){
        int n1 = 0;
        int n2 = 0;
        for(int j = 0; j < 26; j++){
            if(reach[i][j]) n1++;
            if(reach[j][i]) n2++;
        }
        if(n1 > 1 || n2 > 1) ok = 0;
    }
    if(ok == 0){
        cout << "NO" << endl;
        return 0;
    }
    vector<string> ans;
    int used[26];
    for(int i = 0; i < 26; i++){
        used[i] = 0;
    }


    int num = 0;

    for(int i = 0; i < 26; i++){
        if(!has[i]) continue;
        num++;
        int n1 = 0;
        int n2 = 0;
        for(int j = 0; j < 26; j++){
            if(reach[i][j]) n1++;
            if(reach[j][i]) n2++;
        }
        if(n2) continue;
        string cur;
        int a = i;
        while(1){
            if(a == -1) break;
            if(used[a]){
                ok = 0;
                break;
            }
            used[a] = 1;
            cur += (char)('a'+a);
            int b = -1;
            for(int j = 0; j < 26; j++){
                if(reach[a][j]){
                    b = j;
                }
            }
            a = b;
        }
        ans.push_back(cur);
    }
    sort(ans.begin(), ans.end());
    string gg;
    for(int i = 0; i < ans.size(); i++){
        gg += ans[i];
    }
    if(ok == 0 || gg.size() != num){
        cout << "NO" << endl;
        return 0;
    }
    cout << gg << endl;
}