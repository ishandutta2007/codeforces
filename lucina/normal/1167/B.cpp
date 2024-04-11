#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[7],x,b[7]={0,4,8,15,16,23,42};

int main(){
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d",&x);
    bool ch=false;
    for(int i=1;i<=6;i++){
        for(int j=i+1;j<=6;j++){
            if(b[i]*b[j]==x){
                a[1]=b[i];
                a[2]=b[j];
                ch=true;
                break;
            }
        }
        if(ch)
            break;
    }
    ch=false;
    printf("? 1 3\n");
    fflush(stdout);
    scanf("%d",&x);
    for(int i=1;i<=6;i++){
        for(int j=i+1;j<=6;j++){
            if(b[i]*b[j]==x){
                if(b[i]==a[1]||b[i]==a[2]){
                    a[3]=b[j];
                    if(b[i]!=a[1])
                        swap(a[1],a[2]);
                }
                else{
                    a[3]=b[i];
                    if(b[j]!=a[1]){
                        swap(a[1],a[2]);
                    }
                }
                ch=true;
                break;
            }
        }
        if(ch)break;
    }
    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d",&x);
     ch=false;;
    for(int i=1;i<=6;i++){
        for(int j=i+1;j<=6;j++){
            if(b[i]*b[j]==x){
                a[4]=b[i];
                a[5]=b[j];
                ch=true;
                break;
            }
        }
        if(ch)
            break;
    }
    ch=false;
    printf("? 4 6\n");
    fflush(stdout);
    scanf("%d",&x);
    for(int i=1;i<=6;i++){
        for(int j=i+1;j<=6;j++){
            if(b[i]*b[j]==x){
                if(b[i]==a[4]||b[i]==a[5]){
                    a[6]=b[j];
                    if(b[i]!=a[4])
                        swap(a[4],a[5]);
                }
                else{
                    a[6]=b[i];
                    if(b[j]!=a[4]){
                        swap(a[4],a[5]);
                    }
                }
                ch=true;
                break;
            }
        }
        if(ch)break;
    }
    printf("! ");
    for(int i=1;i<=6;i++)
        printf("%d ",a[i]);
    printf("\n");
    fflush(stdout);
}