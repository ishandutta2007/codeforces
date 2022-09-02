#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

long long solve(long long x,long long y){
    if(y==0)return 0;
    return x/y+solve(y,x%y);
}

int main()
{
//  freopen("input.txt","r",stdin);
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",solve(a,b));
    return 0;
}