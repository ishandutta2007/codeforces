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
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
template<class T>
inline T read(T &x) {
	x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	if(fu)x=-x;
}
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
int sum[1000002],n,x,l,r;
int vis[1000002];
int main() {
	cin>>n;
	F(i,2,n) {
		printf("XOR %d %d\n",i-1,i);
		fflush(stdout);
		cin>>x;
		sum[i]=sum[i-1]^x;
		if(vis[sum[i]]) {
			l=vis[sum[i]],r=i;
		}
		vis[sum[i]]=i;
	}
	if(l) {
		printf("OR %d %d\n",l,r);
		fflush(stdout);
		cin>>x;
		x^=sum[l];cout<<"! ";
		F(i,1,n) {
			cout<<(x^sum[i])<<' ';
		}
		cout<<endl;
		return 0;
	} else {
		if(sum[2]==n-1) {
			printf("OR 3 1\n");
			cin>>l;
			printf("OR 3 2\n");
			cin>>x;
			x&=l;
			x^=sum[3];cout<<"! ";
			F(i,1,n) {
				cout<<(x^sum[i])<<' ';
			}
			cout<<endl;
			return 0;
		} else {
			F(i,3,n) {
				if(sum[i]==n-1) {
					printf("OR 2 1\n");
					cin>>l;
					printf("OR 2 %d\n",i);
					cin>>x;
					x&=l;
					x^=sum[2];cout<<"! ";
					F(i,1,n) {
						cout<<(x^sum[i])<<' ';
					}
					cout<<endl;
					return 0;
				}
			}
		}
	}

	return 0;
}