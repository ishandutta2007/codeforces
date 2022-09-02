#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<map>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

map <int,int> M;
int p[100010];
int ans[100010];

int main()
{
    int n, a, b;
    scanf("%d%d%d",&n,&a,&b);
    int sp = 0;
    if(a > b){
        sp = 1;swap(a,b);
    }
    int i;
    for(i=0;i<n;i++){scanf("%d",p+i);
        M[p[i]] = i+1;
    }
    while(!M.empty()){
        map <int,int>::iterator it, jt, kt;
        it = M.end();
        --it;
        jt = M.begin();
        if(*it == *jt){if(it->X*2 == b)ans[it->Y] = 1;else if(it->X*2 != a){printf("NO");return 0;}break;}
        else if(a == b){
            if(it->X + jt->X == a){
                M.erase(it);
                M.erase(jt);
            }
            else{printf("NO");return 0;}
        }
        else if(a - it->X < jt->X){
            kt = M.find(-it->X+b);
            if(kt == M.end()){
                printf("NO");return 0;
            }
            ans[kt->Y] = ans[it->Y] = 1;
            if(kt!=it)M.erase(kt),M.erase(it);else M.erase(kt);
        }
        else if(b - jt->X > it->X){
            kt = M.find(-jt->X+a);
            if(kt == M.end()){
                printf("NO");return 0;
            }
            ans[kt->Y] = ans[jt->Y] = 0;
            if(kt!=jt)M.erase(kt),M.erase(jt);
            else M.erase(jt);
        }
        else{printf("NO");return 0;}
    }
    printf("YES\n");
    for(i=1;i<=n;i++){
        printf("%d ",ans[i]^sp);
    }
    return 0;
}