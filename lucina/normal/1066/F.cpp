#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const long long inf=1e15;
int n;
struct pt{
    int x,y;
    int level(){
        return max(x,y);
        }
    void read(){
        scanf("%d%d",&x,&y);
        return;
    }
    friend int dist(pt a,pt b){
        return abs(a.x-b.x)+abs(a.y-b.y);
    }
    bool operator<(const pt a)const{
        return x==a.x?y>a.y:x<a.x;
    }
}p[maxn];
vector<pt> mi;
vector<pt> ma;
bool cmp(const pt &a,const pt &b){
    return max(a.x,a.y)<max(b.x,b.y);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        p[i].read();
    }
    sort(p+1,p+1+n,cmp);
   // for(int i=1;i<=n;i++)
     //   p[i].print();
     int j;
    for(int i=1;i<=n;i++){
         j=i;
        pt maa=p[i];
        pt mii=p[i];
        while(p[j].level()==p[i].level()&&j<=n){
                maa=max(maa,p[j]),mii=min(mii,p[j]);
                j++;
            }
        j--;
        ma.push_back(maa);
        mi.push_back(mii);
        i=j;
    }
  //  cout<<"Lucinaaaaaa\n";
    long long a[2],b[2];
   b[0]=0LL,b[1]=0LL;
    pt pre[2];
    pre[0]={0,0};pre[1]=pre[0];
    int dis;
    pt p1,p2;
    for(int i=0;i<mi.size();i++){
        p1=mi[i];
        p2=ma[i];
        a[0]=inf;
        a[1]=inf;
        //0->min 1->max
        dis=dist(p1,p2);
        a[0]=min(a[0],b[0]+dist(pre[0],p2)+dis);
        a[0]=min(a[0],b[1]+dist(pre[1],p2)+dis);
        a[1]=min(a[1],b[0]+dist(pre[0],p1)+dis);
        a[1]=min(a[1],b[1]+dist(pre[1],p1)+dis);
        pre[0]=p1;
        pre[1]=p2;
       // printf("%lld %lld\n",a[0],a[1]);
        b[0]=a[0];
        b[1]=a[1];
    }
    printf("%lld\n",min(b[0],b[1]));
}