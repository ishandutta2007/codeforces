#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int n,m,w[512],b[1024],l[512];
set<int> q;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",w+i);
    for(int i=0;i<m;++i)scanf("%d",b+i);
    memset(l,-1,sizeof(l));
    int r=0;
    for(int i=0;i<m;++i){
        q.clear();
        for(int j=l[b[i]]+1;j<i;++j){
            q.insert(b[j]);
        }
        for(set<int>::iterator p=q.begin();p!=q.end();++p){
            r+=w[*p];
        }
        l[b[i]]=i;
    }
    printf("%d\n",r);
}