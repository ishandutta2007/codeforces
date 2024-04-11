//#include <bits/c++config.h>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define endl '\n'//
//#pragma GCC optimize(3)
using namespace std;
using std::bitset;
using namespace __gnu_pbds;
inline int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10+ch-48),ch=getchar();
	return fu?-x:x;
}
ll t,n,l1,r1,l2,r2,k,res,gt,ans,now;
int main() {
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n>>k;
		l1=read(),r1=read(),l2=read(),r2=read();
		if(l1>l2) {
			swap(l1,l2);
			swap(r1,r2);
		}
		if(r1<=l2) {
			res=l2-r1;
			gt=r2-l1;
			if(k>gt) {
				k-=gt;
				ans+=res+gt;
			} else {
				cout<<res+k<<endl;
				continue;
			}
			if(gt<=res) {
				ans+=2*k;
				cout<<ans<<endl;
				continue;
			} else {
				bool x=0;
				while(--n) {

					if(k>=gt) {
						k-=gt;
						ans+=res+gt;
					} else {
						if(res+k<=2*k) {
							ans+=res+k;
							cout<<ans<<endl;
							x=1;
							break;
						} else {
							ans+=2*k;
							cout<<ans<<endl;
							x=1;
							break;
						}
					}
				}
				if(!x) {
					cout<<ans+2*k<<endl;
				}
			}
		} else if(r1<r2) {
			k-=(r1-l2)*n;
			if(k<=0) {
				cout<<0<<endl;
				continue;
			}
			res=0;
			gt=r2-l1-(r1-l2);
			if(k>gt) {
				k-=gt;
				ans+=res+gt;
			} else {
				cout<<res+k<<endl;
				continue;
			}
			if(gt<=res) {
				ans+=2*k;
				cout<<ans<<endl;
				continue;
			} else {
				bool x=0;
				while(--n) {


					if(k>=gt) {
						k-=gt;
						ans+=res+gt;
					} else {
						if(res+k<=2*k) {
							ans+=res+k;
							cout<<ans<<endl;
							x=1;
							break;
						} else {
							ans+=2*k;
							cout<<ans<<endl;
							x=1;
							break;
						}
					}
				}
				if(!x) {
					cout<<ans+2*k<<endl;
				}
			}
		} else {
			k-=(r2-l2)*n;
			if(k<=0) {
				cout<<0<<endl;
				continue ;
			}
			res=0;
			gt=r1-r2+l2-l1;
			if(k>gt) {
				k-=gt;
				ans+=res+gt;
			} else {
				cout<<res+k<<endl;
				continue;
			}
			if(gt<=res) {
				ans+=2*k;
				cout<<ans<<endl;
				continue;
			} else {
				bool x=0;
				while(--n) {


					if(k>=gt) {
						k-=gt;
						ans+=res+gt;
					} else {
						if(res+k<=2*k) {
							ans+=res+k;
							cout<<ans<<endl;
							x=1;
							break;
						} else {
							ans+=2*k;
							cout<<ans<<endl;
							x=1;
							break;
						}
					}
				}
				if(!x) {
					cout<<ans+2*k<<endl;
				}
			}
		}
	}
	return 0;
}