#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c,x,y,z,add=0,ree=0;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
    if(a>=x) add+=(a-x)/2;
    else ree+=x-a;
    if(b>=y) add+=(b-y)/2;
    else ree+=y-b;
    if(c>=z) add+=(c-z)/2;
    else ree+=z-c;
    if(add>=ree) printf("YES\n");
    else printf("NO\n");
    return 0;
}