#include<cstdio>
#define MXAN 100
int a[2],b[2],c[2];
int main()
{
    int i,j,k,l,m;
    scanf("%d%d%d%d%d%d",&a[0],&a[1],&b[0],&b[1],&c[0],&c[1]);
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++){
                if(a[i]==b[j]&&a[i]==c[k]&&a[1^i]+b[1^j]+c[1^k]==a[i]){
                    printf("%d\n",a[i]);
                    for(l=1;l<=a[1^i];l++){
                        for(m=1;m<=a[i];m++)
                            printf("A");
                        puts("");
                    }
                    for(l=1;l<=b[1^j];l++){
                        for(m=1;m<=a[i];m++)
                            printf("B");
                        puts("");
                    }
                    for(l=1;l<=c[1^k];l++){
                        for(m=1;m<=a[i];m++)
                            printf("C");
                        puts("");
                    }
                    return 0;
                }
            }
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++){
                if(a[i]+b[j]==c[k]&&b[1^j]==a[1^i]&&a[1^i]+c[1^k]==c[k]){
                    printf("%d\n",c[k]);
                    for(l=1;l<=c[1^k];l++){
                        for(m=1;m<=c[k];m++)
                            printf("C");
                        puts("");
                    }
                    for(l=1;l<=a[1^k];l++){
                        for(m=1;m<=a[i];m++)
                            printf("A");
                        for(m=1;m<=b[j];m++)
                            printf("B");
                        puts("");
                    }
                    return 0;
                }
                if(b[j]+c[k]==a[i]&&b[1^j]==c[1^k]&&b[1^j]+a[1^i]==a[i]){
                    printf("%d\n",a[i]);
                    for(l=1;l<=a[1^i];l++){
                        for(m=1;m<=a[i];m++)
                            printf("A");
                        puts("");
                    }
                    for(l=1;l<=b[1^j];l++){
                        for(m=1;m<=b[j];m++)
                            printf("B");
                        for(m=1;m<=c[k];m++)
                            printf("C");
                        puts("");
                    }
                    return 0;
                }
                if(a[i]+c[k]==b[j]&&a[1^i]==c[1^k]&&a[1^i]+b[1^j]==b[j]){
                    printf("%d\n",b[j]);
                    for(l=1;l<=b[1^j];l++){
                        for(m=1;m<=b[j];m++)
                            printf("B");
                        puts("");
                    }
                    for(l=1;l<=a[1^i];l++){
                        for(m=1;m<=a[i];m++)
                            printf("A");
                        for(m=1;m<=c[k];m++)
                            printf("C");
                        puts("");
                    }
                    return 0;
                }
            }
    puts("-1");
}