#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define DEBUG(k...) fprintf(stderr,k)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int ans[maxn],n,rt,t_case;
inline void ask(int op,int i,int j,int x){
	cout<<"? "<<op<<" "<<i<<" "<<j<<" "<<x<<endl;
}
int main(){
	cin>>t_case;
	while(t_case--){
		cin>>n;
		rt=0;
		for(ri i=1,j;i<n;i+=2){
			ask(2,i,i+1,1);
			cin>>j;
			if(j==1){rt=i;break;}
			if(j==2){
				ask(2,i+1,1,1);
				cin>>j;
				if(j==1){rt=i+1;break;}
			}
		}
		if(!rt)rt=n;
		ans[rt]=1;
		for(ri i=1;i<=n;++i)
			if(i!=rt){
				ask(1,rt,i,n-1);
				cin>>ans[i];
			}
		cout<<"!";
		for(ri i=1;i<=n;++i)cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}