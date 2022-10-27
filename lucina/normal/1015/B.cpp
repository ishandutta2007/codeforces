#include<stdio.h>
#include<algorithm>
using namespace std;
int a[50000],n,l;
char s[200],t[200];
int main(){
    int sum=0;
    scanf("%d %s %s",&n,s,t);
    for(int i=0;s[i]!='\0';i++){
        a[s[i]]++,a[t[i]]--;
    }
    for(int i='a';i<='z';i++){
        if(a[i]!=0){
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            for(int j=i+1;j<n;j++){
                if(s[j]==t[i]){
                    for(int k=j;k>i;k--){
                        swap(s[k],s[k-1]);
                        a[sum++]=k;
                    }
                    break;
                }
            }
        }
    }
    printf("%d\n",sum);
    for(int i=0;i<sum;i++)
        printf("%d ",a[i]);
}