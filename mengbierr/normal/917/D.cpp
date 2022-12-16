#include <cstdio>
#include <cstring>
#include <vector>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
#define repd(i,x,y) for (int i=x; i>=y; --i)
using namespace std;
 
typedef long long LL;
const int p=1000000007;
 
int n,f[105],mtr[105][105];
bool map[105][105];
struct poly
{
    int a[105];
    poly operator+(poly t);
    poly operator*(int x)
    {
        poly ret;
        repu(i,0,n)
            ret.a[i]=LL(a[i])*x%p;
        return ret;
    }
    poly operator*(poly t)
    {
        poly ret;
        memset(ret.a,0,sizeof(ret.a));
        repu(i,0,n)
            repu(j,0,i)
                ret.a[i]=(ret.a[i]+LL(a[j])*t.a[i-j])%p;
        return ret;
    }
} ans;
 
void inc(int &x,int y)
{
    if ((x+=y)>=p)
        x-=p;
}
 
poly poly::operator+(poly t)
{
    poly ret;
    repu(i,0,n)
        inc(ret.a[i]=a[i],t.a[i]);
    return ret;
}
 
int power(int x,int k)
{
    int ret=1;
    for (; k; k>>=1,x=LL(x)*x%p)
        if (k&1)
            ret=LL(ret)*x%p;
    return ret;
}
 
void addedge(int u,int v,int w)
{
    mtr[u][u]+=w,mtr[v][v]+=w,mtr[u][v]-=w,mtr[v][u]-=w;
}
 
int gauss_elimination(int n)
{
    int ret=1;
    repu(i,1,n)
    {
        repu(j,i,n)
            if (mtr[j][i])
            {
                if (j!=i)
                {
                    repu(k,i,n)
                        swap(mtr[i][k],mtr[j][k]);
                    ret=p-ret;
                }
                break;
            }
        ret=LL(ret)*mtr[i][i]%p;
        int inv=power(mtr[i][i],p-2);
        repu(j,i,n)
            mtr[i][j]=LL(mtr[i][j])*inv%p;
        repu(j,i,n)
            if (i!=j)
                repd(k,n,i)
                    inc(mtr[j][k],p-LL(mtr[j][i])*mtr[i][k]%p);
    }
    return ret;
}
 
int calc(int x)
{
    memset(mtr,0,sizeof(mtr));
    repu(i,1,n)
        repu(j,i+1,n)
            addedge(i,j,map[i][j]?1:x);
    return gauss_elimination(n-1);
}
 
int main()
{
    scanf("%d",&n);
    repu(i,2,n)
    {
        int x,y;
        scanf("%d%d",&x,&y),map[x][y]=1,map[y][x]=1;
    }
    if(n==2)
	{
		puts("0 1");
		return 0;
	 } 
    repu(i,1,n)
        f[i]=calc(i);
    static poly x,t;
    memset(x.a,0,sizeof(x.a)),x.a[0]=1;
    repu(i,1,n)
    {
        ans=ans+x*f[1];
        repu(j,1,n-i)
            f[j]=LL(f[j+1]+p-f[j])*power(i,p-2)%p;
        memset(t.a,0,sizeof(t.a)),t.a[1]=1,t.a[0]=p-i,x=x*t;
    }
    int sum=0;
    for(int i=n-1;i>=0;i--)
    printf("%d ",ans.a[i]);
  //      inc(sum,ans.a[i]);
    //printf("%d\n",sum);
    return 0;
}