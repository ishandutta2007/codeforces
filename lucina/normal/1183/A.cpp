#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a;

int main(){
    scanf("%d",&a);
    while(true){
        int g=a;
        int sum=0;
        while(g){
            sum+=(g%10);
            g/=10;
        }
        if(sum%4==0)
            return !printf("%d\n",a);
        a++;
    }
}