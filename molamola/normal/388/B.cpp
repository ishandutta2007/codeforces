
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

bool edge[1010][1010];
int num;
void add(int s,int e){edge[s][e] = edge[e][s] = 1;}

void add_path(int s,int e,int x)
{
    int a[10];
    for(int i=0;i<x;i++)a[i] = ++num;
    for(int i=0;i<x;i++)add(s,a[i]), add(a[i],e);
}

int p[30];

int main()
{
    int n, i, j;
    scanf("%d",&n);
    num = 2;
    int tmp = n, cnt = 0;
    while(n){
        cnt++;
        p[cnt] = n%4;
        n/=4;
    }
    for(i=1;i<=cnt;i++){
        tmp = ++num;
        add_path(1,tmp,p[i]);
        for(j=0;j<i-1;j++){
            int nxt = ++num;
            add_path(tmp,nxt,4);
            tmp = nxt;
        }
        for(j=0;j<16-i;j++){
            int nxt;
            if(j == 15-i)nxt = 2;
            else nxt = ++num;
            add_path(tmp,nxt,1);
            tmp = nxt;
        }
    }
    printf("%d\n",num);
    for(i=1;i<=num;i++){
        for(j=1;j<=num;j++)printf("%c",edge[i][j]?'Y':'N');
        puts("");
    }
    return 0;
}