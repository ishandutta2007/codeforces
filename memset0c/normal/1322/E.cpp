#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=5e5+10,L=20;
int n,ans,a[N],b[N],lg[N],min[2][N][L],max[2][N][L];
inline int askMin(int l,int r,int x){
	int k=lg[r-l+1];
	return std::min(min[x][l][k],min[x][r-(1<<k)+1][k]);
}
inline int askMax(int l,int r,int x){
	int k=lg[r-l+1];
	return std::max(max[x][l][k],max[x][r-(1<<k)+1][k]);
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),lg[0]=-1;
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++){
		min[i&1][i][0]=a[i],min[!(i&1)][i][0]=INT_MAX;
		max[i&1][i][0]=a[i],max[!(i&1)][i][0]=INT_MIN;
	}
	for(int k=0;k<2;k++)
		for(int j=1;j<L;j++)
			for(int i=1;i<=n;i++){
				min[k][i][j]=std::min(min[k][i][j-1],i+(1<<(j-1))<=n?min[k][i+(1<<(j-1))][j-1]:INT_MAX);
				max[k][i][j]=std::max(max[k][i][j-1],i+(1<<(j-1))<=n?max[k][i+(1<<(j-1))][j-1]:INT_MIN);
			}
	for(int i=1;i<=n;i++){
		int l=1,r=std::min(i-1,n-i),mid,res=0;
		auto check=[&](int mid){
			// printf("[%d] %d >> %d %d %d %d\n",i,mid,askMin(i-mid,i+mid,0),askMin(i-mid,i+mid,1),askMax(i-mid,i+mid,0),askMax(i-mid,i+mid,1));
			if(askMin(i-mid,i+mid,0)>askMax(i-mid,i+mid,1))return true;
			if(askMin(i-mid,i+mid,1)>askMax(i-mid,i+mid,0))return true;
			return false;
		};
		while(l<=r)mid=(l+r)>>1,(check(mid)?(res=mid,l=mid+1):(r=mid-1));
		ans=std::max(ans,res);
		// printf("[%d] res=%d\n",i,res);
		if(askMin(i-res,i+res,0)>askMax(i-res,i+res,1)){
			b[i]=(i&1)^(res&1)?askMax(i-res,i+res,1):askMin(i-res,i+res,0);
		}else{
			b[i]=(i&1)^(res&1)?askMin(i-res,i+res,1):askMax(i-res,i+res,0);
		}
	}
	print(ans,'\n');
	for(int i=1;i<=n;i++)print(b[i]," \n"[i==n]);
}