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

char ch[1000010];
int prev[1000010];
int ans[100010];
vector <int> v;

struct str{
    str(){}
    str(int x,int l,int r):x(x),l(l),r(r){}
    int x, l, r;
    bool operator<(const str &L)const{
        return r<L.r;
    }
}inp[100010];

struct tree{
    int T[1000010];
    void update(int x){
        for(int i=x;i;i-=(i&-i))T[i]++;
    }
    int read(int x){
        int ret = 0;
        for(int i=x;i<1000010;i+=(i&-i))ret += T[i];
        return ret;
    }
}Tr;

int main()
{
    scanf("%s",ch+1);
    int n = strlen(ch+1);
    int i, now = 0;
    for(i=1;i<=n;i++){
        if(ch[i] == '(')v.push_back(i), now++;
        else if(now != 0){
            now--;
            int t = v.back(); v.pop_back();
            prev[i] = t;
        }
    }
    //for(i=1;i<=n;i++)printf("%d ",prev[i]);
    int m;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        inp[i] = str(i, x, y);
    }
    sort(inp+1,inp+1+m);
    now = 1;
    for(i=1;i<=n;i++){
        if(prev[i])Tr.update(prev[i]);
        while(now != m+1 && inp[now].r == i){
            ans[inp[now].x] = Tr.read(inp[now].l);
            now++;
        }
    }
    for(i=1;i<=m;i++)printf("%d\n",2*ans[i]);
    return 0;
}