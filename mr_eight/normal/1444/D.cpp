//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
inline int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	return fu?-x:x;
}
int t,h,v,l[1002],p[1002],now,nx,ny;
bitset<1000002>bs[1002];
vector<int>v1,v2,v3,v4;
inline bool cmp(int x,int y) {
	return x>y;
}
int main() {
	cin>>t;
	while(t--) {
		v2.clear(),v1.clear(),v3.clear(),v4.clear();
		cin>>h;
		F(i,1,h) {
			l[i]=read();
		}
		cin>>v;
		F(i,1,v) {
			p[i]=read();
		}
		if(h!=v) {
			cout<<"No"<<endl;
			continue;
		}
		bs[0].reset();
		bs[0][500000]=1;
		F(i,1,h) {
			bs[i]=((bs[i-1]<<l[i])|(bs[i-1]>>l[i]));
		}
		if(!bs[h][500000]) {
			cout<<"No"<<endl;
			continue;
		}
		now=500000;
		UF(i,h,1) {
			if(now+l[i]<=1000000&&bs[i-1][now+l[i]]) {
				now+=l[i];
				v1.push_back(l[i]);
			} else {
				now-=l[i];
				v2.push_back(-l[i]);
			}
		}
		bs[0].reset();
		bs[0][500000]=1;
		F(i,1,v) {
			bs[i]=((bs[i-1]<<p[i])|(bs[i-1]>>p[i]));
		}
		if(!bs[v][500000]) {
			cout<<"No"<<endl;
			continue;
		}
		now=500000;
		UF(i,v,1) {
			if(now+p[i]<=1000000&&bs[i-1][now+p[i]]) {
				now+=p[i];
				v3.push_back(p[i]);
			} else {
				now-=p[i];
				v4.push_back(-p[i]);
			}
		}
		cout<<"Yes"<<endl;//cout<<v1.size()<<' '<<v3.size();
		if(v1.size()>=v3.size()) {
			sort(v1.begin(),v1.end());
			sort(v2.begin(),v2.end(),cmp);
			sort(v3.begin(),v3.end(),cmp);
			sort(v4.begin(),v4.end());
			F(i,0,v2.size()-1)v1.push_back(v2[i]);
			F(i,0,v4.size()-1)v3.push_back(v4[i]);
			nx=0,ny=0;
			F(i,0,v1.size()-1) {
				cout<<nx<<' '<<ny<<endl;
				ny+=v3[i];
				cout<<nx<<' '<<ny<<endl;
				nx+=v1[i];
			}
		}else{
			sort(v1.begin(),v1.end(),cmp);
			sort(v2.begin(),v2.end());
			sort(v3.begin(),v3.end());
			sort(v4.begin(),v4.end(),cmp);
			F(i,0,v2.size()-1)v1.push_back(v2[i]);
			F(i,0,v4.size()-1)v3.push_back(v4[i]);
			nx=0,ny=0;
			F(i,0,v1.size()-1) {
				cout<<nx<<' '<<ny<<endl;
				nx+=v1[i];
				cout<<nx<<' '<<ny<<endl;
				ny+=v3[i];
			}
		}

	}
	return 0;
}