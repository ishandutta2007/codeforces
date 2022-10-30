#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define MAXN 9999
typedef pair<int,int> pii;

int N,M,size[MAXN],mom[MAXN],ab[MAXN],inc[MAXN],t1[MAXN],t2[MAXN],sum,target[3];
char buf[99],buf2[99];
string name1[MAXN],name2[MAXN];
map <string,int> num1,num2,type;
bool chk[MAXN];
vector <pii> A[9],B[9];
vector <int> lst[MAXN];

void output()
{
    int i,k;
    for (i=1,k=0;i<=N;i++) if (t1[i] == 0){
        if (ab[k] < ab[i]) k = i;
    }
    printf("%s %d ",name1[k].c_str(),lst[k].size());
    for (i=lst[k].size();i--;){
        printf("%s ",name2[lst[k][i]].c_str());
    }
    puts("");
    for (i=1,k=0;i<=N;i++) if (t1[i] == 1){
        if (ab[k] < ab[i]) k = i;
    }
    printf("%s %d ",name1[k].c_str(),lst[k].size());
    for (i=lst[k].size();i--;){
        printf("%s ",name2[lst[k][i]].c_str());
    }
    puts("");
    for (i=1,k=0;i<=N;i++) if (t1[i] == 2){
        if (ab[k] < ab[i]) k = i;
    }
    printf("%s %d ",name1[k].c_str(),lst[k].size());
    for (i=lst[k].size();i--;){
        printf("%s ",name2[lst[k][i]].c_str());
    }
}

int main()
{
    int i,j,k; ab[0] = -1e9;
    type["weapon"] = 0, type["armor"] = 1, type["orb"] = 2;
    type["gladiator"] = 0, type["sentry"] = 1, type["physician"] = 2;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        scanf("%s%s",buf,buf2);
        name1[i] = buf;
        num1[buf] = i;
        t1[i] = type[buf2];
        switch (t1[i]){
        case 0:
            scanf("%d%*d%*d",ab+i);
            break;
        case 1:
            scanf("%*d%d%*d",ab+i);
            break;
        case 2:
            scanf("%*d%*d%d",ab+i);
            break;
        }
        scanf("%d",size+i);
        A[t1[i]].push_back(pii(ab[i],i));
        sum += size[i];
    }
    scanf("%d",&M);
    for (i=1;i<=M;i++){
        scanf("%s%s",buf,buf2);
        name2[i] = buf;
        num2[buf] = i;
        t2[i] = type[buf2];
        scanf("%d%s",inc+i,buf);
        mom[i] = num1[buf];
        B[t2[i]].push_back(pii(inc[i],i));
    }
    if (M == sum){
        for (i=1;i<=M;i++){
            if (t1[mom[i]] == t2[i]){
                ab[mom[i]] += inc[i];
            }
            lst[mom[i]].push_back(i);
        }
        output();
        return 0;
    }
    for (i=0;i<3;i++) sort(A[i].begin(),A[i].end(),greater<pii>()), sort(B[i].begin(),B[i].end(),greater<pii>());
    for (i=0;i<3;i++){
        int mx=-1e9,tar=0;
        for (j=0;j<A[i].size();j++){
            int n=A[i][j].second,sz=size[n],v=ab[n];
            for (k=0;k<B[i].size()&&sz>0;k++){
                v += B[i][k].first;
                sz--;
            }
            if (mx < v) mx = v, tar = n;
        }
        target[i] = tar;
        for (j=0;j<B[i].size()&&size[tar]>0;j++){
            ab[tar] += B[i][j].first;
            lst[tar].push_back(B[i][j].second);
            chk[B[i][j].second] = 1;
            size[tar]--;
        }
    }
    for (i=0;i<3;i++){
        k = target[i];
        for (j=1;j<=M&&size[k]>0;j++) if (!chk[j]){
            chk[j] = 1;
            size[k]--;
            lst[k].push_back(j);
        }
    }
    output();
}