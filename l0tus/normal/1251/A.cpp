#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
bool ch[26];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        for(int i=0; i<26; i++) ch[i] = 0;
        for(int i=0; i<S.size(); i++){
            if(i==S.size()-1||S[i]!=S[i+1]) ch[S[i]-'a'] = 1;
            else i++;
        }
        for(int i=0; i<26; i++) if(ch[i]) cout << (char)('a'+i);
        cout << '\n';
    }
}