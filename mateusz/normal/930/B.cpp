#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

string s;
int cnt[35];

int main() {
    double prob = 0.0;
    cin >> s;
    for (char c = 'a'; c <= 'z'; c++) {
        int cntC = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) cntC++;
        }
        
        double bestProb = 0.0;
        for (int j = 1; j < s.size(); j++) {
            for (int i = 0; i < 26; i++) cnt[i] = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == c) {
                    cnt[s[(i + j) % s.size()] - 'a']++;
                }
            }
            
            double probWin = 0.0;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 1) {
                    probWin += 1.0 / cntC;
                }
            }
            bestProb = max(bestProb, probWin);
        }
        prob += (double)cntC / s.size() * bestProb;
    }
    
    cout << fixed << setprecision(10) << prob << endl;
    
    return 0;
}