# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
const int N = 2000;
int c[N], cnt, a[N], b[N], n, pos, head[N], blg, ord;
bool f[N], ans[N];

void solve(const int k)
{
    memset(f,0,sizeof(f));
    f[0] = true;
    
    for(int i=0; i<cnt; i++)
        if(i!=k)
            for(int j=n-c[i];j>=0;j--)
                if(f[j])f[j+c[i]]=true;
    for(int i=head[k]; i; i=b[i])
    {
        ord++;
        if(i==pos)break;
    }
    for(int i=0; i<=n; i++)
        if(f[i])
            ans[i+ord]=true;
}

void init()
{
    scanf("%d%d",&n,&pos);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        b[a[i]]=i;
    }
    
    for(int i=1;i<=n;i++)
        if(b[i]==0)
        {
            int j;
            c[cnt]=1;
            for(j=i; a[j]; j=a[j])
            {
                if(j==pos)
                    blg = cnt;
                c[cnt]++;
            }

            if(j==pos)
                blg = cnt;

            head[cnt]=j;
            cnt++;
        }
}

void output()
{
    for(int i=1; i<=n; i++)
        if(ans[i]) printf("%d\n",i);
}

int main()
{
    init();
    solve(blg);
    output();
//    while(1);
}