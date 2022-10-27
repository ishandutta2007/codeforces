#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10,mod = 1e9+7;
void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,long long b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}
int n,k;
int ans,ncr[350][350];
using ll = long long;

int main(){
    ncr[0][0] = 1;
    for(int i=1;i<=300;i++){
        for(int j=0;j<=i;j++){
            if(j == 0 || j ==i) {ncr[i][j]  =1 ;continue;}
            ncr[i][j] = add(ncr[i-1][j],ncr[i-1][j-1]);;
        }
    }
    scanf("%d%d",&n,&k);
    if(k == 1)return !printf("1");
    ans = 0;
    int ans1 = 0;
    int tominus = 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int cur = mul(ncr[n][i],ncr[n][j]);
            cur = mul(cur,power(k-1,(ll)(n * n - ( (n -i) * (n - j)))));
            cur = mul(cur,power(k, (ll)( (n-i) * (n - j) ) ) );
            if((i + j) % 2){
            minun(ans,cur);
            plusle(ans1,cur);
            }
            else{
                plusle(ans,cur);
                minun(ans1,cur);
            }
        }
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/