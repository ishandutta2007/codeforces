#include <bits/stdc++.h>
#define N 10000005
#define ll long long
#define int long long
using namespace std;
char xB[1<<15],*xS=xB,*xT=xB;
#define getchar() (xS==xT&&(xT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xT)?0:*xS++)
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define inf 1000000000
int T;
int n,m;
#define pr pair<int,int>
struct fl{
    int a,b;
}f[N];
bool cmp(const fl &a,const fl &b){
    return a.b<b.b;
}


int qsum;
pr sum[N];
int tot,root;
int ch[N][2];
#define ls ch[x][0]
#define rs ch[x][1]
#define fi first
#define se second


priority_queue<int,vector<int>,greater<int> > q;


pr add(pr a,pr b){
    return make_pair(a.fi+b.fi,a.se+b.se);
}
pr dec(pr a,pr b){
    return make_pair(a.fi-b.fi,a.se-b.se);
}
void up(int x){
    sum[x]=add(sum[ls],sum[rs]);
}



void ins(int &x,int l,int r,int p,int v){
    if(!x){
        x=++tot;
    }
    if(l==r){
        sum[x]=add(sum[x],make_pair(v,1));
        return ;
    }
    int mid=(l+r)>>1;
    if(p<=mid) ins(ch[x][0],l,mid,p,v);
    else ins(ch[x][1],mid+1,r,p,v);
    up(x);
}

pair<int,int> ask(int x,int l,int r,int L,int R){
    if(!x) return make_pair(0,0);
    if(l>=L && r<=R){
        return sum[x];
    }
    int mid=(l+r)>>1;
    pr ret=make_pair(0,0);
    if(L<=mid) ret=add(ret,ask(ch[x][0],l,mid,L,R));
    if(R>mid)  ret=add(ret,ask(ch[x][1],mid+1,r,L,R));

    return ret;
}
int ans=0;


void cl(int x,int l,int r){
    sum[x]=make_pair(0,0);
    if(!x) return ;
//    cerr<<l<<' '<<r<<endl;
    if(l==r) return ;
//    cerr<<l<<' '<<r<<endl;
    int mid=(l+r)>>1;

    cl(ch[x][0],l,mid);
    cl(ch[x][1],mid+1,r);

    ch[x][0]=ch[x][1]=0;
}

void clear(){
    cl(root,0,inf);
    //cerr<<sum[1].fi<<' '<<sum[2].se<<endl;
    while(!q.empty()) q.pop();
    qsum=0;
}

main()
{
  // freopen("data.in","r",stdin);
    T=read();
    while(T--){
        ans=0;
        root=0;
        tot=0;
        n=read(),m=read();
        for(int i=1;i<=m;i++){
            f[i].a=read(),f[i].b=read();
        }
        sort(f+1,f+m+1,cmp);

        for(int i=1;i<=m;i++){
            // choose i
            pr bs=ask(root,0,inf,0,f[i].b);
            bs=dec(sum[root],bs);

            if(q.size()==n) ans=max(ans,qsum);

            int rem=n-bs.se-1;
            if(rem<0){
                ans=max(ans,qsum);
            }else{
                ans=max(ans,bs.fi+f[i].a+f[i].b*rem);
            }


            //cerr<<i<<' '<<bs.fi+f[i].a+f[i].b*rem<<' '<<"a"<<' '<<bs.se<<endl;

            ins(root,0,inf,f[i].a,f[i].a);

            if(q.empty()){
                q.push(f[i].a);
                qsum+=f[i].a;
                continue ;
            }
            if(q.size()<n){
                q.push(f[i].a);
                qsum+=f[i].a;
                continue ;
            }
            if(q.top()<f[i].a){
                qsum-=q.top();
                qsum+=f[i].a;
                q.pop();
                q.push(f[i].a);
                continue ;
            }
        }
        if(q.size()==n) ans=max(ans,qsum);

        printf("%lld\n",ans);
    //    assert(tot<=1000000);
    //    cerr<<sum[0].fi<<endl;
        clear();
    }
}