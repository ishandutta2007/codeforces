#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<ctime>
using namespace std;
char a[31];
int k,len,now,sub,maxnum;
int main()
{
    scanf("%s%d",a,&k);
    len=strlen(a);
    while(k>0)
    {
        sub=-1,maxnum=-1;
        for(int i=now+1;i<=min(len,now+k);i++) if(a[i]>maxnum) maxnum=a[i],sub=i;
        if(sub!=-1&&a[sub]>a[now])
        {
            for(int i=sub;i>now;i--) swap(a[i],a[i-1]);
            k-=sub-now;
        }
        now++;
        if(now>=len) break;
    }
    printf("%s\n",a);
    return 0;
}