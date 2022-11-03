#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000005
#define maxc 26
#define ll long long

int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}
int f[maxn][maxc],g[maxn][maxc],P,i,j;
char s1[maxn],s2[maxn];
ll ans,N,M,l;

int main(){
	scanf("%I64d%I64d%s%s",&N,&M,&s1,&s2);
	P=gcd(strlen(s1),strlen(s2));
	for(;s1[i];++i)f[i%P][s1[i]-'a']++;
	for(;s2[j];++j)g[j%P][s2[j]-'a']++;
	ans=(ll)i*j/P;
	l=(ll)N*P/j;
	for(i=0;i<=P-1;++i)for(j=0;j<26;++j)ans-=(ll)f[i][j]*g[i][j];
	ans*=l;
	printf("%I64d\n",ans);
}