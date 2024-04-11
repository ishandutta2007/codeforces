#include <iostream>
#include <cstring> 
#include <cmath> 
using namespace std;


char c[1000500];
void main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int k;
    scanf("%d",&k);
    scanf("%s",&c);
    int l=0;
    int r=0;
    long long res=0;
    int cur=0;
    int len=strlen(c);
    long long x=0;
    long long y=0;
    if (k>0)
    {
        while (true)
        {
            while (cur<k)
            {
                if (c[r]=='1')
                    cur++;
                r++;
                if (r>len)
                    break;
            }
            x=1;
            
            if (r>len )
                break;
            while (c[r]=='0')
            {
                r++;
                x++;
            }
            y=1;
            while (c[l]=='0')
            {
                l++;
                y++;
            }
            l++;
            cur--;
            res+=x*y;
            if (r>=len)
                break;
        }
    }
    else
    {
        while (true)
        {
            while (c[r]=='1')
                r++;
            if (r>len)
                break;
            x=0;
            while (c[r]=='0')
            {
                r++;
                x++;
            }
            r++;
            res+=(x+1)*x/2;
        }
    }
    printf("%I64d",res);
}