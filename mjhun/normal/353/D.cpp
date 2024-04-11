#include <cstdio>

int main(){
    int i=0,p=1,r=0;
    char c;
    while(getchar()=='F');
    while((c=getchar())=='F'||c=='M'){
        if(c=='F'){
            if(p-i>r)r=p-i;
            else r++;
            i++;
        }
        p++;
    }
    printf("%d\n",r);
    return 0;
}