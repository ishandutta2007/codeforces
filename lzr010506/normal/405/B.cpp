#include <cstdio>
int main(){
    int n,last=-1,ans=0;
    bool r=false;
    char c;
    scanf("%d",&n);
    scanf("%*[\n]");
    for(int i=0;i<n;i++){
        scanf("%c",&c);
        if(c=='R'){
            if(last==-1) ans+=i;
            else ans+=i-last-1;
            r=true,last=i;
        }else if(c=='L'){
            if(last!=-1&&(i-last)%2==0) ans+=1;
            r=false,last=i;
        }
    }
    if(r==false) ans+=n-1-last;
    printf("%d\n",ans);
}