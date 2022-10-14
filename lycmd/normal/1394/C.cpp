#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,x[N],y[N];
string s;
int calc(int k,int&tx,int&ty){
	int xi=-N,xa=N,yi=-N,ya=N,zi=-N,za=N;
	for(int i=1;i<=n;i++)
		xi=max(xi,x[i]-k),xa=min(xa,x[i]+k),
		yi=max(yi,y[i]-k),ya=min(ya,y[i]+k),
		zi=max(zi,x[i]-y[i]-k),za=min(za,x[i]-y[i]+k);
	if(xi>xa||yi>ya||zi>za||xa-yi<zi||za<xi-ya)
		return tx=ty=-1,0;
	return tx=min(xa,ya+za),ty=min(tx-zi,ya),1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(char j:s)
			(j=='B'?x:y)[i]++;
	}
	int l=-1,r=N,tx,ty;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(calc(mid,tx,ty))r=mid;else l=mid;
	}
	calc(r,tx,ty),cout<<r<<"\n"+string(tx,'B')+string(ty,'N')<<"\n";
}