#include <bits/stdc++.h>
#define inf 987654321
using namespace std;
typedef long long LL;


int n;
LL m, sum;
int ans[200010], timenum[110];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        LL input, tempsum=sum;
        scanf("%lld", &input);
        sum+=input;
        if(tempsum+input<=m){
            timenum[input]++;
            continue;
        }
        for(LL j=100; j>=1; j--){
            if(!timenum[j])continue;
            int sub;
            if((tempsum-m+input)%j)sub=(tempsum-m+input)/j+1;
            else sub=(tempsum-m+input)/j;
            if(sub>timenum[j]){
                ans[i]+=timenum[j];
                tempsum-=j*timenum[j];
            }
            else{
                ans[i]+=sub;
                break;
            }
        }
        timenum[input]++;
    }
    for(int i=1; i<=n; i++){
        printf("%d ", ans[i]);
    }
}