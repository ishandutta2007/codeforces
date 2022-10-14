#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int t,n,p[N];
string s;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>s;
		if(is_sorted(s.begin(),s.end())){
			cout<<"0\n";
			continue;
		}
		int x=count(s.begin(),s.end(),48),y=n-x;
		if(x<y){
			swap(x,y),reverse(s.begin(),s.end());
			for(char&i:s)i^=1;
		}
		for(int i=0,j=0;i<n;i++)
			j+=s[i]&1?-1:1,j>=0&&(p[j]=i);
		int t=0,c=1;
		while(~s[t]&1)
			t++;
		while(t<x-y)
			c++,t+=(p[t]-t+1)/2;
		cout<<c<<"\n";
	}
}