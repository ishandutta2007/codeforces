#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>
#include<string>
#define inf 0x3f3f3f3f
#define eps 1e-5
#define LL long long
using namespace std;
const double PI=acos(-1.0);
int main(){
    LL n,m,i,j,k;
    while(~scanf("%I64d",&n)){
        k=n/2+n/3+n/5+n/7-n/6-n/10-n/14-n/15-n/21-n/35+n/30+n/42+n/105+n/70-n/210;
        printf("%I64d\n",n-k);
    }
    return 0;
}