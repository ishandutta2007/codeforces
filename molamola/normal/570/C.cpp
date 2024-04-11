#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define rep0(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rep(i,x,y) for(int i=x;i<y;i++)
#define pb(x) push_back(x)

typedef long long ll;

char c[300030];
int ans;

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    scanf("%s",c);
    int now = 0;
    for(int i=0;c[i];i++){
        if(c[i] == '.'){
            ++now;
            if(now >= 2)ans++;
        }
        else now = 0;
    }
    for(int i=0;i<m;i++){
        char ch[3];
        int x;
        scanf("%d%s", &x, ch); --x;
        int cnt = 0;
        if(ch[0] == '.' && c[x] != '.'){
            if(x >= 0 && c[x-1] == '.')cnt++;
            if(c[x+1] && c[x+1] == '.')cnt++;
            ans += cnt;
        }
        else if(ch[0] != '.' && c[x] == '.'){
            if (x >= 0 && c[x - 1] == '.')cnt++;
            if (c[x + 1] && c[x + 1] == '.')cnt++;
            ans -= cnt;
        }c[x] = ch[0];
        printf("%d\n",ans);
    }
    return 0;
}