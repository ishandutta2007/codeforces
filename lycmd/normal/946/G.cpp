#include<bits/stdc++.h>
using namespace std;
int const N=600010;
int n,ans,a[N],f[N][2];
vector<int>b;
void tomax(int&x,int y){
	if(x<y)x=y;
}
struct fenwick_tree{
	int tr[N];
	void add(int x,int y){
		for(x++;x<N;x+=x&-x)
			tomax(tr[x],y);
	}
	int ask(int x){
		int res=0;
		for(x++;x;x&=x-1)
			tomax(res,tr[x]);
		return res;
	}
};
fenwick_tree t1,t2,t3;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]-=i,b.push_back(a[i]),b.push_back(a[i]+1);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=n;i++){
		int t=lower_bound(b.begin(),b.end(),a[i]+1)-b.begin()+1;
		a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
		f[i][0]=t1.ask(a[i])+1;
		f[i][1]=max(t2.ask(a[i])?t2.ask(a[i])+1:0,i>2?t3.ask(t)+1:0);
		t1.add(a[i],f[i][0]),t2.add(a[i],f[i][1]);
		if(i>1)t3.add(a[i-1],f[i-1][0]);
		tomax(ans,f[i][0]),tomax(ans,f[i][1]);
	}
	cout<<max(n-ans-1,0)<<"\n";
}//