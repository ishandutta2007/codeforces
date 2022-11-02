#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)

int a2[1000][1000],a5[1000][1000],d2[1000][1000],d5[1000][1000],ans2[1000][1000],ans5[1000][1000];

char as[2000];

int min(int x,int y){
    return x>y?x:y;
}

int mod(int x){
    return x<0?x*(-1):x;
}

void solve(int n){
    int i,j,t,i0=-1;
    For(i,n){
        For(j,n){
            a5[i][j]=0;
            a2[i][j]=0;
            scanf("%d",&t);
            if(t!=0){
                while(t%2==0){
                    a2[i][j]++;
                    t/=2;
                }
                while(t%5==0){
                    a5[i][j]++;
                    t/=5;
                }
            }
            else{
                i0=j;
                a2[i][j]=a5[i][j]=-1;
            }
        }
    }
    d2[0][0]=a2[0][0];
    d5[0][0]=a5[0][0];
    for(i=1;i<n;i++){
        if(a5[i][0]!=-1&&d5[i-1][0]!=-1){
            d5[i][0]=a5[i][0]+d5[i-1][0];
        }
        else d5[i][0]=-1;

        if(a2[i][0]!=-1&&d2[i-1][0]!=-1){
            d2[i][0]=a2[i][0]+d2[i-1][0];
        }
        else d2[i][0]=-1;

        ans2[i][0]=1;                                                   //1=='D',0=='R', i - 'D', j - 'R'
        ans5[i][0]=1;

        if(d2[0][i-1]!=-1&&a2[0][i]!=-1){
            d2[0][i]=a2[0][i]+d2[0][i-1];
        }
        else d2[0][i]=-1;

        if(d5[0][i-1]!=-1&&a5[0][i]!=-1){
            d5[0][i]=a5[0][i]+d5[0][i-1];
        }
        else d5[0][i]=-1;

        ans2[0][i]=0;
        ans5[0][i]=0;
    }
    d2[n-1][n-1]=d5[n-1][n-1]=-1;
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            if(a2[i][j]!=-1){
                if(d2[i][j-1]==-1){
                    if(d2[i-1][j]==-1){
                        d2[i][j]=-1;
                    }
                    else{
                        d2[i][j]=d2[i-1][j]+a2[i][j];
                        ans2[i][j]=1;
                    }
                }
                else{
                    if(d2[i-1][j]==-1){
                        d2[i][j]=d2[i][j-1]+a2[i][j];
                        ans2[i][j]=0;
                    }
                    else{
                        if(d2[i][j-1]<d2[i-1][j]){
                            d2[i][j]=d2[i][j-1]+a2[i][j];
                            ans2[i][j]=0;
                        }
                        else{
                            d2[i][j]=d2[i-1][j]+a2[i][j];
                            ans2[i][j]=1;
                        }
                    }
                }
            }
            else{
                d2[i][j]=-1;
                ans2[i][j]=1;
            }
            if(a5[i][j]!=-1){
                if(d5[i][j-1]==-1){
                    if(d5[i-1][j]==-1){
                        d5[i][j]=-1;
                    }
                    else{
                        d5[i][j]=d5[i-1][j]+a5[i][j];
                        ans5[i][j]=1;
                    }
                }
                else{
                    if(d5[i-1][j]==-1){
                        d5[i][j]=d5[i][j-1]+a5[i][j];
                        ans5[i][j]=0;
                    }
                    else{
                        if(d5[i][j-1]<d5[i-1][j]){
                            d5[i][j]=d5[i][j-1]+a5[i][j];
                            ans5[i][j]=0;
                        }
                        else{
                            d5[i][j]=d5[i-1][j]+a5[i][j];
                            ans5[i][j]=1;
                        }
                    }
                }
            }
            else{
                d5[i][j]=-1;
                ans5[i][j]=1;
            }
        }
    }
    if(d2[n-1][n-1]==0){
        i=j=n-1;
        while(i!=0||j!=0){
            if(ans2[i][j]==1){
                as[i+j]='D';
                    i--;
            }
            else{
                as[i+j]='R';
                j--;
            }
        }   
        printf("%d\n",mod(d2[n-1][n-1]));
    }
    else{
        if(d5[n-1][n-1]==0){
            i=j=n-1;
            while(i!=0||j!=0){
                if(ans5[i][j]==1){
                    as[i+j]='D';
                    i--;
                }
            else{
                    as[i+j]='R';
                    j--;
                }
            }
            printf("%d\n",mod(d5[n-1][n-1]));
        }
        else{
            if(i0==-1){
                if(d2[n-1][n-1]<d5[n-1][n-1]){
                    i=j=n-1;
                    while(i!=0||j!=0){
                        if(ans2[i][j]==1){
                            as[i+j]='D';
                            i--;
                        }
                        else{
                            as[i+j]='R';
                            j--;
                        }
                    }   
                    printf("%d\n",mod(d2[n-1][n-1]));
                }
                else{
                    i=j=n-1;
                    while(i!=0||j!=0){
                        if(ans5[i][j]==1){
                            as[i+j]='D';
                            i--;
                        }
                        else{
                            as[i+j]='R';
                            j--;
                        }
                    }
                    printf("%d\n",mod(d5[n-1][n-1]));
                }
            }
            else{
                j=1;
                for(i=1;i<i0+1;j++){
                    as[j]='R';
                    i++;
                }
                for(i=1;i<n;j++){
                    as[j]='D';
                    i++;
                }
                for(j=j;j<2*n-1;j++){
                    as[j]='R';
                }
                printf("1\n");
            }
        }
    }
    for(i=1;i<2*n-1;i++){
        printf("%c",as[i]);
    }
    
}

int main() {
#pragma comment(linker, "/STACK:67108864") 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    while(scanf("%d",&n)!=EOF){
    solve(n);
    }
    return 0;
}