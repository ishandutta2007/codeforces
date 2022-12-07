#include <cstdio>
#include <algorithm>
using namespace std;
const long long MOD = 1000000007,N=100010;
int pow(int a,int b){
    if(b==0) return 1;
    if(b==1) return a;
    long long re=pow(a,b/2);re=(re*re)%MOD;
    if(b%2) re=(re*a)%MOD;
    return re;
}
int cou[100]={0};
char cha[N];
int main(){
    int n,m,ac=0;
    scanf("%d",&n);
    scanf("%s",cha);
    for(int i=0;i<n;i++) cou[cha[i]]++;
    m=max(max(cou['A'],cou['G']),max(cou['C'],cou['T']));
    if(cou['A']==m) ac++;
    if(cou['G']==m) ac++;
    if(cou['C']==m) ac++;
    if(cou['T']==m) ac++;
    printf("%d\n",pow(ac,n));
    return 0;
}