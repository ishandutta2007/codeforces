#include <bits/stdc++.h>

using namespace std;

multiset<int> S;

bool usun(multiset<int>::iterator it) {
    if (it != S.end()) {
        S.erase(it);
        return true;
    }
    return false;
}

int main() {
    int n, A, B, C;
    
    scanf("%d", &n);
    scanf("%d %d %d", &A, &B, &C);
    if (A > B) swap(A, B);
    if (A > C) swap(A, C);
    if (B > C) swap(B, C);
    for (int i = 1; i <= n; i++) {
        int strength;
        scanf("%d", &strength);
        S.insert(-strength);
    }
    int wynik = 0;
    while (!S.empty()) {
        
        wynik++;
        auto x = S.begin();
        if (A + B + C < -*x) {
            printf("-1\n");
            return 0;
        }
        
        int w = -*x;
        usun(x);
        
        if (A >= w) {
            usun(S.begin());
            usun(S.begin());
        } else if (B >= w) {
            usun(S.lower_bound(-C));
            usun(S.lower_bound(-A));
        } else if (C >= w) {
            if (usun(S.lower_bound(-B)))
                usun(S.lower_bound(-A)); else {
                    usun(S.lower_bound(-B - A));
                }
        } else if (A + B >= w) {;
            usun(S.lower_bound(-C));
        } else if (A + C >= w) {
            usun(S.lower_bound(-B));
        } else if (B + C >= w) {
            usun(S.lower_bound(-A));
        }
    }
    
    printf("%d\n", wynik);
    
    
    return 0;
}