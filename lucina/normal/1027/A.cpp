#include<bits/stdc++.h>
using namespace std;
int t,n;
char s[500];
pair<int,int> a,b;
pair<int,int> mc(char x){
    if(x=='a'){
        return {-77,2};
    }
    if(x=='z'){
        return {-88,25};
    }
    return {x-'a',x-'a'+2};
}
/*12321*/
int main(){
    bool ch=true;
    scanf("%d",&t);
    while(t--){
        scanf("%d %s",&n,s+1);
        ch=true;
        for(int i=1;i<=n/2;i++){
            a=mc(s[i]);b=mc(s[n+1-i]);
            if(a.first==b.first||a.first==b.second||a.second==b.first||a.second==b.second)
            ;
            else{
                ch=false;
                break;
            }
        }
        printf(ch?"YES\n":"NO\n");
    }
    
}