#include<stdio.h>  
#include<algorithm>  
using namespace std;  
 
 const int maxn=20100;
struct Node  { 
    int x,y;  
    bool id;  
    int bianhao;  
};  
  
Node node[maxn];  
Node ji;  
  
bool cmp1(Node& a,Node& b)  
{  
    if(a.y!=b.y) return a.y<b.y;  
    else return a.x<b.x;  
}  
  
bool cmp2(Node& a,Node& b)  
{  
    return ((a.x-ji.x)*(b.y-ji.y)-(a.y-ji.y)*(b.x-ji.x))<0;  
}  
  
int n;  
int ans[maxn];  
  
void dfs(int l,int r)  
{  
    if(l>r) return;  
    int c=min_element(node+l,node+r+1,cmp1)-node;
    swap(node[l],node[c]);
    ji=node[l];  
    sort(node+l+1,node+r+1,cmp2);  
    int cnt1=0,cnt2=0;  
    int k=r;  
    while(!(ji.id!=node[k].id&&cnt1==cnt2))  
    {  
        if(node[k].id==ji.id) cnt1++;  
        else cnt2++;  
        k--;  
    }  
    if(ji.id) ans[node[k].bianhao]=ji.bianhao;  
    else ans[ji.bianhao]=node[k].bianhao;  
    dfs(l+1,k-1);  
    dfs(k+1,r);  
}  
  
int main()  
{  
	scanf("%d",&n);
    {  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d %d",&node[i].x,&node[i].y);  
            node[i].id=false;  
            node[i].bianhao=i;  
        }  
        for(int i=n+1;i<=2*n;i++)  
        {  
            scanf("%d %d",&node[i].x,&node[i].y);  
            node[i].id=true;  
            node[i].bianhao=i-n;;  
        }  
        dfs(1,2*n);  
        for(int i=1;i<=n;i++)  
            printf("%d\n",ans[i]);  
    }  
    return 0;  
}