#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int freq[26][26][5100];
int letter[26];
int main(){
    for(int i = 0; i < 26; i++){
        letter[i] = 0;
        for(int j = 0; j < 26; j++){
            for(int k = 0; k < 5100; k++){
                freq[i][j][k] = 0;
            }
        }
    }
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        letter[s[i]-'a']++;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int r = (j - i + n) % n;
            freq[s[i]-'a'][s[j]-'a'][r]++;
        }
    }
    LL ans = 0;
    for(int i = 0; i < 26; i++){
        int best = 0;
        for(int len = 0; len <= n; len++){
            int ns = 0;
            for(int j = 0; j < 26; j++){
                if(freq[i][j][len] == 1) ns++;
            }
            best = max(best, ns);
        }
        ans += best;
    }
    double gg1 = ans;
    double gg2 = n;
    cout << fixed << setprecision(10);
    cout << gg1 / gg2 << endl;
}