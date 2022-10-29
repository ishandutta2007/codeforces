#include <cstdio>
#include <iostream>
using namespace std;

int abs(int x){
    return (x>=0)?x:-x;
}

int main(){
    char x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    printf("%d\n",max(abs(x1-x2),abs(y1-y2)));
    while(x1!=x2||y1!=y2){
        if(x1<x2){
            putchar('R');
            x1++;
        }
        else if(x1>x2){
            putchar('L');
            x1--;
        }
        if(y1<y2){
            putchar('U');
            y1++;
        }
        else if(y1>y2){
            putchar('D');
            y1--;
        }
        putchar('\n');
    }
    return 0;
}