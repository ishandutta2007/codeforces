#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
char s[nax];

int main(){
    int T;
    for(cin >> T ; T -- ; ){
        int n;
        scanf("%d", &n);
        for(int i = 0  ;i < n / 2 ; i ++){
            s[i] = '1';
        }
        if(n % 2) s[0] = '7';
        s[n / 2] = '\0';
        printf("%s\n", s);
    }
}
/*
    Good Luck
        -Lucina
*/