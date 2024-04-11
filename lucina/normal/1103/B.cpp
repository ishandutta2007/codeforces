#include<bits/stdc++.h>
using namespace std;
char s[30];
string f;
char d;
long long p[35],x,y,a,b,id,l,r,mid,g;
int main(){
    p[0]=1;
    for(int i=1;i<=32;i++)
        p[i]=p[i-1]<<1;
    while(true){
        scanf("%s",s);
        f=string(s);
        if(f=="end"||f=="mistake"){
            return 0;
        }
        for(int i=0;i<=31;i++){
            printf("? %lld %lld\n",p[i],p[i+1]);
            fflush(stdout);
            scanf("%s",s);
            if(s[0]=='x'){
                id=i;
                break;
            }
        }
        l=p[id],r=p[id+1];
        g=l-1;
        while(l<=r){
            mid=(l+r)>>1;
            printf("? %lld %lld\n",g,mid);
            fflush(stdout);
            scanf("%s",s);
            if(s[0]=='x'){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        printf("! %d\n",l);
        fflush(stdout);
    }

}