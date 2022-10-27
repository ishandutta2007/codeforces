#include<bits/stdc++.h>
using namespace std;
int n,a[5],b;
char s1[5010],s2[5010];
vector<int> q[5];
int main(){
    scanf("%d",&n);
    scanf("%s %s",s1+1,s2+1);
    for(int i=1;i<=n;i++){
        if(s1[i]==s2[i]){
            if(s1[i]=='0')
                a[1]++,q[1].push_back(i);//00
            else
                a[2]++,q[2].push_back(i);//11
        }
        else{
            if(s1[i]=='0')
                a[3]++,q[3].push_back(i);//01
            else
                a[4]++,q[4].push_back(i);//10
        }
    }
    int x,y,k,f=n/2-a[2]-a[3];
    for(int i=0;i<=a[2];i++){
        x=f+i;
        if(x<0) continue;
        if(x>a[1])continue;
        if(x+i>n/2)continue;
        if(n/2-x-i>a[3]+a[4]) continue;
        for(int j=0;j<x;j++)
            printf("%d ",q[1][j]);
        for(int j=0;j<i;j++)
            printf("%d ",q[2][j]);
        f=n/2-x-i;
        if(f>a[3]){
            for(auto j:q[3]) printf("%d ",j),f--;
            for(int j=0;j<f;j++)
                printf("%d ",q[4][j]);
        }
        else
        for(int j=0;j<f;j++)
            printf("%d ",q[3][j]);
            return 0;
    }
    printf("-1");
}