#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char x[7][4],s[maxn];
int n;
int main(){
    x[1][0]='R',x[1][1]='G',x[1][2]='B';
    x[2][0]='R',x[2][1]='B',x[2][2]='G';
    x[3][0]='G',x[3][1]='R',x[3][2]='B';
    x[4][0]='G',x[4][1]='B',x[4][2]='R';
    x[5][0]='B',x[5][1]='R',x[5][2]='G';
    x[6][0]='B',x[6][1]='G',x[6][2]='R';
    scanf("%d",&n);
    scanf("%s",s);
    int sum=0,ans=1e9,ans1=1e9;
    for(int i=1;i<=6;i++){
            sum=0;
        for(int j=0;s[j]!='\0';j++){
            if(s[j]!=x[i][j%3]){
                sum++;
            }
        }
        if(sum<ans){
            ans=sum;
            ans1=i;
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++){
        printf("%c",x[ans1][i%3]);
    }
}