#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int T,n,ans,p[N],c[N],vis[N];
vector<int>fac,t;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>T;T--;){
		cin>>n,ans=n;
		for(int i=1;i<=n;i++)
			cin>>p[i];
		for(int i=1;i<=n;i++)
			cin>>c[i],vis[i]=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			vis[i]=1,t.clear(),t.push_back(c[i]);
			for(int j=p[i];j!=i;j=p[j])
				vis[j]=1,t.push_back(c[j]);
			int k=t.size(),res=k;
			fac.clear();
			for(int j=1;j*j<=k;j++)
				if(k%j==0){
					fac.push_back(j);
					if(j*j<k)fac.push_back(k/j);
				}
			sort(fac.begin(),fac.end());
			for(int j:fac)
				for(int x=0;x<j;x++){
					int flg=1;
					for(int y=x;y<k;y+=j)
						flg&=t[x]==t[y];
					if(flg){
						res=j;goto finish;
					}
				}
finish:	    ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
}