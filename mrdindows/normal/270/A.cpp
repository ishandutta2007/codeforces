#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int a;
        bool flag = 0;
        scanf("%d", &a);
        for(int j = 3; j < 18000; j++) {
            if(180 * (j - 2) == a * j) {
                puts("YES\n");
                flag = 1;
                break;
            }
        }
        if(!flag)
            puts("NO\n");
    }
    return 0;
}