#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int X=5000;
const int N=(int)(X*1.01);
int a[N];
int cnt[N];
bool np[N]={false};
int pc=0;
int ps[N];
int sp[N][N];
int e[N];
LL dlca(int a[N],int b[N]){
	LL sum=0;
	for(int i=pc-1;i>=0;i--){
		int p=ps[i];
		sum+=min(a[p],b[p]);
		if(a[p]!=b[p]){
			break;
		}
	}
	return sum;
}
LL dep(int a[N]){
	LL sum=0;
	for(int i=pc-1;i>=0;i--){
		sum+=a[ps[i]];
	}
	return sum;
}

// 00 10 31

int main(){
	np[0]=np[1]=true;
	for(int i=2;i<N;i++){
		if(!np[i]){
			ps[pc++]=i;
		}
		for(int j=i*2;j<N;j+=i)np[j]=true;
	}
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[x]++;
	}
	cnt[0]=0;
	for(int i=1;i<=X;i++)cnt[i]=a[i]+cnt[i-1];
	for(int i=0;i<pc;i++){
		int p=ps[i];
		for(int k=1;k<=X;k++){
			for(int t=k/p;t;t/=p)sp[k][p]+=t;
		}
	}
	int l=1,r=X;
	for(int i=pc-1;i>=0;i--){
		int p=ps[i];
		int w=0;
		// if(p<=7)cerr<<p<<" ["<<l<<","<<r<<"]"<<endl;
		for(int j=0;j<=X;j+=p){
			int ll=max(j,l);
			int rr=min(j+p-1,r);
			if(ll>rr)continue;
			// if(p<=7)cerr<<"amount: "<<cnt[r]<<"-"<<cnt[ll-1]<<"="<<cnt[r]-cnt[ll-1]<<endl;
			if(cnt[r]-cnt[ll-1]>n/2){
				// if(p<=7)cerr<<p<<" => "<<j<<" ["<<ll<<","<<rr<<"]"<<endl;
				w=j;
			}
			else{
				break;
			}
		}
		LL c=0;
		for(int t=w/p;t;t/=p)c+=t;
		e[p]=c;
		// if(c!=0){
		// 	cerr<<"e "<<p<<" = "<<c<<endl;
		// }
		l=max(w,l);
		r=min(w+p-1,r);
	}
	LL ans=dep(e)*n;
	for(int i=1;i<=X;i++)ans+=a[i]*dep(sp[i]);
	for(int i=1;i<=X;i++)ans-=2*a[i]*dlca(sp[i],e);
	cout<<ans<<endl;
	return 0;
}