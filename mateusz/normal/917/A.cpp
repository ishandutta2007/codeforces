#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n;
char word[N];

int main() {
    
    scanf("%s", &word[1]);
    n = strlen(word + 1);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sumPref = 0;
        int minPref = 0;
        int questionMarks = 0;
        
        for (int j = i; j <= n; j++) {
            if (word[j] == ')') {
                sumPref--;
            } else {
                sumPref++;
            }
            
            if (word[j] == '?') {
                questionMarks++;
                minPref += 2;
            }
            
            minPref = min(minPref, sumPref);
            if (minPref < 0) {
                break;
            }
            
            if (sumPref % 2 == 0 && minPref - sumPref >= 0 && questionMarks >= sumPref / 2) {
                ans++;
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}