#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,ma;
char a[4];
char base[6][5]={"ACGT","AGTC","ATCG","CGAT","CTAG","GTAC"};

int main(){
    ma=(int)1e9;
    //ios::sync_with_stdio(false);
    scanf("%d%d",&n,&m);
    char s[n+10][m+10],f[n+10][m+10],ans[n+10][m+10];
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    int sum=0,sum1=0,sum2=0,index=0;
    for(int i=0;i<6;i++){
            for(int j=0;j<4;j++)a[j]=base[i][j];
            sum=0,sum1=0,sum2=0,index=0;
            for(int j=0;j<n;j++){
                    sum1=0,sum2=0;
                for(int k=0;k<m;k++){
                    index=(j&1)?0:2;index+=((k&1));
                    if(s[j][k]!=a[index])sum1++;
                    index-=(k&1);index+=((k+1)&1);
                    if(s[j][k]!=a[index])sum2++;
                    }
                if(sum1<=sum2) for(int k=0;k<m;k++)f[j][k]=a[(k&1)+((j&1)?0:2)];
                else for(int k=0;k<m;k++)f[j][k]=a[((k+1)&1)+(j&1?0:2)];
                sum+=sum1<sum2?sum1:sum2;
            }
            if(sum<ma){
                for(int j=0;j<n;j++)
                    for(int k=0;k<m;k++)ans[j][k]=f[j][k];
                ma=sum;
            }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++)a[j]=base[i][j];
        sum=0,sum1=0,sum2=0,index=0;
        for(int j=0;j<m;j++){
                sum1=0,sum2=0;
            for(int k=0;k<n;k++){
                index=(j&1)?0:2;index+=(k&1);
                if(s[k][j]!=a[index])sum1++;
                index-=(k&1);index+=((k+1)&1);
                if(s[k][j]!=a[index])sum2++;
            }
        if(sum1<=sum2) for(int k=0;k<n;k++)f[k][j]=a[(k&1)+(j&1?0:2)];
        else for(int k=0;k<n;k++)f[k][j]=a[((k+1)&1)+(j&1?0:2)];
        sum+=sum1<sum2?sum1:sum2;
    }
    if(sum<ma){
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++)ans[j][k]=f[j][k];
        ma=sum;
    }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}