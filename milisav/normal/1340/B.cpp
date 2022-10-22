#include<bits/stdc++.h>
#define maxn 2500
using namespace std;
int n,k;
char s[maxn][8];
int a[maxn];
char digs[10][8]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int nums[10];
bool pos[maxn][maxn];
int convert(char* s) {
    int m=7;
    int t=0;
    for(int i=0;i<m;i++) {
        t<<=1;
        if(s[i]=='1') t|=1;
    }
    return t;
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<10;i++) nums[i]=convert(digs[i]);
    for(int i=0;i<n;i++) {
        scanf("%s",s[i]);
        a[i]=convert(s[i]);
    }
    for(int i=0;i<10;i++) {
        if((nums[i]|a[n-1])==nums[i]) {
            pos[n-1][__builtin_popcount(a[n-1]^nums[i])]=true;
        }
    }
    pos[n][0]=true;
    for(int i=n-2;i>=0;i--) {
        for(int t=0;t<10;t++) {
            if((nums[t]|a[i])!=nums[t]) continue;
            int r=__builtin_popcount(a[i]^nums[t]);
            for(int j=r;j<=k;j++) pos[i][j]=pos[i][j]||pos[i+1][j-r];
        }
    }
    if(!pos[0][k]) {
        printf("-1");
        return 0;
    }
    for(int i=0;i<n;i++) {
        int bv=-1;
        for(int t=9;t>=0;t--) {
            if((nums[t]|a[i])!=nums[t]) continue;
            int r=__builtin_popcount(a[i]^nums[t]);
            if(r<=k && pos[i+1][k-r]) {
                bv=t;
                k-=r;
                break;
            }
        }
        printf("%d",bv);
    }
	return 0;
}