#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,Q,AL,cnt1[101][51],cnt2[101][51];
char buf[9999],*pt;
string name[51];
map <string,int> num,numc;
vector < pair<string,int> > list;

struct {
    string name;
    int cnt[51];
} com[51];

int main()
{
    int i,j,k,n;
    scanf("%d%d%d%d",&AL,&N,&M,&Q);
    for (i=1;i<=N;i++) scanf("%s ",buf), name[i] = buf, num[buf] = i;
    for (i=1;i<=M;i++){
        gets(buf);
        pt = strtok(buf,":, \n\r");
        com[i].name = pt;
        for (pt=strtok(NULL,":, \n\r");pt!=NULL;pt=strtok(NULL,":, \n\r")){
            k = num[pt];
            pt = strtok(NULL,":, \n\r");
            com[i].cnt[k] += atoi(pt);
        }
    }
    while (Q--){
        scanf("%d%s",&k,buf);
        n = num[buf];
        cnt1[k][n]++;
        for (i=1;i<=M;i++){
            for (j=1;j<=N;j++) if (com[i].cnt[j] > cnt1[k][j]) break;
            if (j <= N) continue;
            for (j=1;j<=N;j++) cnt1[k][j] -= com[i].cnt[j];
            cnt2[k][i]++;
            break;
        }
    }
    for (i=1;i<=AL;i++){
        list.clear();
        for (j=1;j<=N;j++) if (cnt1[i][j]) list.push_back(make_pair(name[j],cnt1[i][j]));
        for (j=1;j<=M;j++) if (cnt2[i][j]) list.push_back(make_pair(com[j].name,cnt2[i][j]));
        sort(list.begin(),list.end());
        printf("%d\n",k=list.size());
        for (j=0;j<k;j++) printf("%s %d\n",list[j].first.c_str(),list[j].second);
    }
}