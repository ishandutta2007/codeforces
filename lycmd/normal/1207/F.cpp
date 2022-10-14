#include<bits/stdc++.h>
using namespace std;
int const N=500010,B=755;
int q,op,x,y,a[N],s[B][B];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>q;q--;)
		if(cin>>op>>x>>y,op>1){
			if(x<B)
				cout<<s[x][y]<<"\n";
			else{
				long long res=0;
				for(int i=y;i<N;i+=x)
					res+=a[i];
				cout<<res<<"\n";
			}
		}else{
			for(int i=1;i<B;i++)
				s[i][x%i]+=y;
			a[x]+=y;
		}
}