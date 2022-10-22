#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
inline int query(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int tmp;
	scanf("%d",&tmp);
	return tmp;
}
int ans,l,m,n,r,t;
inline void half1(){
	l=1,r=m-1;
	if(l>=r)ans=1;
	else
		while(l<=r){
			int mid=l+r>>1;
			if(query(mid,m)!=m)r=mid-1;
			else ans=mid,l=mid+1;
		}
}
inline void half2(){
	l=m+1,r=n;
	if(l>=r)ans=r;
	else
		while(l<=r){
			int mid=l+r>>1;
			if(query(m,mid)!=m)l=mid+1;
			else ans=mid,r=mid-1;
		}
}
int main(){
	scanf("%d",&n);
	m=query(1,n);
	if(m==1)t=query(m,n);
	else t=query(1,m);
	if((m==1&&t!=m)||(m!=1&&t==m))half1();
	else half2();
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}