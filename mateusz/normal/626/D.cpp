#include <bits/stdc++.h>

using namespace std;

int n;
int tab[5005];
int zlicz[5005];
int pref[5005];
int main() {
    
//     scanf("%d", &n);
    cin >> n;
    for (int i = 1; i <= n; i++) {
//         scanf("%d", &tab[i]);
        cin >> tab[i];
        for (int j = i - 1; j >= 1; j--) {
            zlicz[abs(tab[j] - tab[i])]++;
        }
    }
    
    long double prob = 0.0;
 
    for (int i = 1; i <= 5000; i++) {
        pref[i] = pref[i - 1] + zlicz[i];

        for (int j = 1; j < i - 1; j++) {
            prob += (long double)zlicz[i] * (long double)zlicz[j] * pref[i - j - 1];
        }
    }
    
    prob /= pow((long double)n * (n - 1) / 2, 3);
    
    cout << setprecision(18) << prob << "\n";
//     printf("%.9lf\n", (double)prob);
    
    return 0;
}