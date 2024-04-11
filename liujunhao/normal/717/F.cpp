#include<cstdio>
#include<algorithm>
#define MAXN 200000
#define INF 0x7fffffff
using namespace std;
void Read(int &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
int n,a[MAXN+10],d[MAXN+10],m;
struct node{
    int odd,even,mio,mie;
}tree[(1<<18)+10];
inline void update(int i){
    tree[i].mio=min(tree[i<<1].mio,tree[(i<<1)|1].mio);
    tree[i].mie=min(tree[i<<1].mie,tree[(i<<1)|1].mie);
}
void build(int i,int l,int r){
    if(l==r){
        tree[i].mio=d[(l<<1)-1];
        tree[i].mie=d[l<<1];
        return;
    }
    tree[i].odd=tree[i].even=0;
    int mid((l+r)>>1);
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
    update(i);
}
void read(){
    Read(n);
    int i;
    for(i=1;i<=n;i++){
        Read(a[i]);
        d[i]=a[i]-d[i-1];
    }
    build(1,1,(n+1)>>1);
}
inline void push_down(int i){
    if(tree[i].even){
        tree[i<<1].even+=tree[i].even;
        tree[(i<<1)|1].even+=tree[i].even;
        tree[i<<1].mie+=tree[i].even;
        tree[(i<<1)|1].mie+=tree[i].even;
        tree[i].even=0;
    }
    if(tree[i].odd){
        tree[i<<1].odd+=tree[i].odd;
        tree[(i<<1)|1].odd+=tree[i].odd;
        tree[i<<1].mio+=tree[i].odd;
        tree[(i<<1)|1].mio+=tree[i].odd;
		tree[i].odd=0;
    }
}
void insert(int i,int l,int r,int ll,int rr,int od,int ev){
    if(ll<=l&&r<=rr){
        tree[i].even+=ev;
        tree[i].odd+=od;
        tree[i].mie+=ev;
        tree[i].mio+=od;
        return;
    }
    if(ll>r||rr<l)
        return;
    int mid((l+r)>>1);
    push_down(i);
    insert(i<<1,l,mid,ll,rr,od,ev);
    insert((i<<1)|1,mid+1,r,ll,rr,od,ev);
    update(i);
}
int get_mi_e(int i,int l,int r,int ll,int rr){
    if(ll<=l&&r<=rr)
        return tree[i].mie;
    if(ll>r||rr<l)
        return INF;
    int mid((l+r)>>1);
    push_down(i);
    return min(get_mi_e(i<<1,l,mid,ll,rr),get_mi_e((i<<1)|1,mid+1,r,ll,rr));
}
int get_mi_o(int i,int l,int r,int ll,int rr){
    if(ll<=l&&r<=rr)
        return tree[i].mio;
    if(ll>r||rr<l)
        return INF;
    int mid((l+r)>>1);
    push_down(i);
    return min(get_mi_o(i<<1,l,mid,ll,rr),get_mi_o((i<<1)|1,mid+1,r,ll,rr));
}
void solve(){
    int p,l,r,v,pre;
    Read(m);
    while(m--){
        Read(p),Read(l),Read(r);
		l++,r++;
        if(p==1){
            Read(v);
            if(l&1)
                insert(1,1,(n+1)>>1,(l+1)>>1,(r+1)>>1,v,0);
            else
                insert(1,1,(n+1)>>1,l>>1,r>>1,0,v);
            if(!((r-l)&1)){
                if(r&1){
                    insert(1,1,(n+1)>>1,(r>>1)+1,(n+1)>>1,0,-v);
                    insert(1,1,(n+1)>>1,(r>>1)+2,(n+1)>>1,v,0);
                }
                else
                    insert(1,1,(n+1)>>1,(r>>1)+1,(n+1)>>1,-v,v);
            }
        }
        else{
			if(l&1){
				if(l==1)
					pre=0;
				else
					pre=get_mi_e(1,1,(n+1)>>1,l>>1,l>>1);
				if(r&1){
					if(get_mi_o(1,1,(n+1)>>1,(r+1)>>1,(r+1)>>1)+pre!=1){
						puts("0");
						continue;
					}
				}
				else
					if(get_mi_e(1,1,(n+1)>>1,r>>1,r>>1)-pre){
						puts("0");
						continue;
					}
				if(get_mi_o(1,1,(n+1)>>1,(l>>1)+1,(r+1)>>1)>=1-pre&&get_mi_e(1,1,(n+1)>>1,(l+1)>>1,r>>1)>=pre)
					puts("1");
				else
					puts("0");
			}
			else{
				if(l==1)
					pre=0;
				else
					pre=get_mi_o(1,1,(n+1)>>1,l>>1,l>>1);
				if(r&1){
					if(get_mi_o(1,1,(n+1)>>1,(r+1)>>1,(r+1)>>1)-pre){
						puts("0");
						continue;
					}
				}
				else
					if(get_mi_e(1,1,(n+1)>>1,r>>1,r>>1)+pre!=1){
						puts("0");
						continue;
					}
				pre=get_mi_o(1,1,(n+1)>>1,l>>1,l>>1);
				if(get_mi_o(1,1,(n+1)>>1,(l>>1)+1,(r+1)>>1)>=pre&&get_mi_e(1,1,(n+1)>>1,(l+1)>>1,r>>1)>=1-pre)
					puts("1");
				else
					puts("0");
			}
		}
    }
}
int main()
{
    read();
    solve();
}