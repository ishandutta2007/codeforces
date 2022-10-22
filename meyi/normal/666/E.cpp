#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxp=233,maxm=1e5+10,maxn=5e5+10;
template<class T>inline void clear(T *arr,int siz){memset(arr,0,sizeof(T)*(siz+1));}
namespace SA{
	int cnt[maxm],id[maxm],inf=255,mx,n,s[maxm],sa[maxm],rk[maxm],tmp[maxm];
	char ss[maxm];
	inline void base_sort(){
		clear(cnt,mx);
		for(ri i=1;i<=n;++i)++cnt[rk[i]];
		for(ri i=1;i<=mx;++i)cnt[i]+=cnt[i-1];
		for(ri i=n;i;--i)sa[cnt[rk[tmp[i]]]--]=tmp[i];
	}
	inline void suffix_sort(){
		for(ri i=1;i<=n;++i)mx=max(mx,rk[i]=s[i]),tmp[i]=i;
		base_sort();
		for(ri len=1,dif=0;dif<n;len<<=1,mx=dif){
			ri p=0;
			for(ri i=n-len+1;i<=n;++i)tmp[++p]=i;
			for(ri i=1;i<=n;++i)
				if(sa[i]>len)
					tmp[++p]=sa[i]-len;
			base_sort();
			swap(rk,tmp);
			rk[sa[1]]=dif=1;
			for(ri i=2;i<=n;++i){
				if(tmp[sa[i-1]]!=tmp[sa[i]]||tmp[sa[i-1]+len]!=tmp[sa[i]+len])++dif;
				rk[sa[i]]=dif;
			}
		}
	}
}
namespace Mo{
	int ans1[maxn],ans2[maxn],bel[maxn],bcnt,m;
	struct qry{
		int l,r,L,R,id;
		inline bool operator<(const qry &k)const{
			return bel[l]!=bel[k.l]?l<k.l:(bel[l]&1)?r<k.r:r>k.r;
		}
	}q[maxn];
}
namespace Block{
	int kbel[maxm],kcnt,kl[maxp],km,kmx[maxp],kr[maxp],ksum[maxp][maxm],tot[maxm];
	inline void add(int k){
		if(!k)return;
		--ksum[kbel[k]][tot[k]];
		++tot[k];
		++ksum[kbel[k]][tot[k]];
		kmx[kbel[k]]=max(kmx[kbel[k]],tot[k]);
	}
	inline void del(int k){ 
		if(!k)return;
		--ksum[kbel[k]][tot[k]];
		--tot[k];
		++ksum[kbel[k]][tot[k]];
		if(!ksum[kbel[k]][kmx[kbel[k]]])--kmx[kbel[k]];
	}
	inline void kquery(int l,int r,int id){
		using namespace Mo;
		ri L=kbel[l],pos=0,R=kbel[r],val=-1;
		if(L==R){
			for(ri i=l;i<=r;++i)
				if(tot[i]>val)
					val=tot[i],pos=i;
			ans1[id]=pos,ans2[id]=val;
			return;
		}
		ri kpos=0,kval=-1;
		for(ri i=L+1;i<R;++i)
			if(kmx[i]>kval)
				kval=kmx[i],kpos=i;
		for(ri i=l;i<=kr[L];++i)
			if(tot[i]>val)
				val=tot[i],pos=i;
		for(ri i=kl[R];i<=r;++i)
			if(tot[i]>val)
				val=tot[i],pos=i;
		if(val>kval||(val==kval&&kbel[pos]<kpos)){
			ans1[id]=pos,ans2[id]=val;
			return;
		}
		ans2[id]=kval;
		for(ri i=kl[kpos];i<=kr[kpos];++i)
			if(tot[i]==kval){
				ans1[id]=i,ans2[id]=kval;
				return;
			}
	}
}
char t[maxn];
int l,num,ql;
int main(){
	scanf("%s%d",t+1,&num);
	using namespace Block;
	km=sqrt(num);
	for(ri i=1;i<=num;++i){
		if(i%km==1)kr[kcnt]=i-1,kl[++kcnt]=i;
		kbel[i]=kcnt;
	}
	kr[kcnt]=num;
	l=strlen(t+1);
	using namespace Mo;
	m=sqrt(l);
	for(ri i=1;i<=l;++i){
		if(i%m==1)++bcnt;
		bel[i]=bcnt;
	}
	using namespace SA;
	for(ri i=1;i<=num;++i){
		scanf("%s",ss+1);
		ri ll=strlen(ss+1);
		for(ri j=1;j<=ll;++j)s[++n]=ss[j],id[n]=i;
		s[++n]=++inf;
	}
	suffix_sort();
	scanf("%d",&ql);
	for(ri i=1;i<=ql;++i){
		ri L=1,R=n,x,y;
		scanf("%d%d%d%d",&q[i].L,&q[i].R,&x,&y);
		q[i].id=i;
		for(ri j=x;j<=y;++j){
			if(L>R)break;
			ri l=L,r=R;
			while(l<=r){
				ri mid=l+r>>1;
				if(s[sa[mid]+j-x]<t[j])l=mid+1;
				else r=mid-1;
			}
			swap(l,L),r=R;
			while(l<=r){
				ri mid=l+r>>1;
				if(s[sa[mid]+j-x]<=t[j])l=mid+1;
				else r=mid-1;
			}
			R=r;
		}
		if(L<=R)q[i].l=L,q[i].r=R;
	}
	sort(q+1,q+ql+1);
	ri pl=1,pr=0;
	for(ri i=1;i<=ql;++i){
		if(q[i].l||q[i].r){
			while(pl>q[i].l)add(id[sa[--pl]]);
			while(pr<q[i].r)add(id[sa[++pr]]);
			while(pl<q[i].l)del(id[sa[pl++]]);
			while(pr>q[i].r)del(id[sa[pr--]]);
			kquery(q[i].L,q[i].R,q[i].id);
		}
		else ans1[q[i].id]=q[i].L;
	}
	for(ri i=1;i<=ql;++i)printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}