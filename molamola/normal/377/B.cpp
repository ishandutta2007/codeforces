#include<stdio.h>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

typedef pair<int,int> Pi;
#define X first
#define Y second
typedef pair<Pi,int> Pii;

struct str{
    int a,b,c;
    bool operator<(const str &l)const{
        return a!=l.a?a<l.a:b<l.b;
    }
}inp[100010];

priority_queue <Pi> pq;
priority_queue <Pii, vector<Pii>, greater<Pii> > H;

int n,m,s;
int a[100010];
int ans[100010],tmp[100010],B[100010];
int flag;
int now[100010];

bool check(int x)
{
    int i,cnt=0;
    while(!pq.empty())pq.pop();
    for(i=1;i<=m;i++)pq.push(Pi(a[i],i));
    for(i=1;i<=m;i++)tmp[i]=0;
//  for(i=1;i<=n;i++)H.push(Pi(inp[i].b,inp[i].a));
    int now=n+1;
    while(!H.empty())H.pop();
    while(!pq.empty()){
        Pi t = pq.top();
        int u = lower_bound(B+1,B+1+n,t.X) - B;
        while(now>u){
            now--;
            H.push(Pii(Pi(inp[now].b,inp[now].a),inp[now].c));
        }
        if(H.empty())return false;
        Pii ta = H.top();
        H.pop();
        cnt += ta.X.X;
        if(cnt>s)return false;
        for(i=1;i<=x;i++){
            Pi tt = pq.top();
            tmp[tt.Y] = ta.Y;
            pq.pop();
            if(pq.empty()){
                for(int j=1;j<=m;j++)ans[j]=tmp[j];
                flag = 1;
                return true;
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    int i;
    for(i=1;i<=m;i++)scanf("%d",a+i);
    for(i=1;i<=n;i++)scanf("%d",&inp[i].a);
    for(i=1;i<=n;i++)scanf("%d",&inp[i].b);
    for(i=1;i<=n;i++)inp[i].c=i;
    sort(inp+1,inp+1+n);
    for(i=1;i<=n;i++)B[i]=inp[i].a;
    int st=1,mi,en=m;
    while(st<=en){
        mi=(st+en)>>1;
        if(check(mi))en=mi-1;
        else st=mi+1;
    }
    if(!flag){printf("NO");return 0;}
    printf("YES\n");
    for(i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}