#include<bits/stdc++.h>
using namespace std;
int const N=500010,M=65;
int q,tot=1,fa[N];
double f[N][M+5];
vector<int>p;
int main(){
	ios::sync_with_stdio(0);
	for(int i=1;i<M;i++)
		f[tot][i]=1.0;
	for(cin>>q;q--;){
		int op,x;cin>>op>>x;
		if(op<2){
			fa[++tot]=x,x=tot;
			for(int i=1;i<=M;i++)f[x][i]=1.0;
			p.clear();
			for(int i=M;i--&&x;x=fa[x])
				p.push_back(x);
			for(int i=p.size()-2;i;i--)
				f[p[i+1]][i+1]/=f[p[i]][i]/2.0+0.5;
			for(int i=0;i<p.size()-1;i++)
				f[p[i+1]][i+1]*=f[p[i]][i]/2.0+0.5;
		}else{
			double ans=M-1;
			for(int i=1;i<M;i++)ans-=f[x][i];
			cout<<fixed<<setprecision(6)<<ans<<"\n";
		}
	}
}