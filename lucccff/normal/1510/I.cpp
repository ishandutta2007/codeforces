#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,fg[1010],mini;
LL num[2];
char ch[1010];
int main(){
	srand(time(0));
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%s",ch);
        num[0]=num[1]=0;
        mini=m+1;
        for (int j=0;j<n;j++)
        if (fg[j]<mini) mini=fg[j];
        int p=11;
        for (int j=0;j<n;j++)
        if (fg[j]<=mini+p) num[ch[j]-'0']+=(1LL<<(mini+p-fg[j]));
        int o=1ll*rand()*rand()*rand()%(num[0]+num[1])+1;
        if (o<=num[0]) printf("0\n");
		else printf("1\n");
        fflush(stdout);
        int tmp;
        scanf("%d",&tmp);
        for (int j=0;j<n;j++)
        if (tmp!=ch[j]-'0') fg[j]++;
    }
}