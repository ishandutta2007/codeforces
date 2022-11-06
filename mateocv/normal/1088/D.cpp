#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll a=0,b=0;
	ll lis[30];
	memset(lis,0,sizeof lis);
	ll gra=0,resp=2,va=29;
	while(1){
		cout<<"? "<<a<<" "<<b<<endl;
		cin>>resp;
		if(resp==-2)return 0;
		if(resp==0)break;
		gra=resp;
		while(va+1){
			cout<<"? "<<a+(1<<va)<<" "<<b+(1<<va)<<endl;
			cin>>resp;
			if(resp==-2)return 0;
			if(resp!=gra){
				if(gra==1){
					a+=(1<<va);
				}else{
					b+=(1<<va);
				}
				lis[va]=1; va--; break;
			}
			va--;
		}
	}
	for(ll i=29;i>=0;i--){
		if(!lis[i]){
			cout<<"? "<<a+(1<<i)<<" "<<b<<endl;
			cin>>resp;
			if(resp==-2)return 0;
			if(resp==-1){
				a+=(1<<i);
				b+=(1<<i);
			}
		}
	}
	
	cout<<"! "<<a<<" "<<b<<endl;
	
	
	return 0;
}