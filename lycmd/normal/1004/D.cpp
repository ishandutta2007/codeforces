#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int t,n,m,x,y,mx,a[N],cnt[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	for(int i=1;i<=t;i++)
		cin>>a[i],cnt[a[i]]++;
	for(int i=1;;i++)
		if(cnt[i]<4*i){x=i;break;}
	for(int i=N-1;;i--)
		if(cnt[i]){mx=i;break;}
	for(n=1;n<=t;n++)
		if(t%n==0){
			m=t/n,y=n+m-mx-x;
			if(y<1||y>m)continue;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					cnt[abs(i-x)+abs(j-y)]--;
			int flg=0;
			for(int i=0;i<=mx;i++)
				flg|=!!cnt[i];
			if(!flg)cout<<n<<" "<<m<<"\n"<<x<<" "<<y<<"\n",exit(0);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					cnt[abs(i-x)+abs(j-y)]++;
		}
	cout<<"-1\n";
}