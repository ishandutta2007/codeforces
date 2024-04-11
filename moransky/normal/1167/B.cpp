#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[6] = {4, 8, 15, 16, 23, 42};
int b[4];
bool inline judge(){
    for(int i = 0; i < 4; i++)
        if(a[i] * a[i + 1] != b[i]) return false;
    return true;
}
int main(){
    for(int i = 1; i <= 4; i++){
        printf("? %d %d\n", i, i + 1);
        fflush(stdout);
        scanf("%d", b + i - 1);
    }
    do{
        if(judge()){
            printf("! ");
            for(int i = 0; i < 6; i++)
                printf("%d ", a[i]);
            puts("");
            fflush(stdout);
            break;
        }
    }while(next_permutation(a, a + 6));
    return 0;
}