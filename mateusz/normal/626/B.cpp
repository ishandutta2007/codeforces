#include <bits/stdc++.h>

using namespace std;
int n;
char word[205];
int main() {
    
    scanf("%d", &n);
    scanf("%s", &word[1]);
    int red = 0, green = 0, blue = 0;
    for (int i = 1; i <= n; i++) {
        if (word[i] == 'R') red++;
        else if (word[i] == 'B') blue++;
        else green++;
    }
    
    if ((red > 0 && green > 0) || (max(red, green) > 1 && blue > 0) || (max(red, green) == 0)) {
        printf("B");
    }
    
    if ((red > 0 && blue > 0) || (max(red, blue) > 1 && green > 0) || (max(blue, red) == 0)) {
        printf("G");
    }
    
    
    if ((blue > 0 && green > 0) || (max(blue, green) > 1 && red > 0) || (max(blue, green) == 0)) {
        printf("R");
    }
    
    return 0;
}