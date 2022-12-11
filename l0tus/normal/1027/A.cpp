#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,n;
    scanf("%d",&T);
    char str[110];
    for(int i=0 ; i<T ; i++)
    {
        bool ispel = true;
        scanf("%d",&n);
        scanf("%s",str);
        for(int j=0 ; j<n ; j++)
        {
            int val = str[j]-str[n-1-j];
            if(val<0) val=-val;
            //printf("%d\n",val);
            if(val>2 || val==1) ispel = false;
        }
        if(ispel) printf("YES\n");
        else printf("NO\n");
    }
}