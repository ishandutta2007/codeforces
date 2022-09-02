
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int N;
int p[100010];
long long sum=0;

inline long long gc(long long a,long long b){return b?gc(b,a%b):a;}

void output(long long a,long long b)
{
    long long g=gc(a,b);
    a/=g;b/=g;
    printf("%lld %lld",a,b);
}

int main()
{
//  freopen("input.txt","r",stdin);
    scanf("%d",&N);
    int i;
    for(i=0;i<N;i++){scanf("%d",p+i);sum+=p[i];}
    sort(p,p+N);
    long long T = N-1;
    long long cnt=0;
    for(i=N-1;i>=0;i--,T-=2){
        cnt+=T*p[i];
    }
    sum+=2*cnt;
    output(sum,N);
    return 0;
}