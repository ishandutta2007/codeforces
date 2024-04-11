#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> node;
int const N=200010;
int n,k,x,flg=1,a[N];
multiset<node>s;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i],flg*=!a[i]?0:a[i]/abs(a[i]);
	if(flg>0){
		node w={INT_MAX,0};
		for(int i=1;i<=n;i++)
			w=min(w,node{abs(a[i])/x+1,abs(a[i])});
		for(int i=1;i<=n;i++)
			if(w==node{abs(a[i])/x+1,abs(a[i])}){
				a[i]-=(a[i]<0?-1:1)*x*min(w.first,k),k-=min(w.first,k);
				break;
			}
	}else if(!flg){
		int cnt=0,s=-1;
		for(int i=1;i<=n;i++)
			if(a[i])
				s*=a[i]/abs(a[i]);
			else cnt++;
		if(k>=cnt){
			k-=cnt;
			for(int i=1;i<=n;i++)
				if(!a[i])a[i]=s*x,s=1;
		}else k=0;
	}
	for(int i=1;i<=n;i++)
		s.insert({abs(a[i]),i});
	while(k--){
		auto t=*s.begin();
		int i=t.second;
		s.erase(s.find(t));
		s.insert({abs(a[i]+=x*(a[i]<0?-1:1)),i});
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}