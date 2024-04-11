#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10,S=320;
int n,m,a[N];deque<int> q[S];
int lst,t[S][N],len,blk[N];
#define L(x) (((x)-1)*len+1)
#define R(x) min(n,x*len)
#define val(x) q[blk[x]][x-L(blk[x])]
int tmp[N],tp;
void print(){For(i,1,n)printf("%d ",val(i));puts("");}
signed main(){
	n=read(),len=sqrt(n);For(i,1,n)blk[i]=(i-1)/len+1,q[blk[i]].push_back(a[i]=read()),t[blk[i]][a[i]]++;
	m=read();while(m--){
		int op=read(),l=(read()+lst-1)%n+1,r=(read()+lst-1)%n+1;
		if(l>r)swap(l,r);
		if(op==1){
			if(blk[l]==blk[r]){
				int ll=L(blk[l]),rr=R(blk[l]);
				For(i,ll,rr)tmp[i]=val(i);
				while(!q[blk[l]].empty())q[blk[l]].pop_back();
				int x=tmp[r];Rof(i,r,l+1)tmp[i]=tmp[i-1];tmp[l]=x;
				For(i,ll,rr)q[blk[l]].push_back(tmp[i]);
			}else{
				int x=q[blk[l]].back(),to=val(r);
				For(i,blk[l]+1,blk[r]-1)q[i].push_front(x),t[i][x]++,x=q[i].back(),q[i].pop_back(),t[i][x]--;
				int ll=L(blk[l]),rr=R(blk[l]);For(i,ll,rr)tmp[i]=val(i);
				while(!q[blk[l]].empty())t[blk[l]][q[blk[l]].back()]--,q[blk[l]].pop_back();
				Rof(i,rr,l+1)tmp[i]=tmp[i-1];tmp[l]=to;
				For(i,ll,rr)q[blk[l]].push_back(tmp[i]),t[blk[l]][tmp[i]]++;
				ll=L(blk[r]),rr=R(blk[r]);For(i,ll,rr)tmp[i]=val(i);
				while(!q[blk[r]].empty())t[blk[r]][q[blk[r]].back()]--,q[blk[r]].pop_back();
				Rof(i,r,ll+1)tmp[i]=tmp[i-1];tmp[ll]=x;
				For(i,ll,rr)q[blk[r]].push_back(tmp[i]),t[blk[r]][tmp[i]]++;
			}
		}else{
			int k=(read()+lst-1)%n+1,ans=0;
			if(blk[l]==blk[r])For(i,l,r)ans+=val(i)==k;
			else{
				For(i,blk[l]+1,blk[r]-1)ans+=t[i][k];
				For(i,l,R(blk[l]))ans+=val(i)==k;
				For(i,L(blk[r]),r)ans+=val(i)==k;
			}printf("%d\n",lst=ans);
		}
	}
	return 0;
}