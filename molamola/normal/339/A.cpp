#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int p[4];
char ch[110];

int main()
{
    scanf("%s",ch);
    int i;
    for(i=0;ch[i];i++){
        if(ch[i]=='1')p[1]++;
        if(ch[i]=='2')p[2]++;
        if(ch[i]=='3')p[3]++;
    }
    int t=1;
    for(i=1;i<=3;i++){
        for(int j=1;j<=p[i];j++){
            if(t){t^=1;}
            else printf("+");
            printf("%d",i);
        }
    }
    return 0;
}