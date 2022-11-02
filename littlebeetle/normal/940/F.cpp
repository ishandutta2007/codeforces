#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int N=200002;
int n,q,m,B,i,k,b[N],d[N],a[N],A[N];
int opt,x,y,p[N],g[N],rg[N],T,L,R,ans[N];
int cnt[N],val[N];
map<int,int>S;
int Cnt;
struct Uzi{
    int t,l,r,o1,o2;
    bool operator<(const Uzi &k)const{
        if(k.o1!=o1)return k.o1<o1;
        if(k.o2!=o2)return k.o2<o2;
        return k.r<r;
    }
}f[N];
void init(){
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",a+i);
		if(!S[a[i]])S[a[i]]=++Cnt;
		a[i]=S[a[i]];
        d[i]=i;
    }
    for(i=1;i<=n;i++)
        A[i]=a[i];
    B=(int)(n/pow(q,0.33))+1;
    for(i=1;i<=q;i++){
        scanf("%d%d%d",&opt,&x,&y);
        if(opt==1){
            f[++m]=(Uzi){i,x,y,i/B,x/B};
        }
        else{
            p[i]=x;
			if(!S[y])S[y]=++Cnt;
			y=S[y];
            g[i]=y;
            rg[i]=A[x];
            A[x]=y;
        }
    }
    sort(f+1,f+m+1);
}
void work(){
    T=0;
    L=f[1].l;
    R=f[1].l-1;
    for(i=1;i<=m;i++){
        while(R<f[i].r){
            R++;
            val[cnt[a[R]]]--;
            val[++cnt[a[R]]]++;
        }
        while(L>f[i].l){
            L--;
            val[cnt[a[L]]]--;
            val[++cnt[a[L]]]++;         
        }
        while(R>f[i].r){
            val[cnt[a[R]]]--;
            val[--cnt[a[R]]]++;
            R--;
        }
        while(L<f[i].l){
            val[cnt[a[L]]]--;
            val[--cnt[a[L]]]++; 
            L++;        
        }
        while(T<f[i].t){
            T++;
            if(p[T]&&L<=p[T]&&p[T]<=R){
                val[cnt[a[p[T]]]]--;
                val[--cnt[a[p[T]]]]++;
                a[p[T]]=g[T];
                val[cnt[a[p[T]]]]--;
                val[++cnt[a[p[T]]]]++;
            }
            a[p[T]]=g[T];
        }
        while(T>f[i].t){
            T--;
            if(p[T]&&L<=p[T]&&p[T]<=R){
                val[cnt[a[p[T]]]]--;
                val[--cnt[a[p[T]]]]++;
                a[p[T]]=rg[T];
                val[cnt[a[p[T]]]]--;
                val[++cnt[a[p[T]]]]++;
            }
            a[p[T]]=rg[T];          
        }       
        for(k=1;val[k];k++);
        ans[f[i].t]=k;
    }
    for(i=1;i<=q;i++)
		if(ans[i])
			printf("%d\n",ans[i]);
}
int main(){
    init();
    work();
    return 0;
}