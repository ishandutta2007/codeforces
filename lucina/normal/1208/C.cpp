#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[1005][1005];
bool ban[1005*1005];
int pt;
void col(int x){

}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i+=4){
        for(int j=0;j<n;j+=4){
            for(int k=0;k<4;k++)
            for(int l=0;l<4;l++)
            a[i+k][j+l]=pt++;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        printf("%d%c",a[i][j],j==n-1?'\n':' ');
}
/*
    Good Luck
        -Lucina
*/