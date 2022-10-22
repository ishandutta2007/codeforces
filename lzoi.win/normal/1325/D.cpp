#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
ll u,v;
int ans[70],len;
int main(){
	cin>>u>>v;
	if(u>v||(v-u)%2){
		puts("-1");
		return 0;
	}
	ll p=v-u>>1;
	for(int i=0;i<=60;i++)
		len=max(len,ans[i]=(p>>i)%2*2+(u>>i)%2);
	cout<<len<<endl;
	for(int i=1;i<=len;i++){
		ll sum=0,x=1;
		for(int j=0;j<=60;j++,x<<=1)
			if(ans[j]) ans[j]--,sum+=x;
		cout<<sum<<' ';
	}
	puts("");
	return 0;
}