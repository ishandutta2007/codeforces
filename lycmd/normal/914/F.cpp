#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int q;
string s,t;
bitset<N>a[33],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		a[s[i]-97][i]=1;
	for(cin>>q;q--;){
		int op,x,y;
		if(cin>>op>>x,x--,op<2)
			cin>>t,a[s[x]-97][x]=0,a[t[0]-97][x]=1,s[x]=t[0];
		else{
			cin>>y>>t,ans.set();
			for(int i=0;i<t.size();i++)
				ans&=a[t[i]-97]>>i;
			cout<<max(0,(int)(ans>>x).count()-(int)(ans>>(y-t.size()+1)).count())<<"\n";
		}
	}
}