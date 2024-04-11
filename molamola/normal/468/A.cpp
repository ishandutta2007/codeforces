#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int n;
int pm[100010];

int main()
{
//  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    if(n <= 3){printf("NO");return 0;}
    if(n == 4){printf("YES\n4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24");return 0;}
    if(n == 5){
        printf("YES\n5 * 4 = 20\n2 - 1 = 1\n20 + 1 = 21\n21 + 3 = 24\n");return 0;
    }
    if(n == 6){
        printf("YES\n6 * 5 = 30\n30 + 2 = 32\n32 - 1 = 31\n31 - 3 = 28\n28 - 4 = 24\n");return 0;
    }
    printf("YES\n");
    int i;
    ll s = 0;
    for(i=1;i<=n;i++)s += i;
    if(s % 2){
        printf("%d - %d = %d\n",n,n-1,1);
        printf("1 * 1 = 1\n");
        s -= n, s -= n-1;
        n -= 2;
    }
    ll a = (s - 24) / 2;
    for(i=n;i;i--){
        if(a >= i)pm[i] = -1, a -= i;
    }
    //for(i=1;i<=n;i++)printf("%d ",pm[i]);
    vector <int> v1,v2;
    for(i=1;i<=n;i++)if(pm[i] == -1)v1.push_back(i);else v2.push_back(i);
    for(i=0;i<v1.size();i++){
        printf("%d - %d = %d\n",v2[i],v1[i],v2[i]-v1[i]);
        v2[i] -= v1[i];
    }
    for(i=0;i<(int)v2.size() - 1;i++){
        printf("%d + %d = %d\n",v2[i],v2[i+1],v2[i]+v2[i+1]);
        v2[i+1] += v2[i];
    }
    return 0;
}