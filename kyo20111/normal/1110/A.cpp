#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int b,k,ans,fl,a;
int main(){
    scanf("%d %d",&b,&k);
    for(int i=1;i<k;i++){
        scanf("%d",&a);
        if(a*b%2) fl=1-fl;
    }
    scanf("%d",&a);
    if(a%2) fl=1-fl;
    printf("%s",((fl)?"odd":"even"));
}