#include <cstdio>
#include <cstring>
const int N=3e5;
struct ps{
    ps *n,*bef;
    bool in;
    long long art;
    struct ws{
        ps *o;
        ws *n;
        int val;
        ws(ps *o,ws *n,int val):o(o),n(n),val(val){}
    }*w;
    ps(){
        memset(this,0,sizeof(ps));
        art=1e12;
    }
}p[N];
inline void mkline(ps *a,ps *b,int val){
    a->w=new ps::ws(b,a->w,val);
    b->w=new ps::ws(a,b->w,val);
}
int way[N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        mkline(p+a-1,p+b-1,c);
    }
    p[0].in=true;
    p[0].art=0;
    for(ps *s=p,*e=s;s!=0;s=s->n){
        for(ps::ws *i=s->w;i!=0;i=i->n){
            if(i->o->art>s->art+i->val){
                i->o->art=s->art+i->val;
                i->o->bef=s;
                if(!i->o->in){
                    i->o->in=true;
                    e=e->n=i->o,e->n=0;
                }
            }
        }
        s->in=false;
    }
    int wc=0;
    for(ps *s=p+n-1;s!=0;s=s->bef){
        way[wc++]=s-p+1;
    }
    if(p[n-1].art==1e12){
            printf("-1");
            return 0;
    }
    for(wc--;wc>=0;wc--) printf("%d ",way[wc]);
    return 0;
}