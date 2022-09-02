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

int p[5050], C[1000010];
int chk[1000010];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++)scanf("%d",p+i);
    sort(p+1,p+1+n);
    for(i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)chk[p[j]-p[i]]++;
    }
    for(i=1;i<=1e6+5;i++){
        int counter = 0;
        int j;
        for(j=i;j<=1e6+5;j+=i)counter += chk[j];
        if(counter > k*(k+1)/2)continue;
        counter = 0;
        for(j=1;j<=n;j++){
            if(C[p[j]%i] == i)counter ++;
            else C[p[j]%i] = i;
        }
        if(counter <= k){printf("%d",i);break;}
    }
    return 0;
}