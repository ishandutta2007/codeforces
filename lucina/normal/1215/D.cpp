#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n,a[maxn],bal,x1,x2,y1,y2;
char s[maxn];
 
int main(){
    scanf("%d%s",&n,s+1);
    int cur =0;
    for(int i=1;i<=n/2;i++){
        if(s[i] !='?'){
            bal += s[i] - '0';
            continue;
        }
        else{
           if(cur & 1){
                x2++;
           }
           else{
            x1 ++;
           }
           cur ^= 1;
        }
    }
    for(int i = n/2+1;i <=n;i++){
        if(s[i] !='?'){
            bal -= s[i] - '0';
            continue;
        }
        else{
           if(cur & 1){
                y2++;
           }
           else{
                y1++;
           }
           cur ^= 1;
        }
    }
    int x = bal;
    bool first = false;
    {
        ///If Monocarp wants left to l - r > 0
        for(int i=1;i<=x1; i++){
            bal += 9;
        }
        for(int i=1;i<=y2;i++)
            bal -= 9;
        if( (bal <= 0 && (bal + 9*y2 >=0))){
            ;
        }
        else first = true;
    }
    {
        /// If Monocarp wants l-r <0
        bal = x;
        for(int i=1;i<=x2;i++)
            bal += 9;
        for(int i=1;i<=y1;i++)
            bal -= 9;
        if( (bal >= 0) && (bal - (9*x2)<=0))
            ;
        else
            first = true;
    }
    printf(first? "Monocarp\n":"Bicarp\n");
 
}
/*
    Good Luck
        -Lucina
*/