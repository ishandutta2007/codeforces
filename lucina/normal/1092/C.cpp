#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,ma,ma1,x,c,d,l;
char s[210][210];
int a[210];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=201;i++)
        a[i]=-1;
    for(int i=1;i<=2*n-2;i++){
        scanf("%s",s[i]);
        if(strlen(s[i])==n-1){
            if(c==0)
                c=i;
            else
                d=i;
        }
    }
    for(int i=1;i<=n-2;i++){
        if(s[c][i]!=s[d][i-1]){
            swap(c,d);
            break;
        }
    }
    bool fuck=true;
    for(int i=1;i<=2*n-2;i++){
            fuck=true;
            l=strlen(s[i]);
        for(int j=0;j<l;j++){
            if(s[i][j]!=s[c][j]){
            fuck=false;
            break;
            }
        }
        if(fuck)
            a[i]=1;
        fuck=true;
        for(int j=0;j<l;j++){
            if(s[i][l-1-j]!=s[d][n-2-j])
                fuck=false;
                break;
        }
        if(fuck){
            if(a[i]==1)
                a[i]=2;
            else
                a[i]=0;
        }
    }
    fuck=false;
    for(int i=1;i<=2*n-2;i++){
        if(a[i]==-1)
            fuck=true;
        }
    if(fuck){
        swap(c,d);
        for(int i=1;i<=201;i++)
        a[i]=-1;
        for(int i=1;i<=2*n-2;i++){
            fuck=true;
            l=strlen(s[i]);
        for(int j=0;j<l;j++){
            if(s[i][j]!=s[c][j]){
            fuck=false;
            break;
            }
        }
        if(fuck)
            a[i]=1;
        fuck=true;
        for(int j=0;j<l;j++){
            if(s[i][l-1-j]!=s[d][n-2-j])
                fuck=false;
                break;
        }
        if(fuck){
            if(a[i]==1)
                a[i]=2;
            else
                a[i]=0;
        }
    }
    }
    for(int i=1;i<=2*n-2;i++){
        for(int j=i+1;j<=2*n-2;j++){
            if(strlen(s[i])==strlen(s[j])){
                if(a[i]==a[j]){
                    if(a[i]==2)
                        a[i]=1,a[j]=0;
                        break;
                }
                else{
                    if(a[i]==2){
                        a[i]=abs(a[j]-1);
                        break;
                        }
                    if(a[j]==2){
                        a[j]=abs(a[i]-1);
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=2*n-2;i++){
        if(a[i])
            printf("P");
        else
            printf("S");
    }
}