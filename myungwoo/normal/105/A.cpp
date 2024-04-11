#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#define ERR 1e-7

int N,M,ans;
double K;
char buf[99];
map <string,int> sc; map <string,int>::iterator it;

int main()
{
    int i,k;
    scanf("%d%d%lf",&N,&M,&K);
    for (i=1;i<=N;i++){
        scanf("%s%d",buf,&k);
        sc[buf] += k;
    }
    for (it=sc.begin();it!=sc.end();++it){
        it->second = it->second*K+ERR;
        if (it->second < 100) it->second = -1;
    }
    for (i=1;i<=M;i++){
        scanf("%s",buf);
        if (sc[buf] <= 0) sc[buf] = 0;
    }
    for (it=sc.begin();it!=sc.end();++it){
        if (it->second >= 0) ans++;
    }
    printf("%d\n",ans);
    for (it=sc.begin();it!=sc.end();++it){
        if (it->second >= 0) printf("%s %d\n",it->first.c_str(),it->second);
    }
}