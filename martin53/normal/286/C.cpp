#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,arr[nmax];
void no()
{
printf("NO\n");
exit(0);
}
void yes()
{
printf("YES\n");
for(int i=1;i<=n;i++)printf("%i ",arr[i]);printf("\n");
exit(0);
}
stack< int/*value*/ > s;
int spec[nmax];
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
int t,x;
scanf("%i",&t);
for(int i=1;i<=t;i++)
{
scanf("%i",&x);
arr[x]=-arr[x];
}

if(n%2==1)no();

for(int i=n;i>=1;i--)
{
    if(arr[i]<0)s.push(arr[i]);
    else if(s.size()&&s.top()==-arr[i])s.pop();
    else {arr[i]=-arr[i];s.push(arr[i]);}
}

if(s.size()==0)yes();
else no();
return 0;
}