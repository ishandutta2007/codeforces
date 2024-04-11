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

int n, c[2], k;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int x; scanf("%d", &x);
        c[x&1]++;
    }
    if(n == k){
        if(c[1] & 1)printf("Stannis");
        else printf("Daenerys");
    }
    else{
    if(k % 2 == 0 && (n-k) % 2 == 1){
        if(c[0] > (n-k)/2 && c[1] > (n-k)/2)printf("Stannis");
        else printf("Daenerys");
    }
    if(k % 2 == 1 && (n-k) % 2 == 0){
        if(!(c[0] > (n-k)/2))printf("Stannis");
        else printf("Daenerys");
    }
    if(k % 2 == 1 && (n-k) % 2 == 1){
        if(c[1] > (n-k)/2)printf("Stannis");
        else printf("Daenerys");
    }
    if(k % 2 == 0 && (n-k) % 2 == 0){
        printf("Daenerys");
    }}
    return 0;
}