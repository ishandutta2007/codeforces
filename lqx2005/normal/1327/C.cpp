/* **********************************************
Created Time: 2020/3/25 21:53:23
File Name: SegmentTree
*********************************************** */
#include<bits/stdc++.h>
using namespace std;
#define Deg fprintf(stderr,"Passing [%s] line %d\n",__FUNCTION__,__LINE__)
typedef long long LL;
int n,m,k,x,y;
map<int,char> p;
vector<int> ans;
void put(int op)
{
    ans.push_back(op);
    return;
}
void out()
{
    int tot=ans.size();
    printf("%d\n",tot);
    for(int i=0;i<tot;i++) printf("%c",p[ans[i]]);
    printf("\n");
    return;
}
int main()
{
    p[0]='U';
    p[1]='D';
    p[2]='L';
    p[3]='R';
	scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k*2;i++) scanf("%d%d",&x,&y);
    if(n!=1) for(int i=1;i<=n-1;i++) put(0);
    if(m!=1) for(int i=1;i<=m-1;i++) put(2);
    for(int i=1;i<=n;i++)
    {
        if(i%2==1) for(int i=1;i<=m-1;i++) put(3);
        else for(int i=1;i<=m-1;i++) put(2);
        put(1);
    }
    out();
	return 0;
}