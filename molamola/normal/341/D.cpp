#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

const int R=(1<<10);
long long T[2][2][R+5][R+5];

void update(int a,int b,long long l){for(int i=a;i<=R;i+=(i&-i))for(int j=b;j<=R;j+=(j&-j))T[a&1][b&1][i][j]^=l;}
long long read(int a,int b)
{
    if(!a||!b)return 0;
    long long ret=0;
    for(int i=a;i;i-=(i&-i))for(int j=b;j;j-=(j&-j))ret^=T[a&1][b&1][i][j];
    return ret;
}

int main()
{
 //   freopen("input.txt","r",stdin);
    int q;scanf("%*d%d",&q);
    while(q--){
        int t,a,b,c,d;
        scanf("%d%d%d%d%d",&t,&a,&b,&c,&d);
        if(t==2){
            long long l;scanf("%lld",&l);
            a+=2;b+=2;c+=2;d+=2;
            update(c,d,l);
            update(a-1,d,l);
            update(c,b-1,l);
            update(a-1,b-1,l);
        }
        else{
            a++,b++,c++,d++;
            printf("%lld\n",read(c,d)^read(a-1,d)^read(c,b-1)^read(a-1,b-1));
        }
    }
    return 0;
}