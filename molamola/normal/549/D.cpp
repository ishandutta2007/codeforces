#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

char ch[105][105];
int a[105][105];
int n, m;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",ch[i]);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)a[i][j] = (ch[i][j] == 'W' ? 1 : -1);
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(a[i][j] != 0){
                for(int k=0;k<=i;k++)for(int u=0;u<=j;u++)a[k][u] -= a[i][j];
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}