#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int t,n,tr[N];
vector<int>p[5];
string s;
int getord(char c){
	switch(c){
		case'A':return 1;
		case'N':return 2;
		case'T':return 3;
		case'O':return 4;
		default:return -1;
	}
}
void add(int x,int y){
	for(;x<=n;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	int res=0;
	for(;x;x&=x-1)res+=tr[x];
	return res;
}
int calc(vector<int>&a){
	for(int i=1;i<=n;i++)
		tr[i]=0;
	int res=0;
	for(int i=0;i<a.size();i++)
		res+=i-ask(a[i]),add(a[i],1);
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>s,n=s.size(),s=" "+s;
		for(int i=1;i<=4;i++)
			p[i].clear();
		for(int i=1;i<=n;i++)
			p[getord(s[i])].push_back(i);
		string t="ANOT",ans;
		int mx=-1;
		do{
			vector<int>a;
			for(char i:t)
				for(int j:p[getord(i)])
					a.push_back(j);
			int res=calc(a);
			if(res>mx)
				mx=res,ans=t;
		}while(next_permutation(t.begin(),t.end()));
		for(char i:ans)
			cout<<string(p[getord(i)].size(),i);
		cout<<"\n";
	}
}