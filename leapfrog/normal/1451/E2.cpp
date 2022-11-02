//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,v[65545],a[65545],Key;vector<int>T[65545];
inline void solve1(int id)
{
	cout<<"AND "<<T[id][0]<<" "<<T[id][1]<<endl,cout.flush(),cin>>Key;
	v[1]=id^Key;for(int i=2;i<=n;i++) v[i]=v[1]^a[i];
	cout<<"! ";for(int i=1;i<=n;i++) cout<<v[i]<<(i==n?'\n':' ');
}
inline void solve2()
{
	int x=1,y=T[n-1][0],z=(y==2)?3:2;
	int Xxy=a[y],Xxz=a[z],Xyz=a[y]^a[z],Axy=0,Axz,Ayz;
	cout<<"AND "<<x<<" "<<z<<endl,cout.flush(),cin>>Axz;
	cout<<"AND "<<y<<" "<<z<<endl,cout.flush(),cin>>Ayz;
//	cout<<x<<" "<<y<<" "<<z<<endl;
//	cout<<Xxy<<" "<<Xxz<<" "<<Xyz<<" "<<Axy<<" "<<Axz<<" "<<Ayz<<endl;
	int Sxy=Xxy+(Axy<<1),Sxz=Xxz+(Axz<<1),Syz=Xyz+(Ayz<<1),Sxyz=(Sxy+Sxz+Syz)>>1;
	v[x]=Sxyz-Syz;for(int i=2;i<=n;i++) v[i]=v[1]^a[i];
	cout<<"! ";for(int i=1;i<=n;i++) cout<<v[i]<<(i==n?'\n':' ');
}
inline void solve3()
{
	int x=1,y=T[0][0];
	cout<<"AND "<<x<<" "<<y<<endl,cout.flush(),cin>>v[1];
	for(int i=2;i<=n;i++) v[i]=v[1]^a[i];
	cout<<"! ";for(int i=1;i<=n;i++) cout<<v[i]<<(i==n?'\n':' ');
}
int main()
{
	read(n);
	for(int i=2;i<=n;i++) cout<<"XOR 1 "<<i<<endl,cout.flush(),cin>>a[i],T[a[i]].push_back(i);
	int id=0;for(int i=0;i<n;i++) if((int)T[i].size()>=2) {id=i;break;}
	if(T[0].size()) solve3();else if(id) solve1(id);else solve2();
	return 0;
}