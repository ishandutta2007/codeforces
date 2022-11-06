#include<cstdio>
#include<cstring>
const int N=1005;
int n,m,c,cnt;
int a[N];
signed main()
{
  int x;
  register int i;
  memset(a,-1,sizeof(a));
  scanf("%d%d%d",&n,&m,&c);
  while(cnt<n)
  {
    scanf("%d",&x);
    if(x<=(c>>1))
    {
      for(i=1;i<=n;++i)
        if(!~a[i]||a[i]>x)
          break;
      if(!~a[i])
        ++cnt;
      a[i]=x;
      printf("%d\n",i);
      fflush(stdout);
    }
    else
    {
      for(i=n;i;--i)
        if(!~a[i]||a[i]<x)
          break;
      if(!~a[i])
        ++cnt;
      a[i]=x;
      printf("%d\n",i);
      fflush(stdout);
    }
  }
  return 0;
}