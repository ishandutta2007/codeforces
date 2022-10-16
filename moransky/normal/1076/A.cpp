#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200010;
int n;
char str[N];
int main(){
    scanf("%d%s", &n, str + 1);
    for(int i = 1; i < n; i++){
        if(str[i] > str[i + 1]){
            for(int j = 1; j <= n; j++)
                if(j != i) printf("%c", str[j]);
            return 0;
        }
    }
    for(int i = 1; i < n; i++)
        printf("%c", str[i]);
    return 0;
}