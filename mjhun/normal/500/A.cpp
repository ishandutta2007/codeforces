#include <cstdio>

int main(){
    int n,t,a,p=0;
    scanf("%d %d",&n,&t);t--;
    for(int i=0;i<n-1&&p<t;++i){
        scanf("%d", &a);
        if(i==p){
            p+=a;
        }
    }
    puts(p==t?"YES":"NO");
}