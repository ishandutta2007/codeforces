#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct nd{
	int l,r,ls,rs,c;
}tr[200001];int trt;
int nw(int l,int r){
	tr[++trt]=(nd){l,r,0,0,2e9};
	return trt;
}
void xg(int o,int p,int c){
	if(tr[o].l==tr[o].r){
		tr[o].c=min(tr[o].c,c);
		return;
	}
	int mid=tr[o].l+tr[o].r>>1;
	if(p<=mid){
		if(!tr[o].ls)tr[o].ls=nw(tr[o].l,mid);
		xg(tr[o].ls,p,c);
	}
	else{
		if(!tr[o].rs)tr[o].rs=nw(mid+1,tr[o].r);
		xg(tr[o].rs,p,c);
	}
	tr[o].c=min(tr[tr[o].ls].c,tr[tr[o].rs].c);
}
int cx(int o,int p){
	if(tr[o].l==tr[o].r)return tr[o].c;
	int mid=tr[o].l+tr[o].r>>1;
	if(p<=mid)return cx(tr[o].ls,p);
	else return min(cx(tr[o].rs,p),tr[tr[o].ls].c);
}
struct dn{int x,y,z,i;};
bool operator<(dn u,dn v){
	return u.x<v.x;
}
vector<dn>a[8],b[8];
dn bf[100001];
int ans[100001];
int main(){
	int X,Y,Z,n,m,k;
	int l1=2e9,r1=-1,l2=2e9,r2=-1,l3=2e9,r3=-1;
	scanf("%d%d%d%d%d%d",&X,&Y,&Z,&n,&m,&k);
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		l1=min(l1,x);
		r1=max(r1,x);
		l2=min(l2,y);
		r2=max(r2,y);
		l3=min(l3,z);
		r3=max(r3,z);
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x>=l1&&x<=r1&&y>=l2&&y<=r2&&z>=l3&&z<=r3){
			printf("INCORRECT\n");
			return 0;
		}
		for(int ii=0;ii<2;ii++)
			for(int jj=0;jj<2;jj++)
				for(int kk=0;kk<2;kk++){
					if(ii==0&&x>r1)continue;
					if(ii==1&&x<l1)continue;
					if(jj==0&&y>r2)continue;
					if(jj==1&&y<l2)continue;
					if(kk==0&&z>r3)continue;
					if(kk==1&&z<l3)continue;
					a[ii*4+jj*2+kk].push_back((dn){max(0,ii?x-r1:l1-x),max(0,jj?y-r2:l2-y),max(0,kk?z-r3:l3-z),0});
				}
	}
	for(int i=1;i<=k;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		bf[i]=(dn){x,y,z,i};
		for(int ii=0;ii<2;ii++)
			for(int jj=0;jj<2;jj++)
				for(int kk=0;kk<2;kk++){
					if(ii==0&&x>r1)continue;
					if(ii==1&&x<l1)continue;
					if(jj==0&&y>r2)continue;
					if(jj==1&&y<l2)continue;
					if(kk==0&&z>r3)continue;
					if(kk==1&&z<l3)continue;
					b[ii*4+jj*2+kk].push_back((dn){max(0,ii?x-r1:l1-x),max(0,jj?y-r2:l2-y),max(0,kk?z-r3:l3-z),i});
				}
	}
	for(int ii=0;ii<8;ii++){
		tr[0].c=2e9;
		trt=0;
		nw(0,1e5);
		vector<dn>&aa=a[ii],&bb=b[ii];
		sort(aa.begin(),aa.end());
		sort(bb.begin(),bb.end());
		for(int i=0,j=0;i<bb.size();i++){
			while(j<aa.size()&&aa[j].x<=bb[i].x){
				xg(1,aa[j].y,aa[j].z);
				j++;
			}
			if(cx(1,bb[i].y)<=bb[i].z)
				ans[bb[i].i]|=1;
		}
	}
	printf("CORRECT\n");
	for(int i=1;i<=k;i++)
		printf(bf[i].x>=l1&&bf[i].x<=r1&&bf[i].y>=l2&&bf[i].y<=r2&&bf[i].z>=l3&&bf[i].z<=r3?
			"OPEN\n":ans[i]?"CLOSED\n":"UNKNOWN\n");
}