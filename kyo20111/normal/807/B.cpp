#include <bits/stdc++.h>
using namespace std;
int a,b,c;
bool chk(int d){
    d = (d/50) % 475;
    for(int i=1;i<=25;i++){
        d = (d * 96 + 42) % 475;
        if(d+26 == a) return true;
    }
    return false;
}
int main(){
    scanf("%d %d %d",&a,&b,&c);

    for(int i=b;i>=c;i-=50) if(chk(i)) return !printf("0");
    for(int i=1;i<=500;i++) if(chk(b+i*50)) return !printf("%d",(i+1)/2);
}