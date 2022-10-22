#include <iostream>
using namespace std;
 
int main() {
    int n = 0;
    
    cin >> n;
    
    int x = 0;
    int y = 0;
    
    int i, j, k;
    
    
    int s[n];
    int counter = 0;
    
    cin >> x;
    
    int p[x];
    
    for (i = 0; i < x; i++) {
        p[i] = 0;
        cin >> p[i];
    }
    
    cin >> y;
    
    int a[y];
    
    for (i = 0; i < y; i++) {
        a[i] = 0;
        cin >> a[i];
    }
    
    j = 0;
    
    for (i = 0; i < n; i++) {
        s[i] = 0;
        j = i + 1;
        
        for (k = 0; k < x; k++) {
            if (j == p[k]) {
                s[i] = 1;
            }
        }
        
        for (k = 0; k < y; k++) {
            if (j == a[k]) {
                s[i] = 1;
            }
        }
        if (s[i] == 1) {
            counter++;
        }
    }
    
    
    if (counter == n) {
        cout << "I become the guy.";
    } else {
        cout << "Oh, my keyboard!";
    }
    
    
    return 0;
}