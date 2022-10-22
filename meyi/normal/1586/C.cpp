#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=1e6+10;
int a[maxn],m,n,q,t_case;
vector<int>sum;
string s[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ri i=0;i<n;++i)cin>>s[i];
	sum.resize(m);
	for(ri j=1;j<m;++j){
		sum[j]=sum[j-1];
		for(ri i=1;i<n;++i)
			if(s[i-1][j]=='X'&&s[i][j-1]=='X')
				++sum[j];
	}
	cin>>q;
	while(q--){
		ri x,y;
		cin>>x>>y;
		if(sum[y-1]-sum[x-1]==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}