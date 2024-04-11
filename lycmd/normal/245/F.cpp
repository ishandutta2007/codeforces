#include<bits/stdc++.h>
#define int long long
#define upd(a,i,k) ((a)+=(s[i]-48)*(k))
using namespace std;
int const N=233333,md[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,m,k,a[N];
string s;
void nxtday(int&y,int&m,int&d){
	d++;
	if(d==(md[m]+(m==2&&((y%4==0&&y%100)||y%400==0))+1))
		d=1,m++;
	if(m==13)
		m=1,y++;
}
void add(string&s,int k,int n){
	string t="";
	while(n--)t+=k%10+48,k/=10;
	reverse(t.begin(),t.end());
	s+=t;
}
int daycount(int y,int m,int d){
	int ty=2011,tm=1,td=1,cnt=0;
	while(ty^y||tm^m||td^d)
		nxtday(ty,tm,td),cnt++;
	return cnt;
}
string trans(int s){
	int k=s/86400,ty=2011,tm=1,td=1;
	string a="";
	while(k--)
		nxtday(ty,tm,td);
	add(a,ty,4),a+="-",add(a,tm,2),a+="-",add(a,td,2),a+=" ";
	add(a,s/3600%24,2),a+=":",add(a,s/60%60,2),a+=":",add(a,s%60,2);
	return a;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>k>>m,getline(cin,s);
	for(n=1;;n++){
		getline(cin,s);
		if(s=="")break;
		int y=0,m=0,d=0,t=0;
		upd(y,0,1000),upd(y,1,100),upd(y,2,10),upd(y,3,1);
		upd(m,5,10),upd(m,6,1);
		upd(d,8,10),upd(d,9,1);
		upd(t,11,36000),upd(t,12,3600);
		upd(t,14,600),upd(t,15,60);
		upd(t,17,10),upd(t,18,1);
		a[n]=daycount(y,m,d)*86400+t;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int p=lower_bound(a+1,a+1+n,a[i]-k+1)-a;
		if(i-p+1>=m)
			cout<<trans(a[i])<<"\n",exit(0);
	}
	cout<<"-1\n";
}