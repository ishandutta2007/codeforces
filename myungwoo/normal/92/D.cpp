#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define N 100005

typedef struct _walrus{
    int idx, agee;
    bool const operator<(const _walrus &r)const{
        return agee < r.agee;
    }
}walrus;
walrus list[N];
int age[N], a, n, ag[N], tree[N], ans[N];

int main(void){
    int i, j;
    scanf("%d", &n);
    for(i=1; i<=n; i++){ scanf("%d", &ag[i]), age[i] = ag[i]; list[i].agee = age[i], list[i].idx = i;}
    sort(list+1, list+n+1);
    int mx = 0;
    for(i=1; i<=n;){
        int tmx = 0;
        for(j=i; list[j].agee == list[i].agee && j<=n; j++){
            if(list[j].idx > tmx) tmx = list[j].idx;
            if(list[j].idx > mx) ans[list[j].idx] = -1;
            else ans[list[j].idx] = mx - list[j].idx - 1;
        }
        if(tmx > mx) mx = tmx;
        i = j;
    }
    for(i=1; i<=n; i++) printf("%d ", ans[i]);
    return 0;
}