#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N,M,X=1e9,Y=-1;
vector <string> org,now,list[11];
map <string,int> idx;

void proc()
{
    int i,j,k,x=0,p;
    for (i=1;i<N;i++){
        for (j=0;j<i;j++) if (idx[now[i]] < idx[now[j]]) x++;
    } p = N*(N-1)/2-x+1;
    for (i=1;i<=M;i++){
        for (j=k=0;j<list[i].size()&&k<N;j++){
            if (list[i][j] == now[k]) k++;
        }
        if (k == N){
            if (Y < p || Y == p && X > i)
                X = i, Y = p;
            return;
        }
    }
}

int main()
{
    int i,j;
    char buf[99]={0,};
    string str;
    scanf("%d",&N);
    for (i=0;i<N;i++){
        scanf("%s",buf);
        str = buf;
        org.push_back(str);
        idx[str] = i;
    }
    scanf("%d",&M);
    for (i=1;i<=M;i++){
        for (scanf("%d",&j);j--;){
            scanf("%s",buf);
            list[i].push_back(buf);
        }
    }
    now = org;
    do{
        proc();
        next_permutation(now.begin(),now.end());
    }while (now != org);
    if (X == 1e9) puts("Brand new problem!");
    else{
        printf("%d\n[:",X);
        while (Y--) printf("|");
        puts(":]");
    }
}