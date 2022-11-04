#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[4][4]={
    {8, 9, 1, 13},
    {3, 12, 7, 5},
    {0, 2, 4, 11},
    {6, 10, 15, 14}
};
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i%4][j%4] + 16 * ((i/4)*n/4 + (j/4)));
        }
        puts("");
    }
}