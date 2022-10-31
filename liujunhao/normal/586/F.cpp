#include<cstdio>
#include<algorithm>
#include<map>
#define MAXN 25
using namespace std;
typedef pair<int,int>pii;
pair<pii,pii>state[1594323+10];
pii rf[4]={make_pair(0,0),make_pair(1,2),make_pair(1,3),make_pair(2,3)},ans;
int cnt,n,a[MAXN+10][4],pow[15]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969},ansl=0x80000000;
void Read(int &x){
    char c;
    bool f=0;
    while(c=getchar(),c!=EOF){
        if(c=='-')
            f=1;
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            if(f)
                x=-x;
            return;
        }
    }
}
void dfs1(int i,int up,int s,int l,int m,int w){
    if(i>up){
        state[++cnt]=make_pair(make_pair(m-l,w-m),make_pair(l,s));
        return;
    }
    dfs1(i+1,up,s,l+a[i][1],m+a[i][2],w);
    dfs1(i+1,up,s+1*pow[i-1],l+a[i][1],m,w+a[i][3]);
    dfs1(i+1,up,s+2*pow[i-1],l,m+a[i][2],w+a[i][3]);
}
pair<pii,pii>ts;
void dfs2(int i,int down,int s,int l,int m,int w){
    if(i==down){
        pii t=make_pair(l-m,m-w);
        int j=upper_bound(state+1,state+cnt+1,make_pair(t,make_pair(0x7fffffff,0x7fffffff)))-state-1;
        if(t==state[j].first){
            if(ansl<state[j].second.first+l)
                ansl=state[j].second.first+l,ans=make_pair(state[j].second.second,s);
        }
        return;
    }
    dfs2(i-1,down,s,l+a[i][1],m+a[i][2],w);
    dfs2(i-1,down,s+1*pow[n-i],l+a[i][1],m,w+a[i][3]);
    dfs2(i-1,down,s+2*pow[n-i],l,m+a[i][2],w+a[i][3]);
}
char pf[3][3]={{'L','M'},{'L','W'},{'M','W'}};
int main()
{
    
    int i,j;
    Read(n);
    for(i=1;i<=n;i++)
        for(j=1;j<=3;j++)
            Read(a[i][j]);
    dfs1(1,n/2,0,0,0,0);
    sort(state+1,state+cnt+1);
    dfs2(n,n/2,0,0,0,0);
    j=n/2;
    if(ansl==(int)0x80000000){
        puts("Impossible");
        return 0;
    }
    for(i=1;i<=j;i++)
        puts(pf[ans.first%pow[i]/pow[i-1]]);
    for(i=j+1;i<=n;i++)
        puts(pf[ans.second%pow[n-i+1]/pow[n-i]]);
}