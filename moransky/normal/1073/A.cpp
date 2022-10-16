#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1010;
int n;
char str[N];
int main(){
    cin >> n >> (str + 1);
    for(int i = 1; i < n; i++){
        if(str[i] != str[i + 1]){
            printf("YES\n%c%c\n", str[i], str[i + 1]);
            return 0;
        }
    }
    puts("NO");
    return 0;
}