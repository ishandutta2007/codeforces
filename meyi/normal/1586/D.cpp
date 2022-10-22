#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &k){return x>k?x=k,1:0;}
template<class T>inline bool ckmax(T &x,const T &k){return x<k?x=k,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
inline int query(vector<int>v){
	printf("? ");
	for(auto i:v)printf("%d ",i);
	printf("\n");
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	return ret;
}
int a[maxn],n,pos;
inline int query(int k){
	ri pos;
	for(ri i=1;i<=n;++i)
		if(i>=max(1,1-k)&&i<=min(n,n-k)){
			pos=i;
			break;
		}
	vector<int>tmp;
	for(ri i=1;i<n;++i)tmp.push_back(pos);
	tmp.push_back(pos+k);
	return query(tmp);
}
int main(){
	scanf("%d",&n);
	for(ri i=n;i>1;--i)
		if(!query(n-i+1)){
			a[n]=i;
			break;
		}
	if(!a[n])a[n]=1;
	for(ri i=1;i<=n;++i)
		if(i!=a[n])
			a[query(i-a[n])]=i;
	printf("! ");
	for(ri i=1;i<=n;++i)printf("%d ",a[i]);
	fflush(stdout);
	return 0;
}