#include<bits/stdc++.h>
using namespace std;
int const N=23333;
int T,n,t[N],res[N];
map<array<int,3>,int>mp;
int query(int a,int b,int c){
	if(mp.count({a,b,c}))return mp[{a,b,c}];
	if(b==c||a==c)return res[c];
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	int x;cin>>x;
	if(~x)return mp[{a,b,c}]=x;
	assert(0);
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>T;T--;){
		memset(res,-1,sizeof res);
		mp.clear();
		cin>>n;
		for(int i=1;i<=n/3;i++)
			t[i]=query(i*3-2,i*3-1,i*3);
		array<int,2>k({-1,-1});
		for(int i=1;i<n/3;i++)
			if(t[i]!=t[i+1]){
				array<int,4>a({t[i],query(i*3-1,i*3,i*3+1),
					query(i*3,i*3+1,i*3+2),t[i+1]});
				for(int j=0;j<3;j++)
					if(a[j]!=a[j+1]){
						if(a[j+1])
							k[1]=i*3-2+j,k[0]=i*3+1+j,
							res[i*3-2+j]=1,res[i*3+1+j]=0;
						else
							k[0]=i*3-2+j,k[1]=i*3+1+j,
							res[i*3-2+j]=0,res[i*3+1+j]=1;
						break;
					}
				break;
			}
		for(int i=1;i<=n/3;i++){
			int f=t[i],l=query(i*3-2,i*3-1,k[f])^f,r=query(i*3-1,i*3,k[f])^f;
			res[i*3-2]=(l&&!r)^!f,res[i*3-1]=(l&&r)^!f,res[i*3]=(!l&&r)^!f;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=res[i];
		cout<<"! "<<cnt; 
		for(int i=1;i<=n;i++)
			if(res[i])cout<<" "<<i;
		cout<<endl;
	}
}