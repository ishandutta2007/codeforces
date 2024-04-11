#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,pl,cnt,arr[7]={1,2,3,1,3,2,1};

int main(){
    scanf("%lld %lld %lld",&a,&b,&c);
    cnt = min({a/3, b/2, c/2});

    for(int i=0;i<7;i++){
        ll aa=a-cnt*3,bb=b-cnt*2,cc=c-cnt*2,j=i,cn=0;

        while(aa>=0 && bb>=0 && cc>=0){
            if(arr[j] == 1){
                if(aa == 0) break;
                aa--;
            }else if(arr[j] == 2){
                if(bb == 0) break;
                bb--;
            }else if(arr[j] == 3){
                if(cc == 0) break;
                cc--;
            }
            j=(j+1)%7;
            cn++;
        }
        pl=max(pl,cn);
    }

    printf("%lld",cnt*7+pl);
}