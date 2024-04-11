#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define LIM 1000005
//#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define gc getchar
char *P1,*P2,buf[LIM];
int n,m,c,d[N];bitset<N> pr[N],a[N];struct Answer {int x1,y1,x2,y2;}w[N];
struct Node {int x,vl;bool operator < (Node t) const {return vl==t.vl?x<t.x:vl<t.vl;}};
set<int> z1;set<Node> z;
int rd()
{
    int res=0;char c=0;while(!isdigit(c)) c=gc();
    while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
void upd(int x1,int x2)
{
	if(w[x1].x1) z1.erase(x1);
    int w1,w2;bitset<N> t1=(a[x1]^pr[m])&a[x2],t2=(a[x2]^pr[m])&a[x1];
	w1=t1._Find_first();w2=t2._Find_first();if(w1>w2) swap(w1,w2);
	if(w1>m || w2>m) w[x1]=(Answer) {0,0,0,0};
	else w[x1]=(Answer) {min(x1,x2),w1,max(x1,x2),w2},z1.insert(x1);
}
void print(int x)
{
	if(x<0) {putchar('-');print(-x);return;}
	if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);
}
int main()
{
    n=rd();m=rd();c=rd();for(int i=1;i<=n;++i) z.insert((Node) {i,0});
    z.insert((Node) {0,0});z.insert((Node) {n+1,m});
    for(int i=1;i<=m;++i) pr[i]=pr[i-1],pr[i][i]=1;a[n+1]=pr[m];
    for(int i=1,x,l,r;i<=c;++i)
    {
        x=rd();l=rd();r=rd();Node t=(Node) {x,d[x]},t1,t2;set<Node>::iterator it,it1,it2;
		it=z.find(t);it1=it2=it;t1=*--it1;t2=*++it2;z.erase(t);upd(t1.x,t2.x);
		a[x]^=pr[r]^pr[l-1];d[x]=a[x].count();t=(Node) {x,d[x]};
        z.insert(t);it=z.find(t);it1=it2=it;t1=*--it1;t2=*++it2;upd(t1.x,x);upd(x,t2.x);
        if(z1.empty()) {print(-1);puts("");continue;}x=*z1.begin();
        print(w[x].x1);putchar(' ');print(w[x].y1);putchar(' ');
		print(w[x].x2);putchar(' ');print(w[x].y2);puts("");
    }return 0;
}