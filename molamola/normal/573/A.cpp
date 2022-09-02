#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int p;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        while(x % 2 == 0)x /= 2;
        while(x % 3 == 0)x /= 3;
        if(p == 0)p = x;
        else if(p != x){printf("NO");return 0;}
    }
    printf("YES");
    return 0;
}