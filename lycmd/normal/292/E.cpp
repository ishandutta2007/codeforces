#include<bits/stdc++.h>
using namespace std;
int const N=100010,B=300;
int n,m,a[N],b[N],flg[N],ord[N],bl[N],br[N];
void cov(int x,int y,int k){
	for(int i=0;i<k;i++)
		b[y+i]=a[x+i];
}
void down(int x){
	if(flg[x])
		cov(flg[x],bl[x],br[x]-bl[x]+1),flg[x]=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		ord[i]=i/B+1;
		if(!bl[i/B+1])bl[i/B+1]=i;
		br[i/B+1]=i;
	}
	while(m--){
		int op,x,y,k;
		if(cin>>op>>x,op<2){
			cin>>y>>k;
			int l=y,r=y+k-1,lo=ord[l],ro=ord[r];
			if(lo==ro){
				down(lo),cov(x,y,k);
				continue;
			}
			down(lo),down(ro);
			cov(x,l,br[lo]-l+1);
			cov(x+bl[ro]-y,bl[ro],r-bl[ro]+1);
			for(int i=lo+1;i<ro;i++)
				flg[i]=x+bl[i]-y;
		}else{
			int p=ord[x];
			cout<<(flg[p]?a[x-bl[p]+flg[p]]:b[x])<<"\n";
		}
	}
}