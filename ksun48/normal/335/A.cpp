#include<iostream>
#include<string.h>
#define LL long long
using namespace std;

int main(){
    char s[1100];
    cin >> s;
    int len = strlen(s);
    int stuff[26];
    for(int i = 0; i < 26; i++) stuff[i] = 0;
    for(int i = 0; i < len; i++){
        stuff[s[i]-'a'] ++;
    }
    int n;
    cin >> n;
    int num = 0;
    //for(int i = 0; i < 26; i++) cout << stuff[i] << endl;
    for(int i = 0; i < 26; i++) if(stuff[i] > 0) num++;
    if(num > n){
        cout << -1 << endl;
        return 0;
    }
    int ans;
    for(ans = 1; ans <= 1001; ans++){
        int cur = 0;
        for(int i = 0; i < 26; i++){
            if(stuff[i] > 0){
                int k = (stuff[i]-1)/ans + 1;
                cur += (stuff[i]-1)/ans + 1;
                //cout << stuff[i] << " " << k << endl;
            }
        }
        if(cur <= n){
            cout << ans << endl;
            cur = 0;
            for(int i = 0; i < 26; i++){
                if(stuff[i] > 0){
                    int k = (stuff[i]-1)/ans + 1;
                    cur += (stuff[i]-1)/ans + 1;
                    for(int j = 0; j < k; j++){
                        char m = 'a' + i;
                        cout << m;
                    }
                }
            }
            for(int i = 0; i < n-cur; i++){
                cout << "z";
            }
            cout << endl;
            return 0;
        }
    }
}