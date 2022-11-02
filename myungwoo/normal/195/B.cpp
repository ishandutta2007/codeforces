#include <stdio.h>

int N,M;

int main()
{
    int i,m,p,cnt=0;
    scanf("%d%d",&N,&M); m = p = (M+1)/2;
    for (i=1;i<=N;i++){
        if (M%2 == 0){
            cnt++;
            if (cnt&1){
                printf("%d\n",p);
            }else{
                printf("%d\n",p+cnt-1);
                p--;
                if (!p) p = m, cnt = 0;
            }
        }else{
            cnt++;
            if (cnt <= 1){
                printf("%d\n",p); p--;
                if (!p) p = m, cnt = 0;
            }else{
                if (cnt&1){
                    printf("%d\n",p+cnt-1);
                    p--;
                    if (!p) p = m, cnt = 0;
                }else{
                    printf("%d\n",p);
                }
            }
        }
    }
}