#include<bits/stdc++.h>
#define maxn 123456

using namespace std;
int n,m,l,r;
int t=0;
char s[123];

int qry(int x,int y){
    printf("%d %d\n",x,y);
    fflush(stdout);
    scanf("%s",s);
    return s[0]=='b';
}

int main(){
    cin >> n;
    l=0; r=1<<(n-1);
    int m=qry(1,0);
    for (int i=1;i<n;i++){
        int mid=(l+r)/2;
        if (qry(1,mid)==m) l=mid; else r=mid;
    }
    printf("%d %d %d %d\n",2,l,0,r);
    return 0;
}