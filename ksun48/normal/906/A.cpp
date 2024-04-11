#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n;
    cin >> n;
    int ok[26];
    for(int i = 0; i < 26; i++){
        ok[i] = 1;
    }
    int ans = 0;
    int done = 0;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        if(i == n-1) continue;
        if(a[0] == '!'){
            if(done){
                ans++;
            } else {
                int word[26];
                for(int j = 0; j < 26; j++) word[j] = 0;
                for(int j = 0; j < b.size(); j++){
                    word[b[j]-'a'] = 1;
                }
                for(int j = 0; j < 26; j++){
                    if(word[j] == 0) ok[j] = 0;
                }
            }
        } else if(a[0] == '.'){
            if(done){
            } else {
                for(int j = 0; j < b.size(); j++){
                    ok[b[j]-'a'] = 0;
                }
            }
        } else if(a[0] == '?'){
            if(done){
                ans++;
            } else {
                ok[b[0]-'a'] = 0;
            }
        }
        int num = 0;
        for(int j = 0; j < 26; j++){
            num += ok[j];
        }
        if(num == 1) done = 1;
    }
    cout << ans << endl;
}