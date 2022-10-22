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
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
#define endl '\n'//
#pragma GCC optimize(3)
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
int lg[200002],f[400002][22],g[400002][22],n,m,two[22],mmax,l,r,len,t;
map<int,vector<int> >mp;
map<int,bool>vis;
inline int querymax(int l,int r) {
	ri len=r-l+1;
	return max(f[l][lg[len]],f[r-two[lg[len]]+1][lg[len]]);
}
inline int querymin(int l,int r) {
	ri len=r-l+1;
	return min(g[l][lg[len]],g[r-two[lg[len]]+1][lg[len]]);
}
int main() {
	two[0]=1,lg[1]=0;
	F(i,1,20)two[i]=two[i-1]*2;
	F(i,2,200000)lg[i]=lg[i>>1]+1;
	cin>>t;
	while(t--) {
		cin>>n;
		mmax=lg[n];
		mp.clear();vis.clear();
		F(i,1,n)F(j,1,20)f[i][j]=0,g[i][j]=INT_MAX;
		F(i,1,n) {
			f[i][0]=read();
			g[i][0]=f[i][0];
			mp[f[i][0]].push_back(i);
		}
		UF(i,n,1) {
			F(j,1,mmax) {
				f[i][j]=max(f[i][j-1],f[i+two[j-1]][j-1]);
				g[i][j]=min(g[i][j-1],g[i+two[j-1]][j-1]);
			}
		}//cout<<querymin(2,7)<<endl;
		ri num;
		F(i,1,n) {
			num=f[i][0];if(vis[num])continue;
			vis[num]=1;
			if(mp[num].size()>=3) {
				if(f[1][0]>num||f[n][0]>num)continue;
				F(i,1,mp[num].size()-2) {
					ri l=1,r=mp[num][i]-1,mid,tag;
					while(l<r) {
						mid=(l+r)>>1;mid++;
						if(querymax(1,mid)<=num){
							l=mid;
						}else r=mid-1;
					}tag=l;
					l=mp[num][i]+1,r=n;
					while(l<r){
						mid=(l+r)>>1;
						if(querymax(mid,n)<=num){
							r=mid;
						}else l=mid+1;
					}//if(num==9)cout<<querymin(tag+1,l-1)<<endl;
					//if(num==9)cout<<tag+1<<' '<<l-1<<endl;
					if(tag>=mp[num][0]&&l<=mp[num][mp[num].size()-1]&&querymin(tag+1,l-1)==num){
						cout<<"YES\n"<<tag<<' '<<l-tag-1<<' '<<n-l+1<<'\n';
						goto H6_6Q_AK_IOI;
					}
				}

			}
		}
		cout<<"NO\n";
		H6_6Q_AK_IOI:n;
	}

	return 0;
}
/*
9
9 9 10 11 12 13 14 9 8
*/