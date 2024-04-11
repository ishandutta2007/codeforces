#include <iostream>
#include <cstdio>
using namespace std;
int n;
int s[105],b1[105],b2[105],p;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]),b1[s[i]]++;
    int sum=0,num=0;
    for(int i=1;i<=100;i++) if(b1[i]==1) sum++; else if(b1[i]>2) p=i,num++;
    if(sum%2&&num==0){puts("NO");return 0;}
    puts("YES");
    if(sum%2==0)
    {
        int ss=0;
        for(int i=1;i<=n;i++) 
        {
            if(b1[s[i]]==1) 
            {
                ss++;
                if(ss<=sum/2) putchar('A');
                else putchar('B');
            }
            else putchar('A');
        }
        return 0;
    }
    int ss=0,k=0;
    for(int i=1;i<=n;i++) 
    {
        if(b1[s[i]]==1) 
        {
            ss++;
            if(ss<=sum/2) putchar('A');
            else putchar('B');
            continue;
        }
        if(s[i]==p) {k++;if(k!=1) putchar('B');else putchar('A');}
        else putchar('A');
    }
    return 0;
}