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
#define endl '\n'
//#pragma GCC optimize(3)
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
int t,n;
vector<pair<int,int> >f;
vector<int>ans;
void fen(int n) {
	f.clear();
	for(ri i=2; i*i<=n; i++) {
		if(n%i==0) {
			f.push_back(make_pair(i,1));
			n/=i;
			while(n%i==0) {
				f[f.size()-1].second++;
				n/=i;
			}
		}
	}
	if(n>1)f.push_back(make_pair(n,1));
}
inline void dfs(int pos,int now) {
	if(pos<0) {
		ans.push_back(now);
		return;
	}
	int temp=now;
	F(i,0,f[pos].second) {

		dfs(pos-1,temp);
		temp*=f[pos].first;
	}
}
inline void go(int pos,int now) {
	if(pos<0) {
		ans.push_back(now);
		return;
	}
	int temp=now;
	F(i,1,f[pos].second) {
		temp*=f[pos].first;
		dfs(pos-1,temp);
	}
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		fen(n);
		ans.clear();
		if(f.size()==2) {
			if(f[0].second==1&&f[1].second==1) {
				cout<<f[0].first<<' '<<f[1].first<<' '<<f[0].first*f[1].first<<endl;
				cout<<1<<endl;
				continue;
			}else if(f[0].second==1){
				UF(i,f.size()-1,0) {
				go(i,1);
				if(i==f.size()-1) {
					ans.pop_back();
					swap(ans[ans.size()-1],ans[ans.size()-2]);
				}
			}ans.push_back(n);
			F(i,0,ans.size()-1)cout<<ans[i]<<' ';
			cout<<endl<<0;
			cout<<endl;
				continue;
			}
		} 
			UF(i,f.size()-1,0) {
				go(i,1);
				if(i==f.size()-1) {
					ans.pop_back();
				}
			}
			ans.push_back(n);
			F(i,0,ans.size()-1)cout<<ans[i]<<' ';
			cout<<endl<<0;
			cout<<endl;
		

	}
	return 0;
}