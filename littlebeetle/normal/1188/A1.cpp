#include<cstdio>
const int N=1000002;
int n,a,b,i,s[N];
int main(){
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        s[a]++;
        s[b]++;
    }
    for(i=1;i<=n;i++)
    if(s[i]==2){
        printf("NO");
        return 0;
    }
    printf("YES");
}