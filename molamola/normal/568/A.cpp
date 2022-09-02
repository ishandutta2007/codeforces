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

const int MX = 1e7;

int pl[MX+10];
int pr[MX+10];

bool chk(int x){
    int t = 0, y = x;
    while(y){
        t = (t<<3) + (t<<1) + y % 10;
        y /= 10;
    }
    return x == t;
}

int main(){
    pr[0] = pr[1] = 1;
    for(int i=2;i<=MX + 5;i++){
        if(!pr[i]){
            if((ll)i * i <= MX + 5)for(int j=i*i;j<=MX+5;j+=i)pr[j] = 1;
        }
    }
    for(int i=0;i<=MX+5;i++)pr[i] = !pr[i];
    for(int i=1;i<=MX+5;i++)pr[i] += pr[i-1];
    for(int i=1;i<=MX+5;i++)pl[i] = pl[i-1] + chk(i);
    int p, q; scanf("%d%d",&p,&q);
    int i;
    for(i=MX+4;i;i--){
        if((ll)pr[i] * q <= (ll)pl[i] * p){
            printf("%d\n", i);
            break;
        }
    }
    if(i == -1)printf("Palindromic tree is better than splay tree");
    return 0;
}