#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int a,b; scanf("%d %d",&a,&b);
        if(a == b){
            printf("0\n");
            continue;
        }
        if(a > b) swap(a, b);
        int c = (b - a) / 5;
        if((b-a)%5 >= 1) c++;
        if((b-a)%5 >= 3) c++;
        printf("%d\n",c);
    }
}