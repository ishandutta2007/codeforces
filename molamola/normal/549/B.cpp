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

int n;
char ch[105][105];
int a[105], b[105];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",ch[i]);
    for(int i=0;i<n;i++)scanf("%d",a+i), b[i] = a[i];
    vector <int> ans;
    for(int i=0;i<n;i++){
        int f = -1;
        for(int j=0;j<n;j++){
            if(b[j] == 0){f = j; break;}
        }
        if(f == -1)break;
        ans.pb(f+1);
        for(int j=0;j<n;j++){
            if(ch[f][j] == '1')b[j]--;
        }
    }
    printf("%d\n", sz(ans));
    for(auto i : ans)printf("%d ", i);
    return 0;
}