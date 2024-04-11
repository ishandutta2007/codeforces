#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
char a[501];
int k,len,ans;
bool ok;
int main()
{
    scanf("%s%d",a,&k);
    len=strlen(a);
    if(k>=len) {printf("%d\n",(len+k)/2*2);return 0;}
    for(int i=0;i<len;i++)
        for(int j=i;j<len;j++)
        {
            ok=true;
            if(j+j-i+1>=len+k) continue;
            for(int k=j+1;k<=j+j-i+1;k++)
                if(k<len&&a[k]!=a[k-(j-i+1)]) {ok=false;break;}
            if(ok) ans=max(ans,2*(j-i+1));
        }
    printf("%d\n",ans); 
    return 0;
}