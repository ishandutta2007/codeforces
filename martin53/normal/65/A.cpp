#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,c,d,e,f;
scanf("%i%i%i%i%i%i",&a,&b,&c,&d,&e,&f);
int p=a*c*e;
int q=b*d*f;

int u=c*e;
int v=d*f;

if(c==0&&d)printf("Ron\n");
else if(a==0&&b&&c&&d)printf("Ron\n");
else if(p<q)printf("Ron\n");
else printf("Hermione\n");
return 0;
}