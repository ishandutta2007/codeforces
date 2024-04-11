#include <iostream>
#include <cstdio>

using namespace std;
pair<int,int> p[100000];

long long f(int n)
{
    if (n==1) return 1;
    return (n+f(n-1));
}

long long f1(int n)
{
    long long s=0;
    for (int i=n;i>0;i--)
     s+=i;
     return s;

}

int main()
{
  int n,max=0;
  long long s=0,k=0;
  cin>>n;

  for(int i=0;i<n;i++)
  {
      int a ;
      scanf("%d",&a)>>a;
      if(a<0)
      {
          p[-a].second++;

      }
      if(a>0)
      {
          if (a>max)
          max=a;
          p[a].first++;
      }
       if (a==0)
           p[a].first++;

  }
  if (p[0].first!=0)
     k=f1(p[0].first-1);

  for(int i =1;i<=max;i++)
  {

      s+=1ll * p[i].first*p[i].second;

  }
  printf("%I64d",s+k);
  return 0;
}