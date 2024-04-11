#include<bits/stdc++.h>
using namespace std;
int const N=40010,MOD=1000000007;
int t,n,f[N];
vector<int>a;
void add(int&x,int y){
	if((x+=y)>=MOD)x-=MOD;
}
string tostr(int x){
	string t="";
	while(x)t+=x%10+48,x/=10;
	reverse(t.begin(),t.end());
	return t;
}
int toint(string x){
	int t=0;
	for(char i:x)
		t=t*10+i-48;
	return t;
}
int ispali(int x){
	if(x%10==0)
		return 0;
	string t=tostr(x);
	reverse(t.begin(),t.end());
	return toint(t)==x;
}
int main(){
	ios::sync_with_stdio(0);
	for(int i=1;i<N;i++)
		if(ispali(i))
			a.push_back(i);
	f[0]=1;
	for(int i:a)
		for(int j=i;j<N;j++)
			add(f[j],f[j-i]);
	for(cin>>t;t--;)
		cin>>n,cout<<f[n]<<"\n";
}