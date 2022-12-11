#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int ch[26],num[26];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string P,H;
        cin >> P >> H;
        for(int i=0; i<26; i++) ch[i] = 0;
        for(int i=0; i<P.size(); i++) ch[P[i]-'a']++;
        bool ans = false;
        for(int i=0; i<=(int)H.size()-(int)P.size(); i++){
            for(int j=0; j<26; j++) num[j] = 0;
            for(int j=0; j<P.size(); j++) num[H[i+j]-'a']++;
            bool ispos = true;
            for(int j=0; j<26; j++) if(ch[j]!=num[j]) ispos = false;
            if(ispos) ans = true;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}